#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct node
{
    int info;
    struct node *next;
};

// Global pointer to the head of the list
struct node *list = NULL;

// Unified function to insert a node at a specific position or after a given node
void insertNode(int pos, struct node *pred, int val)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = val;
    newNode->next = NULL;

    if (pos == 0)  // Insert at the beginning
    {
        newNode->next = list;
        list = newNode;
    }
    else if (pred != NULL)  // Insert after the given node
    {
        newNode->next = pred->next;
        pred->next = newNode;
    }
    else  // Insert at the specified position
    {
        struct node *temp = list;
        int count = 0;
        while (temp != NULL && count < pos - 1)
        {
            temp = temp->next;
            count++;
        }
        if (temp == NULL)  // Position is out of bounds
        {
            printf("Position out of bounds.\n");
            free(newNode);
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Function to merge a node
void mergenode(struct node *pred)
{
    struct node *temp = pred->next;
    pred->info += temp->info;
    pred->next = temp->next;
    free(temp);
}

// Function to delete a node
void deletenode(struct node *del)
{
    if (del == list)
    {
        list = del->next;
    }
    else
    {
        struct node *pred = list;
        while (pred->next != del)
        {
            pred = pred->next;
        }
        pred->next = del->next;
    }
    free(del);
}

// Function to display the linked list
void display()
{
    struct node *temp = list;
    while (temp != NULL)
    {
        printf("%d\t", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    // Insert nodes
    insertNode(0, NULL, 7);   // Insert 7 at the beginning
    insertNode(0, list, 10);  // Insert 10 after the first node
    insertNode(0, list, 16);  // Insert 16 after the second node

    printf("Original list: ");
    display();  // Display the original list

    // Delete the node after the head (which is '10')
    deletenode(list->next->next);
    
    printf("List after deletion: ");
    display();  // Display the list after deletion

    // Insert 12 at position 2
    insertNode(2, NULL, 12);
    insertNode(6, NULL, 13);
    printf("List after inserting 12 at position 2: ");
    display();  // Display the list after insertion at position 2

    mergenode(list->next);  // Merge the node after the head
    printf("List after merging the node after the head with the head:");
    display();  // Display the list after merging       

    return 0;
}
