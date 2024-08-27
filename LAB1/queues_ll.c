#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Queue structure
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Initialize the queue
void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// Enqueue operation
void enqueue(Queue* q, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    
    newNode->data = data;
    newNode->next = NULL;
    
    if (q->rear == NULL) {
        // Queue is empty
        q->front = q->rear = newNode;
    } else {
        // Add to the end and update rear
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Dequeue operation
int dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("Queue underflow\n");
        return -1; // Assuming -1 is an error value for empty queue
    }

    Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL; // Queue is now empty
    }
    free(temp);

    return data;
}



// Check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == NULL;
}

// Display the queue contents
void display(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    Node* current = q->front;
    printf("Queue contents:\n");
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

// Main function with menu
int main() {
    Queue q;
    initQueue(&q);
    
    int choice, value;

    do {
        printf("\nQueue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        
        printf("3. Display\n");
        printf("4. Check if Empty\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                value = dequeue(&q);
                if (value != -1) {
                    printf("Dequeued value: %d\n", value);
                }
                break;
            
            case 3:
                display(&q);
                break;
            case 4:
                if (isEmpty(&q)) {
                    printf("Queue is empty\n");
                } else {
                    printf("Queue is not empty\n");
                }
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}

