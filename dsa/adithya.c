#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Seat {
    int seatNumber;
    char customerName[50];
    char foodChoice[100];
    struct Seat* next;
} Seat;


void bookSeat(Seat** head, int seatNumber, char* customerName, int totalSeats);
void cancelBooking(Seat** head, int seatNumber);
void displayBookings(Seat* head);
void chooseFood(Seat* head, int seatNumber);
int isSeatAvailable(Seat* head, int seatNumber);
int checkFull(Seat* head, int totalSeats);
void freeAllSeats(Seat** head);

int main() {
    Seat* head = NULL; 
    int choice, seatNumber, totalSeats = 10; 
    char customerName[50];

    while (1) {
        printf("\nCinema Ticket Booking System:\n");
        printf("1. Book a Seat\n");
        printf("2. Cancel Booking\n");
        printf("3. Display Bookings\n");
        printf("4. Choose Food for a Seat\n");
        printf("5. Check Seat Availability\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            
            if (checkFull(head, totalSeats)) {
                printf("Sorry, all seats are booked.\n");
                continue; 
            }
            printf("Enter seat number to book: ");
            scanf("%d", &seatNumber);
            printf("Enter customer name: ");
            scanf(" %[^\n]", customerName);
            bookSeat(&head, seatNumber, customerName, totalSeats);  
        } else if (choice == 2) {
            printf("Enter seat number to cancel booking: ");
            scanf("%d", &seatNumber);
            cancelBooking(&head, seatNumber);
        } else if (choice == 3) {
            displayBookings(head);
        } else if (choice == 4) {
            printf("Enter seat number to choose food: ");
            scanf("%d", &seatNumber);
            chooseFood(head, seatNumber);
        } else if (choice == 5) {
            printf("Enter seat number to check availability: ");
            scanf("%d", &seatNumber);
            if (isSeatAvailable(head, seatNumber)) {
                printf("Seat %d is available.\n", seatNumber);
            } else {
                printf("Seat %d is already booked.\n", seatNumber);
            }
        } else if (choice == 6) {
            freeAllSeats(&head);
            printf("Exiting the system...\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}


void bookSeat(Seat** head, int seatNumber, char* customerName, int totalSeats) {
    if (!isSeatAvailable(*head, seatNumber)) {
        printf("Seat %d is already booked.\n", seatNumber);
        return;
    }

    Seat* newSeat = (Seat*)malloc(sizeof(Seat));
    if (!newSeat) {
        printf("Memory allocation failed. Cannot book seat.\n");
        return;
    }
    newSeat->seatNumber = seatNumber;
    strcpy(newSeat->customerName, customerName);
    strcpy(newSeat->foodChoice, "No food selected");  
    newSeat->next = NULL;

    
    printf("Food Menu:\n");
    printf("1. Popcorn\n");
    printf("2. Nachos\n");
    printf("3. Soda\n");
    printf("4. Combo (Popcorn + Soda)\n");
    printf("5. No food\n");
    printf("Enter your choice: ");
    int foodChoice;
    scanf("%d", &foodChoice);

    if (foodChoice == 1) {
        strcpy(newSeat->foodChoice, "Popcorn");
    } else if (foodChoice == 2) {
        strcpy(newSeat->foodChoice, "Nachos");
    } else if (foodChoice == 3) {
        strcpy(newSeat->foodChoice, "Soda");
    } else if (foodChoice == 4) {
        strcpy(newSeat->foodChoice, "Combo (Popcorn + Soda)");
    } else if (foodChoice == 5) {
        strcpy(newSeat->foodChoice, "No food");
    } else {
        printf("Invalid choice. No food selected.\n");
    }

    
    if (*head == NULL || (*head)->seatNumber > seatNumber) {
        newSeat->next = *head;
        *head = newSeat;
    } else {
        Seat* current = *head;
        while (current->next != NULL && current->next->seatNumber < seatNumber) {
            current = current->next;
        }
        newSeat->next = current->next;
        current->next = newSeat;
    }
    printf("Seat %d successfully booked for %s.\n", seatNumber, customerName);
}


void cancelBooking(Seat** head, int seatNumber) {
    if (*head == NULL) {
        printf("No bookings available to cancel.\n");
        return;
    }
    Seat* current = *head;
    Seat* previous = NULL;

    while (current != NULL && current->seatNumber != seatNumber) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Seat %d is not booked.\n", seatNumber);
        return;
    }

    if (previous == NULL) {
        *head = current->next;
    } else {
        previous->next = current->next;
    }
    free(current);
    printf("Booking for seat %d has been cancelled.\n", seatNumber);
}


void displayBookings(Seat* head) {
    if (head == NULL) {
        printf("No bookings available.\n");
        return;
    }
    printf("Current Bookings:\n");
    while (head != NULL) {
        printf("Seat %d - %s | Food: %s\n", head->seatNumber, head->customerName, head->foodChoice);
        head = head->next;
    }
}


void chooseFood(Seat* head, int seatNumber) {
    while (head != NULL && head->seatNumber != seatNumber) {
        head = head->next;
    }

    if (head == NULL) {
        printf("Seat %d is not booked. Cannot choose food.\n", seatNumber);
        return;
    }

    printf("Food Menu:\n");
    printf("1. Popcorn\n");
    printf("2. Nachos\n");
    printf("3. Soda\n");
    printf("4. Combo (Popcorn + Soda)\n");
    printf("5. No food\n");
    printf("Enter your choice: ");
    int foodChoice;
    scanf("%d", &foodChoice);

    if (foodChoice == 1) {
        strcpy(head->foodChoice, "Popcorn");
    } else if (foodChoice == 2) {
        strcpy(head->foodChoice, "Nachos");
    } else if (foodChoice == 3) {
        strcpy(head->foodChoice, "Soda");
    } else if (foodChoice == 4) {
        strcpy(head->foodChoice, "Combo (Popcorn + Soda)");
    } else if (foodChoice == 5) {
        strcpy(head->foodChoice, "No food");
    } else {
        printf("Invalid choice. No food selected.\n");
        return;
    }
    printf("Food choice updated for seat %d.\n", seatNumber);
}


int isSeatAvailable(Seat* head, int seatNumber) {
    while (head != NULL) {
        if (head->seatNumber == seatNumber) {
            return 0; 
        }
        head = head->next;
    }
    return 1; 
}


int checkFull(Seat* head, int totalSeats) {
    int bookedSeats = 0;
    while (head != NULL) {
        bookedSeats++;
        head = head->next;
    }
    return bookedSeats >= totalSeats;
}


void freeAllSeats(Seat** head) {
    while (*head != NULL) {
        Seat* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    printf("All seat bookings have been cleared.\n");
}
