#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MALLOC(ptr, size) ((ptr) = malloc(size)) // Memory allocation macro

typedef struct polyNode *polyPointer;

typedef struct polyNode {
    int coef;             // Coefficient of the term
    int expon;            // Exponent of the term
    char variable;        // Variable of the term (e.g., x, y, z)
    polyPointer link;     // Pointer to the next term
} polyNode;

// Function prototypes
polyPointer padd(polyPointer a, polyPointer b);
void attach(int coefficient, int exponent, char variable, polyPointer *ptr);
int COMPARE(int x, int y);
void printPoly(polyPointer head);
polyPointer createPoly();

int main() {
    // Create two sample polynomials
    printf("Creating Polynomial A:\n");
    polyPointer a = createPoly();

    printf("\nCreating Polynomial B:\n");
    polyPointer b = createPoly();

    // Add the polynomials
    printf("\nAdding the two polynomials...\n");
    polyPointer result = padd(a, b);

    // Print the polynomials
    printf("\nPolynomial A: ");
    printPoly(a);

    printf("Polynomial B: ");
    printPoly(b);

    printf("Resultant Polynomial: ");
    printPoly(result);

    return 0;
}

polyPointer padd(polyPointer a, polyPointer b) {
    polyPointer c, rear, temp;
    int sum;

    MALLOC(rear, sizeof(*rear));  // Create a dummy node
    rear->link = NULL;
    c = rear;

    while (a && b) {
        if (a->variable == b->variable) { // Check if variables match
            switch (COMPARE(a->expon, b->expon)) {
                case -1: // Exponent of b is greater
                    attach(b->coef, b->expon, b->variable, &rear);
                    b = b->link;
                    break;
                case 0: // Exponents are equal
                    sum = a->coef + b->coef;
                    if (sum != 0)
                        attach(sum, a->expon, a->variable, &rear);
                    a = a->link;
                    b = b->link;
                    break;
                case 1: // Exponent of a is greater
                    attach(a->coef, a->expon, a->variable, &rear);
                    a = a->link;
                    break;
            }
        } else { // Variables are different
            attach(a->coef, a->expon, a->variable, &rear);
            a = a->link;
        }
    }

    // Attach remaining terms of a
    for (; a; a = a->link)
        attach(a->coef, a->expon, a->variable, &rear);

    // Attach remaining terms of b
    for (; b; b = b->link)
        attach(b->coef, b->expon, b->variable, &rear);

    rear->link = NULL; // End the result list

    temp = c;
    c = c->link; // Skip dummy node
    free(temp);

    return c;
}

void attach(int coefficient, int exponent, char variable, polyPointer *ptr) {
    polyPointer temp;
    MALLOC(temp, sizeof(*temp));  // Allocate memory for a new node
    temp->coef = coefficient;
    temp->expon = exponent;
    temp->variable = variable;
    temp->link = NULL;
    (*ptr)->link = temp;  // Link new node to the list
    *ptr = temp;          // Move the pointer to the new node
}

int COMPARE(int x, int y) {
    if (x < y) return -1;
    if (x == y) return 0;
    return 1;
}

void printPoly(polyPointer head) {
    if (!head) {
        printf("0\n");
        return;
    }
    polyPointer temp = head;
    while (temp != NULL) {
        printf("%d%c^%d", temp->coef, temp->variable, temp->expon);
        if (temp->link != NULL) {
            printf(" + ");
        }
        temp = temp->link;
    }
    printf("\n");
}

polyPointer createPoly() {
    polyPointer head = NULL, rear = NULL;
    int n, coef, expon;
    char var;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter coefficient, exponent, and variable (coef expon var): ");
        scanf("%d %d %c", &coef, &expon, &var);

        if (!head) {
            MALLOC(head, sizeof(*head));
            head->coef = coef;
            head->expon = expon;
            head->variable = var;
            head->link = NULL;
            rear = head;
        } else {
            attach(coef, expon, var, &rear);
        }
    }
    return head;
}