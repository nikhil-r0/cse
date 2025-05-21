#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a crew member (Tree Node)
typedef struct CrewMember {
    char name[50];
    struct CrewMember *firstChild;
    struct CrewMember *nextSibling;
} CrewMember;

// Create a new crew member
CrewMember* createCrewMember(char name[]) {
    CrewMember* newMember = (CrewMember*)malloc(sizeof(CrewMember));
    if (!newMember) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strcpy(newMember->name, name);
    newMember->firstChild = NULL;
    newMember->nextSibling = NULL;
    return newMember;
}

// Add a crew member under a specific parent
void addCrewMember(CrewMember *parent, char name[]) {
    CrewMember *newMember = createCrewMember(name);
    if (!parent->firstChild) {
        parent->firstChild = newMember; // First child of the parent
    } else {
        // Add as a sibling of the existing children
        CrewMember *sibling = parent->firstChild;
        while (sibling->nextSibling) {
            sibling = sibling->nextSibling;
        }
        sibling->nextSibling = newMember;
    }
    printf("Crew member '%s' added under '%s'.\n", name, parent->name);
}

// Display the crew hierarchy (Tree Traversal)
void displayHierarchy(CrewMember *root, int level) {
    if (!root) return;
    for (int i = 0; i < level; i++) printf("  "); // Indentation for hierarchy
    printf("- %s\n", root->name);
    displayHierarchy(root->firstChild, level + 1); // Recurse on children
    displayHierarchy(root->nextSibling, level);   // Recurse on siblings
}

// Search for a crew member by name
CrewMember* searchCrewMember(CrewMember *root, char name[]) {
    if (!root) return NULL;
    if (strcmp(root->name, name) == 0) return root;

    CrewMember *found = searchCrewMember(root->firstChild, name);
    if (found) return found;

    return searchCrewMember(root->nextSibling, name);
}

// Free the memory for a subtree
void freeSubtree(CrewMember *root) {
    if (!root) return;
    freeSubtree(root->firstChild); // Free all children
    freeSubtree(root->nextSibling); // Free all siblings
    printf("Crew member '%s' removed.\n", root->name);
    free(root);
}

// Remove a crew member and their subordinates
CrewMember* removeCrewMember(CrewMember *root, char name[]) {
    if (!root) return NULL;

    // Check if the first child matches
    if (root->firstChild && strcmp(root->firstChild->name, name) == 0) {
        CrewMember *toRemove = root->firstChild;
        root->firstChild = root->firstChild->nextSibling; // Update first child pointer
        freeSubtree(toRemove);
        return root;
    }

    // Check for siblings
    CrewMember *current = root->firstChild;
    while (current && current->nextSibling) {
        if (strcmp(current->nextSibling->name, name) == 0) {
            CrewMember *toRemove = current->nextSibling;
            current->nextSibling = toRemove->nextSibling; // Update sibling pointer
            freeSubtree(toRemove);
            return root;
        }
        current = current->nextSibling;
    }

    // Recurse on children
    root->firstChild = removeCrewMember(root->firstChild, name);
    return root;
}

int main() {
    // Initialize the root of the tree (Captain)
    CrewMember *crewRoot = createCrewMember("Monkey D. Luffy");

    int choice;
    char name[50], parentName[50];
    CrewMember *parent;

    do {
        printf("\nMenu:\n");
        printf("1. Add Crew Member\n");
        printf("2. Display Crew Hierarchy\n");
        printf("3. Search Crew Member\n");
        printf("4. Remove Crew Member\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume newline left by scanf

        switch (choice) {
            case 1:
                printf("Enter the name of the new crew member: ");
                fgets(name, 50, stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove newline
                printf("Enter the name of the parent crew member: ");
                fgets(parentName, 50, stdin);
                parentName[strcspn(parentName, "\n")] = '\0'; // Remove newline

                parent = searchCrewMember(crewRoot, parentName);
                if (parent) {
                    addCrewMember(parent, name);
                } else {
                    printf("Parent crew member '%s' not found.\n", parentName);
                }
                break;

            case 2:
                printf("Crew Hierarchy:\n");
                displayHierarchy(crewRoot, 0);
                break;

            case 3:
                printf("Enter the name of the crew member to search: ");
                fgets(name, 50, stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove newline

                parent = searchCrewMember(crewRoot, name);
                if (parent) {
                    printf("Crew member '%s' found!\n", name);
                } else {
                    printf("Crew member '%s' not found.\n", name);
                }
                break;

            case 4:
                printf("Enter the name of the crew member to remove: ");
                fgets(name, 50, stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove newline

                if (strcmp(crewRoot->name, name) == 0) {
                    printf("Cannot remove the captain!\n");
                } else {
                    crewRoot = removeCrewMember(crewRoot, name);
                }
                break;

            case 5:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);

    freeSubtree(crewRoot); // Free all allocated memory
    return 0;
}