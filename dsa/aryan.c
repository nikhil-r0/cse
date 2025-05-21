#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Employee Node
typedef struct Employee {
    int id;
    char name[50];
    struct Employee* child;
    struct Employee* sibling;
} Employee;

// Function to create a new employee node
Employee* createEmployee(int id, const char* name) {
    Employee* newEmployee = (Employee*)malloc(sizeof(Employee));
    if (!newEmployee) {
        printf("[ERROR] Error :Memory allocation failed.\n");
        return NULL;
    }
    newEmployee->id = id;
    strcpy(newEmployee->name, name);
    newEmployee->child = NULL;
    newEmployee->sibling = NULL;
    return newEmployee;
}

// Add employee under a specific manager
Employee* addEmployee(Employee* root, int managerId, int employeeId, const char* name) {
    if (root == NULL) return NULL;

    if (root->id == managerId) {
        Employee* newEmployee = createEmployee(employeeId, name);
        if (!newEmployee) return root;

        if (root->child == NULL) {
            root->child = newEmployee;
        } else {
            Employee* temp = root->child;
            while (temp->sibling) {
                temp = temp->sibling;
            }
            temp->sibling = newEmployee;
        }
        printf("[SUCCESS] Success: Added employee '%s' (ID: %d) under manager '%s' (ID: %d).\n", name, employeeId, root->name, managerId);
        return root;
    }

    root->child = addEmployee(root->child, managerId, employeeId, name);
    root->sibling = addEmployee(root->sibling, managerId, employeeId, name);
    return root;
}

// Search for an employee by ID
Employee* searchEmployee(Employee* root, int id) {
    if (root == NULL) return NULL;

    if (root->id == id) return root;

    Employee* found = searchEmployee(root->child, id);
    if (found) return found;

    return searchEmployee(root->sibling, id);
}

// Display the hierarchy
void displayHierarchy(Employee* root, int level) {
    if (root == NULL) return;

    for (int i = 0; i < level; i++) printf("  ");
    printf("|-- %s (ID: %d)\n", root->name, root->id);

    displayHierarchy(root->child, level + 1);
    displayHierarchy(root->sibling, level);
}

// Count total employees
int countEmployees(Employee* root) {
    if (root == NULL) return 0;

    return 1 + countEmployees(root->child) + countEmployees(root->sibling);
}

// List subordinates
void listSubordinates(Employee* root) {
    if (root == NULL || root->child == NULL) {
        printf("No subordinates found.\n");
        return;
    }

    Employee* temp = root->child;
    printf("Subordinates of %s (ID: %d):\n", root->name, root->id);
    while (temp) {
        printf("  %s (ID: %d)\n", temp->name, temp->id);
        temp = temp->sibling;
    }
}

// Display reporting path
int displayPathToCEO(Employee* root, int employeeId) {
    if (root == NULL) return 0;

    if (root->id == employeeId) {
        printf("%s (ID: %d)", root->name, root->id);
        return 1;
    }

    if (displayPathToCEO(root->child, employeeId) || displayPathToCEO(root->sibling, employeeId)) {
        printf(" <- %s (ID: %d)", root->name, root->id);
        return 1;
    }
    return 0;
}

// Remove an employee
Employee* removeEmployee(Employee* root, int id, Employee* parent) {
    if (root == NULL) return NULL;

    if (root->id == id) {
        // Handle subordinates
        if (parent) {
            Employee* temp = root->child;
            while (temp && temp->sibling) temp = temp->sibling;
            if (temp) temp->sibling = parent->child;
            parent->child = root->child;
        }

        printf("Removed employee '%s' (ID: %d).\n", root->name, root->id);
        free(root);
        return NULL;
    }

    root->child = removeEmployee(root->child, id, root);
    root->sibling = removeEmployee(root->sibling, id, parent);
    return root;
}

// Edit employee details
void editEmployeeDetails(Employee* root, int id) {
    Employee* emp = searchEmployee(root, id);
    if (!emp) {
        printf("Employee with ID %d not found.\n", id);
        return;
    }

    printf("Editing details for %s (ID: %d).\n", emp->name, emp->id);
    printf("Enter new name: ");
    scanf(" %[^\n]", emp->name);
    printf("Enter new ID: ");
    scanf("%d", &emp->id);
    printf("Employee details updated successfully.\n");
}

// Function to display all employees for selection
void displayAllEmployees(Employee* root) {
    if (root == NULL) return;

    printf("  - %s (ID: %d)\n", root->name, root->id);
    displayAllEmployees(root->child);
    displayAllEmployees(root->sibling);
}


// Free all memory
void freeHierarchy(Employee* root) {
    if (root == NULL) return;

    freeHierarchy(root->child);
    freeHierarchy(root->sibling);
    free(root);
}

// Main menu
int main() {
    Employee* root = createEmployee(1, "CEO");

    int choice, managerId, employeeId;
    char name[50];

    do {
        printf("\nEmployee Management System:\n");
        printf("1. Add Employee\n");
        printf("2. Remove Employee\n");
        printf("3. Search for Employee\n");
        printf("4. Display Organizational Hierarchy\n");
        printf("5. List Subordinates\n");
        printf("6. Display Reporting Path to CEO\n");
        printf("7. Edit Employee Details\n");
        printf("8. Count Total Employees\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nAvailable Managers:\n");
                printf("----------------------------------------\n");
                displayAllEmployees(root);
                printf("----------------------------------------\n");
                printf("Enter Manager ID: ");
                scanf("%d", &managerId);
                printf("Enter Employee ID: ");
                scanf("%d", &employeeId);
                printf("Enter Employee Name: ");
                scanf(" %[^\n]", name);
                if (searchEmployee(root, managerId)) {
                    root = addEmployee(root, managerId, employeeId, name);
                } else {
                    printf("[ERROR] Error: Manager with ID %d not found.\n", managerId);
                }
                break;

            case 2:
                printf("Enter Employee ID to remove: ");
                scanf("%d", &employeeId);
                if (employeeId == 1) {
                    printf("Cannot remove the CEO.\n");
                } else {
                    root = removeEmployee(root, employeeId, NULL);
                }
                break;

            case 3:
                printf("Enter Employee ID to search: ");
                scanf("%d", &employeeId);
                Employee* emp = searchEmployee(root, employeeId);
                if (emp) {
                    printf("Employee found: %s (ID: %d)\n", emp->name, emp->id);
                } else {
                    printf("Employee with ID %d not found.\n", employeeId);
                }
                break;

            case 4:
                printf("\n[Hierarchy] Organizational Hierarchy:\n");
                displayHierarchy(root, 0);
                break;

            case 5:
                printf("Enter Manager ID: ");
                scanf("%d", &managerId);
                Employee* manager = searchEmployee(root, managerId);
                if (manager) {
                    listSubordinates(manager);
                } else {
                    printf("[ERROR] Error: Manager with ID %d not found.\n", managerId);
                }
                break;

            case 6:
                printf("Enter Employee ID to display path: ");
                scanf("%d", &employeeId);
                printf("[PATH] Reporting Path:\n----------------------------------------\n");
                if (!displayPathToCEO(root, employeeId)) {
                    printf("[ERROR] Error: Employee with ID %d not found.\n", employeeId);
                } else {
                    printf("\n");
                }
                break;

            case 7:
                printf("Enter Employee ID to edit: ");
                scanf("%d", &employeeId);
                editEmployeeDetails(root, employeeId);
                break;

            case 8:
                printf("[Subordinates] Total Employees: %d\n", countEmployees(root));
                break;

            case 9:
                printf("Exiting program and freeing memory.\n");
                freeHierarchy(root);
                break;

            default:
                printf("[ERROR] Error: Invalid choice. Please try again.\n");
        }
    } while (choice != 9);

    return 0;
}