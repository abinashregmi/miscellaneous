#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

struct node *top = NULL;

int isempty() {
    return top == NULL;
}

void push(int val) {
    struct node *ins = (struct node*) malloc(sizeof(struct node));
    ins->info = val;
    ins->next = top;
    top = ins;
}

int peek() {
    if (isempty()) {
        printf("Stack is empty.\n");
        return -1; // Return -1 to indicate the stack is empty
    } else {
        return top->info;
    }
}

int pop() {
    if (isempty()) {
        printf("Stack is empty.\n");
        return -1; // Return -1 to indicate the stack is empty
    } else {
        struct node *temp = top;
        int data = top->info;
        top = top->next;
        free(temp);
        return data;
    }
}

int main() {
    push(1);
    push(12);
    push(15);
    push(20);

    printf("Element at top of the stack: %d\n", peek());

    printf("Popped element: %d\n", pop());
    printf("Popped element: %d\n", pop());

    printf("Element at top of the stack: %d\n", peek());

    return 0;
}