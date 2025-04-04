#include <stdio.h>

int sequential_search(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; // Return index of the key if found
        }
    }
    return -1; // Return -1 if the key is not found
}

int main() {
    int arr[] = {10, 25, 30, 45, 60, 75, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 45; // Key to search for

    int result = sequential_search(arr, n, key);
    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }

    return 0;
}
