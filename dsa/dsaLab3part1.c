#include <stdio.h>
#include <stdlib.h>

int *queue;
int front = -1, rear = -1, maxSize;

void enqueue(int value) {
    if (rear == maxSize - 1) {
        printf("Queue Overflow\n");
    } else {
        if (front == -1) front = 0;
        queue[++rear] = value;
        printf("Enqueued %d\n", value);
    }
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return -1;
    } else {
        int value = queue[front++];
        printf("Dequeued %d\n", value);
        return value;
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are:\n");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int value;

    printf("Enter the maximum size of the queue: ");
    scanf("%d", &maxSize);

    queue = (int *)malloc(maxSize * sizeof(int));

    // Demonstrate enqueue operations
    printf("Enter values to enqueue (enter -1 to stop):\n");
    while (1) {
        scanf("%d", &value);
        if (value == -1) break;
        enqueue(value);
    }

    display();

    // Demonstrate dequeue operations
    printf("Dequeueing elements (enter -1 to stop):\n");
    while (1) {
        printf("Enter 1 to dequeue, -1 to stop: ");
        scanf("%d", &value);
        if (value == -1) break;
        if (value == 1) dequeue();
        display();
    }

    free(queue);
    return 0;
}