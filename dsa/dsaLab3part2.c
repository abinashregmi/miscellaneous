#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if ((front == 0 && rear == MAX - 1) || (rear == (front - 1) % (MAX - 1))) {
        printf("Queue Overflow\n");
    } else {
        if (front == -1) {
            front = rear = 0;
        } else if (rear == MAX - 1 && front != 0) {
            rear = 0;
        } else {
            rear++;
        }
        queue[rear] = value;
        printf("Enqueued %d\n", value);
    }
}

int dequeue() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return -1;
    }
    int value = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
    printf("Dequeued %d\n", value);
    return value;
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are:\n");
        if (rear >= front) {
            for (int i = front; i <= rear; i++) {
                printf("%d ", queue[i]);
            }
        } else {
            for (int i = front; i < MAX; i++) {
                printf("%d ", queue[i]);
            }
            for (int i = 0; i <= rear; i++) {
                printf("%d ", queue[i]);
            }
        }
        printf("\n");
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    display();

    dequeue();
    display();

    enqueue(60);
    display();

    dequeue();
    display();

    return 0;
}