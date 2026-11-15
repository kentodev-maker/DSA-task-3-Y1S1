#include <stdio.h>

#define SIZE 5

int deque[SIZE];
int front = -1;
int rear = -1;

int is_full(void) {
    return (front == 0 && rear == SIZE - 1) || (front == rear + 1);
}

int is_empty(void) {
    return front == -1;
}

void insert_front(int value) {
    if (is_full()) {
        printf("Deque is full.\n");
        return;
    }
    if (is_empty()) {
        front = rear = 0;
    } else if (front == 0) {
        front = SIZE - 1;
    } else {
        front--;
    }
    deque[front] = value;
}

void insert_rear(int value) {
    if (is_full()) {
        printf("Deque is full.\n");
        return;
    }
    if (is_empty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }
    deque[rear] = value;
}

void delete_front(void) {
    if (is_empty()) {
        printf("Deque is empty.\n");
        return;
    }
    printf("Removed %d.\n", deque[front]);
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

void delete_rear(void) {
    if (is_empty()) {
        printf("Deque is empty.\n");
        return;
    }
    printf("Removed %d.\n", deque[rear]);
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = SIZE - 1;
    } else {
        rear--;
    }
}

void display(void) {
    int index;
    if (is_empty()) {
        printf("Deque is empty.\n");
        return;
    }
    printf("Deque: ");
    index = front;
    while (1) {
        printf("%d ", deque[index]);
        if (index == rear) break;
        index = (index + 1) % SIZE;
    }
    printf("\n");
}

int main(void) {
    int choice;
    int value;

    do {
        printf("\n1. Insert front\n2. Insert rear\n3. Delete front\n4. Delete rear\n5. Display\n6. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: "); scanf("%d", &value); insert_front(value); break;
            case 2:
                printf("Enter value: "); scanf("%d", &value); insert_rear(value); break;
            case 3: delete_front(); break;
            case 4: delete_rear(); break;
            case 5: display(); break;
            case 6: break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 6);
    return 0;
}
