#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to implement Selection Sort
void SelectionSort(int A[], int n) {
    int i, j, least, p;
    for (i = 0; i < n - 1; i++) {
        least = A[i];
        p = i;
        for (j = i + 1; j < n; j++) {
            if (A[j] < least) {
                least = A[j];
                p = j;
            }
        }
        swap(&A[i], &A[p]);
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
    int A[] = {64, 25, 12, 22, 11};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Original array: \n");
    displayArray(A, n);

    SelectionSort(A, n);

    printf("Sorted array: \n");
    displayArray(A, n);

    return 0;
}