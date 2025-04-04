#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sequentialSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int size, int target) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void generateRandomArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

int main() {
    int size = 10000;
    int target = 50;

    int unsortedArr[size];
    int sortedArr[size];
    generateRandomArray(unsortedArr, size);
    for (int i = 0; i < size; i++) {
        sortedArr[i] = unsortedArr[i];
    }
    bubbleSort(sortedArr, size);

    clock_t start = clock();
    int seqResultUnsorted = sequentialSearch(unsortedArr, size, target);
    clock_t end = clock();
    double seqTimeUnsorted = (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    int seqResultSorted = sequentialSearch(sortedArr, size, target);
    end = clock();
    double seqTimeSorted = (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    int binResultUnsorted = binarySearch(sortedArr, size, target);
    end = clock();
    double binTimeUnsorted = (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    int binResultSorted = binarySearch(sortedArr, size, target);
    end = clock();
    double binTimeSorted = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Sequential Search on Unsorted Array:\n");
    if (seqResultUnsorted != -1) {
        printf("Element %d found at index %d.\n", target, seqResultUnsorted);
    } else {
        printf("Element %d not found in unsorted array.\n", target);
    }
    printf("Time taken: %.6f seconds\n\n", seqTimeUnsorted);

    printf("Sequential Search on Sorted Array:\n");
    if (seqResultSorted != -1) {
        printf("Element %d found at index %d.\n", target, seqResultSorted);
    } else {
        printf("Element %d not found in sorted array.\n", target);
    }
    printf("Time taken: %.6f seconds\n\n", seqTimeSorted);

    printf("Binary Search on Unsorted Array (after sorting):\n");
    if (binResultUnsorted != -1) {
        printf("Element %d found at index %d.\n", target, binResultUnsorted);
    } else {
        printf("Element %d not found in unsorted array.\n", target);
    }
    printf("Time taken: %.6f seconds\n\n", binTimeUnsorted);

    printf("Binary Search on Sorted Array:\n");
    if (binResultSorted != -1) {
        printf("Element %d found at index %d.\n", target, binResultSorted);
    } else {
        printf("Element %d not found in sorted array.\n", target);
    }
    printf("Time taken: %.6f seconds\n\n", binTimeSorted);

    return 0;
}
