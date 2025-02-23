#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;

int isempty() {
    return front == NULL;
}

void enqueue(int val) {
    struct node* ins = (struct node*) malloc(sizeof(struct node));
    ins->info = val;
    ins->next = NULL;
    if (rear != NULL) {
        rear->next = ins;
    } else {
        front = ins;
    }
    rear = ins;
}

int peek() {
    if (isempty()) {
        printf("Queue is empty.\n");
        return -1; // Return -1 to indicate the queue is empty
    } else {
        return front->info;
    }
}

int dequeue() {
    if (isempty()) {
        printf("Queue is empty.\n");
        return -1; // Return -1 to indicate the queue is empty
    } else {
        struct node *temp = front;
        int data = front->info;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        free(temp);
        return data;
    }
}

int main() {
    enqueue(1);
    enqueue(12);
    enqueue(15);
    enqueue(20);

    printf("Element at front of the queue: %d\n", peek());
    printf("Dequeued element: %d\n", dequeue());
    printf("Dequeued element: %d\n", dequeue());
    printf("Element at front of the queue: %d\n", peek());

    return 0;
}