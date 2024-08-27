#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Stack structure
typedef struct Stack {
    Node* top;
} Stack;

// Initialize the stack
void initStack(Stack* s) {
    s->top = NULL;
}

// Push operation
void push(Stack* s, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
}

// Pop operation
int pop(Stack* s) {
    if (s->top == NULL) {
        printf("Stack underflow\n");
        return -1; // Assuming -1 is an error value for empty stack
    }

    Node* temp = s->top;
    int data = temp->data;
    s->top = s->top->next;
    free(temp);

    return data;
}


// Check if the stack is empty
int isEmpty(Stack* s) {
    return s->top == NULL;
}

// Display the stack contents
void display(Stack* s) {
    if (s->top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    Node* current = s->top;
    printf("Stack contents:\n");
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

// Main function with menu
int main() {
    Stack s;
    initStack(&s);
    
    int choice, value;

    do {
        printf("\nStack Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        
        printf("3. Display\n");
        printf("4. Check if Empty\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&s, value);
                break;
            case 2:
                value = pop(&s);
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;
            
            case 3:
                display(&s);
                break;
            case 4:
                if (isEmpty(&s)) {
                    printf("Stack is empty\n");
                } else {
                    printf("Stack is not empty\n");
                }
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a number between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}

