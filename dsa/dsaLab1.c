// A program to read n numbers and to find the sum and average of those numbers.

#include <stdio.h>

int main() {
    int n, i;
    float sum = 0, average;

    // Read the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    float numbers[n];

    // Read the elements and calculate the sum
    
    printf("Enter the numbers:\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &numbers[i]);
        sum += numbers[i];
    }

    // Calculate the average
    average = sum / n;

    // Print the sum and average
    printf("Sum = %.2f\n", sum);
    printf("Average = %.2f\n", average);

    return 0;
}