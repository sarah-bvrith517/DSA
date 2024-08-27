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
void printStack(Stack* s) {
    Node* current = s->top;
    printf("Stack contents:\n");
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}
void insertAtBeginning(Stack* s, int data) {
    push(s, data);
}
void insertAtEnd(Stack* s, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    
    newNode->data = data;
    newNode->next = NULL;
    
    if (s->top == NULL) {
        s->top = newNode;
        return;
    }
    
    Node* current = s->top;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}
void insertAtMiddle(Stack* s, int data, int position) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    
    newNode->data = data;
    if (position == 0) {
        newNode->next = s->top;
        s->top = newNode;
        return;
    }

    Node* current = s->top;
    int count = 0;
    while (current != NULL && count < position - 1) {
        current = current->next;
        count++;
    }

    if (current == NULL) {
        printf("Position out of range\n");
        free(newNode);
        return;
    }
    
    newNode->next = current->next;
    current->next = newNode;
}
void deleteAtBeginning(Stack* s) {
    if (s->top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    
    Node* temp = s->top;
    s->top = s->top->next;
    free(temp);
}
void deleteAtEnd(Stack* s) {
    if (s->top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    
    if (s->top->next == NULL) {
        free(s->top);
        s->top = NULL;
        return;
    }
    
    Node* current = s->top;
    while (current->next->next != NULL) {
        current = current->next;
    }
    
    free(current->next);
    current->next = NULL;
}
void deleteAtMiddle(Stack* s, int position) {
    if (s->top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    if (position == 0) {
        deleteAtBeginning(s);
        return;
    }

    Node* current = s->top;
    Node* previous = NULL;
    int count = 0;
    while (current != NULL && count < position) {
        previous = current;
        current = current->next;
        count++;
    }

    if (current == NULL) {
        printf("Position out of range\n");
        return;
    }
    
    previous->next = current->next;
    free(current);
}
int main() {
    Stack s;
    initStack(&s);
    
    int choice, value, position;

    do {
        printf("\nStack Menu:\n");
        printf("1. Push\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Middle\n");
        printf("5. Delete at Beginning\n");
        printf("6. Delete at End\n");
        printf("7. Delete at Middle\n");
        printf("8. Print Stack\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&s, value);
                break;
            case 2:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insertAtBeginning(&s, value);
                break;
            case 3:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(&s, value);
                break;
            case 4:
                printf("Enter value to insert and position: ");
                scanf("%d %d", &value, &position);
                insertAtMiddle(&s, value, position);
                break;
            case 5:
                deleteAtBeginning(&s);
                break;
            case 6:
                deleteAtEnd(&s);
                break;
            case 7:
                printf("Enter position to delete from middle: ");
                scanf("%d", &position);
                deleteAtMiddle(&s, position);
                break;
            case 8:
                printStack(&s);
                break;
            case 9:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 9.\n");
        }
    } while (choice != 9);

    return 0;
}

