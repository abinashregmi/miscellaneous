// Sort a list of student scores using Shell Sort and compare its execution time with Bubble Sort for the same list.
#include <stdio.h>
#include <time.h>

// Function to implement Bubble Sort
void BubbleSort(int A[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

// Function to implement Shell Sort
void ShellSort(int A[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = A[i];
            int j;
            for (j = i; j >= gap && A[j - gap] > temp; j -= gap) {
                A[j] = A[j - gap];
            }
            A[j] = temp;
        }
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
    int A[] = {89, 45, 68, 90, 29, 34, 17};
    int n = sizeof(A) / sizeof(A[0]);
    int B[n];
    
    // Copy array A to B
    for (int i = 0; i < n; i++) {
        B[i] = A[i];
    }

    printf("Original array: \n");
    displayArray(A, n);

    // Measure execution time for Bubble Sort
    clock_t start = clock();
    BubbleSort(A, n);
    clock_t end = clock();
    double bubbleSortTime = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Sorted array using Bubble Sort: \n");
    displayArray(A, n);
    printf("Bubble Sort execution time: %f seconds\n", bubbleSortTime);

    // Measure execution time for Shell Sort
    start = clock();
    ShellSort(B, n);
    end = clock();
    double shellSortTime = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Sorted array using Shell Sort: \n");
    displayArray(B, n);
    printf("Shell Sort execution time: %f seconds\n", shellSortTime);

    return 0;
}