#include <stdio.h>
#include <stdlib.h>

// Define a node for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to push an element onto the stack
void push(struct Node** top, int value) {
    // Allocate memory for a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    // Check if memory was successfully allocated
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }

    // Assign the value to the new node and adjust pointers
    newNode->data = value;
    newNode->next = *top;
    
    // Set the new node as the top of the stack
    *top = newNode;
    printf("%d pushed onto stack\n", value);
}

// Function to pop an element from the stack
int pop(struct Node** top) {
    // Check if the stack is empty
    if (*top == NULL) {
        printf("Stack underflow\n");
        return -1;
    }

    // Get the top element
    struct Node* temp = *top;
    int poppedValue = temp->data;
    
    // Move the top pointer to the next node and free memory
    *top = (*top)->next;
    free(temp);

    return poppedValue;
}

// Function to display the elements of the stack
void display(struct Node* top) {
    // Check if the stack is empty
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    // Traverse and display the stack
    printf("Stack elements:\n");
    while (top != NULL) {
        printf("%d\n", top->data);
        top = top->next;
    }
}

// Function to get the top element of the stack
int peek(struct Node* top) {
    // Check if the stack is empty
    if (top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }

    // Return the top element
    return top->data;
}

int main() {
    struct Node* stack = NULL;
    int choice, value;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                value = pop(&stack);
                if (value != -1)
                    printf("Popped: %d\n", value);
                break;
            case 3:
                value = peek(stack);
                if (value != -1)
                    printf("Top element is %d\n", value);
                break;
            case 4:
                display(stack);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
