#include <stdio.h>
#define MAX_SIZE 10

int list[MAX_SIZE];
int size = 0;

void insertElement(int position, int element)
{
    if (size == MAX_SIZE)
    {
        printf("Error: List is full, cannot insert element.\n");
        return;
    }
    if (position < 0 || position > size)
    {
        printf("Error: Invalid position. Valid range is 0 to %d.\n", size);
        return;
    }
    for (int i = size; i > position; i--)
    {
        list[i] = list[i - 1]; // Shift elements to the right
    }
    list[position] = element; // Insert the new element
    size++;                   // Increment the size of the list
}

void deleteElement(int position)
{
    if (position < 0 || position >= size)
    {
        printf("Error: Invalid position. Valid range is 0 to %d.\n", size - 1);
        return;
    }
    for (int i = position; i < size - 1; i++)
    {
        list[i] = list[i + 1]; // Shift elements to the left
    }
    size--; // Decrement the size of the list
    printf("Deleted element at position %d.\n", position);
}

// Function to merge two lists
int mergeLists(int list1[], int size1, int list2[], int size2)
{
    if (size1 + size2 > MAX_SIZE)
    {
        printf("Error: The merged list will exceed the maximum size.\n");
        return -1;
    }
    for (int i = 0; i < size2; i++)
    {
        list1[size1 + i] = list2[i]; // Append elements of list2 to list1
    }
    printf("Lists merged successfully.\n");
    return size1 + size2; // Return the size of the merged list
}

// Function to search for an element in the list
int searchElement(int element)
{
    for (int i = 0; i < size; i++)
    {
        if (list[i] == element)
        {
            return i; // Return the index if the element is found
        }
    }
    return -1; // Return -1 if the element is not found
}

void displayList()
{
    printf("List: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", list[i]);
    }
    printf("\n");
}

// Main function to demonstrate the list implementation
int main()
{
    insertElement(0, 10); // Insert 10 at position 0
    insertElement(1, 20); // Insert 20 at position 1
    insertElement(1, 15); // Insert 15 at position 1

    displayList(); // Display the list

    // Create a second list
    int list2[MAX_SIZE] = {56, 36, 33};
    int size2 = 3;

    // Merge the second list into the first list
    size = mergeLists(list, size, list2, size2);
    displayList(); // Display the merged list

    deleteElement(1); // Delete the element at position 1
    displayList();    // Display the list after deletion

    int search = 20; // Search for the element 20
    int index = searchElement(search);
    if (index != -1)
    {
        printf("Element %d found at position %d.\n", search, index);
    }
    else
    {
        printf("Element %d not found in the list.\n", search);
    }

    return 0;
}