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

// Function to partition the array for Quick Sort
int partition(int A[], int low, int high) {
    int pivot = A[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (A[j] < pivot) {
            i++;
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    int temp = A[i + 1];
    A[i + 1] = A[high];
    A[high] = temp;
    return (i + 1);
}

// Function to implement Quick Sort
void quickSort(int A[], int low, int high) {
    if (low < high) {
        int pi = partition(A, low, high);

        // Recursively sort elements before partition and after partition
        quickSort(A, low, pi - 1);
        quickSort(A, pi + 1, high);
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
    int n = 100; // Size of the array
    int A[n], B[n];

    // Generate random integers and fill the arrays
    srand(time(0));
    for (int i = 0; i < n; i++) {
        A[i] = rand() % 1000;
        B[i] = A[i]; // Copy array A to B for fair comparison
    }

    printf("Original array: \n");
    displayArray(A, n);

    // Measure execution time for Merge Sort
    clock_t start = clock();
    mergeSort(A, 0, n - 1);
    clock_t end = clock();
    double mergeSortTime = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Sorted array using Merge Sort: \n");
    displayArray(A, n);
    printf("Merge Sort execution time: %f seconds\n", mergeSortTime);

    // Measure execution time for Quick Sort
    start = clock();
    quickSort(B, 0, n - 1);
    end = clock();
    double quickSortTime = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Sorted array using Quick Sort: \n");
    displayArray(B, n);
    printf("Quick Sort execution time: %f seconds\n", quickSortTime);

    return 0;
}