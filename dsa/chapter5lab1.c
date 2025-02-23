#include <stdio.h>
#define MAX_SIZE 10

int list[MAX_SIZE];
int size = 0;

void insertElement(int position, int element) {
    if (size == MAX_SIZE) {
        printf("List is full\n");
    } else if (position < 0 || position > size) {
        printf("Invalid position\n");
    } else {
        for (int i = size; i > position; i--) {
            list[i] = list[i - 1];
        }
        list[position] = element;
        size++;
        printf("Element inserted successfully\n");
    }
}

void deleteElement(int position) {
    if (size == 0) {
        printf("List is empty\n");
    } else if (position < 0 || position >= size) {
        printf("Invalid position\n");
    } else {
        for (int i = position; i < size - 1; i++) {
            list[i] = list[i + 1];
        }
        size--;
        printf("Element deleted successfully\n");
    }
}

int searchElement(int element) {
    for (int i = 0; i < size; i++) {
        if (list[i] == element) {
            return i;
        }
    }
    return -1;
}

void displayList() {
    if (size == 0) {
        printf("List is empty\n");
    } else {
        printf("List elements:\n");
        for (int i = 0; i < size; i++) {
            printf("%d\n", list[i]);
        }
    }
}

int main() {
    insertElement(0, 5);
    insertElement(1, 10);
    insertElement(2, 15);
    displayList();
    deleteElement(1);
    displayList();
    int search = 5;
    int index = searchElement(search);
    if (index != -1) {
        printf("%d found at position %d\n", search, index);
    } else {
        printf("%d not found in the list\n", search);
    }
    return 0;
}