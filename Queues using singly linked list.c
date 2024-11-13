#include <stdio.h>
#include <stdlib.h>
// Structure to define a node
struct Node {
    int data;
    struct Node* next;
};
// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
// Function to check if the queue is empty
int isEmpty(struct Node* front) {
    return front == NULL;
}
// Function to enqueue (add) an element to the queue
void enqueue(struct Node** front, struct Node** rear, int data) {
    struct Node* newNode = createNode(data);
    if (!newNode) return;

    if (*rear == NULL) {
        // Queue is empty
        *front = *rear = newNode;
        return;
    }

    // Add new node at the end of the queue and update rear
    (*rear)->next = newNode;
    *rear = newNode;
    printf("%d enqueued to the queue\n", data);
}
// Function to dequeue (remove) an element from the queue
int dequeue(struct Node** front, struct Node** rear) {
    if (isEmpty(*front)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    }
    struct Node* temp = *front;
    int data = temp->data;
    *front = (*front)->next;
    // If the queue becomes empty, set rear to NULL
    if (*front == NULL) {
        *rear = NULL;
    }
    free(temp);
    return data;
}
// Function to display the queue
void display(struct Node* front) {
    if (isEmpty(front)) {
        printf("Queue is empty!\n");
        return;
    }
    struct Node* temp = front;
    printf("Queue: ");
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
// Main function with menu-driven program
int main() {
    struct Node* front = NULL;
    struct Node* rear = NULL;
    int choice, value;
    while (1) {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&front, &rear, value);
                break;
            case 2:
                value = dequeue(&front, &rear);
                if (value != -1)
                    printf("Dequeued value: %d\n", value);
                break;
            case 3:
                display(front);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
