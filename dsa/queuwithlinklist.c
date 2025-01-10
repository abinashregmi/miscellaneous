#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *next;
};
struct node *front = NULL, *rear = NULL;
int isempty()
{
    if (front == NULL)
        return 1;
    else
        return 0;
}
void enqueue(int val)
{
    struct node *ins = (struct node *)malloc(sizeof(struct node));
    ins->info = val;
    ins->next = NULL;
    if (rear != NULL)
        rear->next = ins;
    else
        front = ins;
    rear = ins;
}
int peek()
{
    if (isempty())
        printf("Queue empty.\n");
    else
        return front->info;
}
int dequeue()
{
    if (isempty())
        printf("Queue is empty.\n");
    else
    {
        struct node *temp = front;
        int data = front->info;
        front = front->next;
        if (front == NULL)
            rear = NULL;
        free(temp);
        return data;
    }
}
int main()
{
    enqueue(1);
    enqueue(12);
    enqueue(15);
    enqueue(20);
    printf("Element at top of the stack: %d\n", peek());
    printf("Dequeued element: %d\n", dequeue());
    printf("Popped element: %d\n", dequeue());
    printf("Dequeued at top of the front: %d\n", peek());
}
