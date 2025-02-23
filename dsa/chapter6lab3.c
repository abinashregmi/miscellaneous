//Implement Insertion Sort to sort a list of customer IDs in ascending order and display the sorted IDs.
#include <stdio.h>

// Function to implement Insertion Sort
void InsertionSort(int A[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = A[i];
        j = i - 1;

        // Move elements of A[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = key;
    }
}

// Function to display the array
void displayArray(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main() {
    int A[] = {31, 41, 59, 26, 41, 58};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Original array: \n");
    displayArray(A, n);

    InsertionSort(A, n);

    printf("Sorted array: \n");
    displayArray(A, n);

    return 0;
}