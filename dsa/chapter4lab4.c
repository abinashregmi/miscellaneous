#include <stdio.h>

// Function to find the largest element using tail recursion
int findLargest(int arr[], int n, int max) {
    if (n == 0) {
        return max; // Base case: return the maximum element found
    } else {
        if (arr[n-1] > max) {
            max = arr[n-1]; // Update max if current element is greater
        }
        return findLargest(arr, n-1, max); // Recursive case
    }
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int largest = findLargest(arr, n, arr[0]);
    printf("The largest element in the array is: %d\n", largest);

    return 0;
}