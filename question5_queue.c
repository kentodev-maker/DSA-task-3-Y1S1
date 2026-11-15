#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = 0;
int rear = -1;

void enqueue(int value) {
    if (rear == SIZE - 1) {
        printf("Queue is full.\n");
        return;
    }
    queue[++rear] = value;
}

void dequeue(void) {
    if (front > rear) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Removed %d.\n", queue[front++]);
}

void display(void) {
    int index;
    if (front > rear) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    for (index = front; index <= rear; index++) {
        printf("%d ", queue[index]);
    }
    printf("\n");
}

int main(void) {
    int choice;
    int value;

    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);
    return 0;
}
