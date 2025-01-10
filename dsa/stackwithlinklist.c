#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *next;
};
struct node *top = NULL;
int isempty()
{
    if (top == NULL)
        return 1;
    else
        return 0;
}
void push(int val)
{
    struct node *ins = (struct node *)malloc(sizeof(struct node));
    ins->info = val;
    ins->next = NULL;
    ins->next = top;
    top = ins;
}
int peek()
{
    if (isempty())
        printf("Stack is empty.\n");
    else
        return top->info;
}
int pop()
{
    if (isempty())
        printf("Stack is empty.\n");
    else
    {
        struct node *temp = top;
        int data = top->info;
        top = top->next;
        free(temp);
        return data;
    }
}
int main()
{
    push(1);
    push(12);
    push(15);
    push(20);
    printf("Element at top of the stack:%d\n", peek());
    printf("Popped	element:	%d\n",
           pop());
    printf("Popped	element:	%d\n",
           pop());
    printf("Element at top of the stack:%d\n", peek());
}
