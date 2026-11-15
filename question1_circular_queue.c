/*
    Disadvantages of a linear queue:
    - Deleted positions cannot be reused when rear reaches the last index.
    - This can cause false overflow even when there are free positions at the front.
    - Shifting elements to reclaim space adds unnecessary time complexity.
    - A circular queue solves this by wrapping rear and front around the array.
*/

#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue(int value) {
    if ((rear + 1) % SIZE == front) {
        printf("Circular queue is full.\n");
        return;
    }

    if (front == -1) {
        front = 0;
    }
    rear = (rear + 1) % SIZE;
    queue[rear] = value;
    printf("Inserted %d.\n", value);
}

void dequeue(void) {
    int value;

    if (front == -1) {
        printf("Circular queue is empty.\n");
        return;
    }

    value = queue[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
    printf("Removed %d.\n", value);
}

void display(void) {
    int index;

    if (front == -1) {
        printf("Circular queue is empty.\n");
        return;
    }

    printf("Queue: ");
    index = front;
    while (1) {
        printf("%d ", queue[index]);
        if (index == rear) {
            break;
        }
        index = (index + 1) % SIZE;
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
