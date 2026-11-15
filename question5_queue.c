#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = 0;
int rear = -1;

int is_empty(void) {
    return rear < front;
}

int is_full(void) {
    return rear == SIZE - 1;
}

void enqueue(int value) {
    if (is_full()) {
        printf("Queue is full.\n");
        return;
    }
    queue[++rear] = value;
    printf("%d inserted.\n", value);
}

void dequeue(void) {
    if (is_empty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("%d removed.\n", queue[front++]);
}

void display(void) {
    int index;

    if (is_empty()) {
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
