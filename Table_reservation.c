#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TABLES 20
#define MAX_NAME_LEN 50
#define MAX_TIME_LEN 10

typedef struct {
    int id;
    int capacity;
    int isOccupied;
    char reservedBy[MAX_NAME_LEN];
    char reservationTime[MAX_TIME_LEN];
} Table;

typedef struct {
    Table tables[MAX_TABLES];
    int tableCount;
} Restaurant;

void initializeRestaurant(Restaurant *restaurant, int tableCount) {
    restaurant->tableCount = tableCount;
    int i;
    for (i = 0; i < tableCount; i++) {
        restaurant->tables[i].id = i + 1;
        restaurant->tables[i].capacity = (i % 4) + 2; // Tables with capacity between 2 and 6
        restaurant->tables[i].isOccupied = 0;
        strcpy(restaurant->tables[i].reservedBy, "");
        strcpy(restaurant->tables[i].reservationTime, "");
    }
}

void viewTables(Restaurant *restaurant) {
    printf("Table Status:\n");
    int i;
    for (i = 0; i < restaurant->tableCount; i++) {
        printf("Table %d (Capacity: %d): %s\n", 
               restaurant->tables[i].id, 
               restaurant->tables[i].capacity,
               restaurant->tables[i].isOccupied ? "Occupied" : "Available");
    }
}

void reserveTable(Restaurant *restaurant, const char *name, int guests, const char *time) {
    int found = 0;
    int i;
    for (i = 0; i < restaurant->tableCount; i++) {
        if (!restaurant->tables[i].isOccupied && restaurant->tables[i].capacity >= guests) {
            restaurant->tables[i].isOccupied = 1;
            strcpy(restaurant->tables[i].reservedBy, name);
            strcpy(restaurant->tables[i].reservationTime, time);
            printf("Table %d reserved for %s at %s\n", restaurant->tables[i].id, name, time);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("No available table for %d guests at %s.\n", guests, time);
    }
}

void cancelReservation(Restaurant *restaurant, int tableId) {
    if (tableId > 0 && tableId <= restaurant->tableCount && restaurant->tables[tableId - 1].isOccupied) {
        restaurant->tables[tableId - 1].isOccupied = 0;
        strcpy(restaurant->tables[tableId - 1].reservedBy, "");
        strcpy(restaurant->tables[tableId - 1].reservationTime, "");
        printf("Reservation for Table %d has been canceled.\n", tableId);
    } else {
        printf("Invalid table ID or table is not reserved.\n");
    }
}

void viewReservations(Restaurant *restaurant) {
    printf("Current Reservations:\n");
    int hasReservations = 0;
    int i;
    for (i = 0; i < restaurant->tableCount; i++) {
        if (restaurant->tables[i].isOccupied) {
            printf("Table %d (Capacity: %d) reserved by %s at %s\n", 
                   restaurant->tables[i].id, 
                   restaurant->tables[i].capacity, 
                   restaurant->tables[i].reservedBy, 
                   restaurant->tables[i].reservationTime);
            hasReservations = 1;
        }
    }
    if (!hasReservations) {
        printf("No active reservations.\n");
    }
}

int main() {
    Restaurant restaurant;
    initializeRestaurant(&restaurant, MAX_TABLES);

    int choice;
    char name[MAX_NAME_LEN];
    int guests;
    char time[MAX_TIME_LEN];
    int tableId;

    while (1) {
        printf("\n--- Restaurant Reservation System Menu ---\n");
        printf("1. View Table Status\n");
        printf("2. Reserve a Table\n");
        printf("3. Cancel Reservation\n");
        printf("4. View Current Reservations\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                viewTables(&restaurant);
                break;
            case 2:
                printf("Enter your name: ");
                scanf(" %[^\n]%*c", name);
                printf("Enter number of guests: ");
                scanf("%d", &guests);
                printf("Enter reservation time (HH:MM): ");
                scanf(" %[^\n]%*c", time);
                reserveTable(&restaurant, name, guests, time);
                break;
            case 3:
                printf("Enter table ID to cancel reservation: ");
                scanf("%d", &tableId);
                cancelReservation(&restaurant, tableId);
                break;
            case 4:
                viewReservations(&restaurant);
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
