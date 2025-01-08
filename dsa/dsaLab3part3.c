#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int value;
    int priority;
} Element;

Element priorityQueue[MAX];
int size = 0;

void enqueue(int value, int priority) {
    if (size == MAX) {
        printf("Queue Overflow\n");
        return;
    }
    Element newElement;
    newElement.value = value;
    newElement.priority = priority;
    int i;
    for (i = size - 1; i >= 0; i--) {
        if (priorityQueue[i].priority > priority) {
            priorityQueue[i + 1] = priorityQueue[i];
        } else {
            break;
        }
    }
    priorityQueue[i + 1] = newElement;
    size++;
    printf("Enqueued %d with priority %d\n", value, priority);
}

int dequeue() {
    if (size == 0) {
        printf("Queue Underflow\n");
        return -1;
    }
    int value = priorityQueue[0].value;
    for (int i = 0; i < size - 1; i++) {
        priorityQueue[i] = priorityQueue[i + 1];
    }
    size--;
    printf("Dequeued %d\n", value);
    return value;
}

void display() {
    if (size == 0) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are:\n");
        for (int i = 0; i < size; i++) {
            printf("%d (priority %d) ", priorityQueue[i].value, priorityQueue[i].priority);
        }
        printf("\n");
    }
}

int main() {
    enqueue(10, 2);
    enqueue(20, 1);
    enqueue(30, 3);
    display();

    dequeue();
    display();

    enqueue(40, 0);
    display();

    dequeue();
    display();

    return 0;
}