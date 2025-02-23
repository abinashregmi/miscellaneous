#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to merge two subarrays of A[]
void merge(int A[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = A[left + i];
    for (j = 0; j < n2; j++)
        R[j] = A[mid + 1 + j];

    // Merge the temporary arrays back into A[left..right]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = left; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

// Function to implement Merge Sort
void mergeSort(int A[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(A, left, mid);
        mergeSort(A, mid + 1, right);

        // Merge the sorted halves
        merge(A, left, mid, right);
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
    int n = 69; // Size of the array
    int A[n];

    // Generate random integers and fill the array
    srand(time(0));
    for (int i = 0; i < n; i++) {
        A[i] = rand() % 1000;
    }

    printf("Original array: \n");
    displayArray(A, n);

    // Measure execution time for Merge Sort
    clock_t start = clock();
    mergeSort(A, 0, n - 1);
    clock_t end = clock();
    double mergeSortTime = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Sorted array: \n");
    displayArray(A, n);
    printf("Merge Sort execution time: %f seconds\n", mergeSortTime);

    return 0;
}