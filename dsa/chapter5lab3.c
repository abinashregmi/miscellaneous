#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *left, *right;
};

struct node* list = NULL;

void insertnode(struct node* pred, int val) {
    struct node* ins = (struct node*) malloc(sizeof(struct node));
    ins->info = val;
    ins->left = NULL;
    ins->right = NULL;

    if (pred == NULL) {
        // Insert at the beginning
        ins->right = list;
        list = ins;
        if (ins->right != NULL) {
            ins->right->left = ins;
        }
    } else {
        // Insert after pred
        ins->right = pred->right;
        pred->right = ins;
        if (ins->right != NULL) {
            ins->right->left = ins;
        }
        ins->left = pred;
    }
}

void deletenode(struct node* del) {
    if (del == list) {
        // Delete the first node
        list = del->right;
        if (list != NULL) {
            list->left = NULL;
        }
    } else {
        // Delete a node other than the first
        struct node *pred = del->left;
        struct node *succ = del->right;
        pred->right = succ;
        if (succ != NULL) {
            succ->left = pred;
        }
    }
    free(del);
}

void display() {
    struct node* temp = list;
    while (temp != NULL) {
        printf("%d\t", temp->info);
        temp = temp->right;
    }
    printf("\n");
}

int main() {
    insertnode(NULL, 7); // Insert 7 at the beginning
    insertnode(list, 10); // Insert 10 after 7
    insertnode(list, 16); // Insert 16 after 7
    display(); // Display the list

    deletenode(list->right); // Delete the node with value 10
    display(); // Display the list again

    return 0;
}