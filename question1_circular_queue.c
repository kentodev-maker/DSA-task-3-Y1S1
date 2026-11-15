#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

int is_full(void) {
    return front == (rear + 1) % SIZE;
}

int is_empty(void) {
    return front == -1;
}

void enqueue(int value) {
    if (is_full()) {
        printf("Queue is full.\n");
        return;
    }

    if (is_empty()) {
        front = 0;
    }
    rear = (rear + 1) % SIZE;
    queue[rear] = value;
    printf("%d inserted.\n", value);
}

void dequeue(void) {
    int value;

    if (is_empty()) {
        printf("Queue is empty.\n");
        return;
    }

    value = queue[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
    printf("%d removed.\n", value);
}

void display(void) {
    int index;

    if (is_empty()) {
        printf("Queue is empty.\n");
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
                printf("Program ended.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}
