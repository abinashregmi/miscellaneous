#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TABLE_SIZE 10007

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
        arr[i] = rand() % 10000;
    }
}

int linearProbingInsert(int hashTable[], int size, int value) {
    int index = value % size;
    while (hashTable[index] != -1) {
        index = (index + 1) % size;
    }
    hashTable[index] = value;
    return index;
}

double measureTime(void (*searchFunction)(int[], int, int), int arr[], int size, int target) {
    clock_t start = clock();
    searchFunction(arr, size, target);
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
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
    int binResultSorted = binarySearch(sortedArr, size, target);
    end = clock();
    double binTimeSorted = (double)(end - start) / CLOCKS_PER_SEC;

    int hashTableLinear[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTableLinear[i] = -1;
    }

    start = clock();
    for (int i = 0; i < size; i++) {
        linearProbingInsert(hashTableLinear, TABLE_SIZE, unsortedArr[i]);
    }
    end = clock();
    double linearProbingTime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Sequential Search on Unsorted Array: Time taken: %.6f seconds\n", seqTimeUnsorted);
    printf("Sequential Search on Sorted Array: Time taken: %.6f seconds\n", seqTimeSorted);
    printf("Binary Search on Sorted Array: Time taken: %.6f seconds\n", binTimeSorted);
    printf("Linear Probing Time: %.6f seconds\n", linearProbingTime);

    return 0;
}
