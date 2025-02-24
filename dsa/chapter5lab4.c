#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

void insertAtBeginning(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
}

void insertAtEnd(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;    
    } else {
        struct node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

void insertAtPosition(int value, int pos) {
    if (pos < 1) {
        printf("Invalid position!\n");
        return;
    }
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    if (pos == 1) {
        insertAtBeginning(value);
        return;
    }
    struct node* temp = head;
    for (int i = 1; i < pos - 1; i++) {
        if (temp->next == head) {
            printf("Position out of range!\n");
            return;
        }
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    insertAtBeginning(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtPosition(15, 2);
    display(); // Output: 10 15 20 30

    return 0;
}