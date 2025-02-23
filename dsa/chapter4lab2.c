#include <stdio.h>

// Function to calculate Fibonacci number using recursion
int fibo(int n) {
    if (n == 1) {
        return 0; // Base case: F(1) = 0
    } else if (n == 2) {
        return 1; // Base case: F(2) = 1
    } else {
        return fibo(n - 1) + fibo(n - 2); // Recursive case
    }
}

int main() {
    int num;
    printf("Enter the position of the Fibonacci sequence: ");
    scanf("%d", &num);

    if (num <= 0) {
        printf("Position must be a positive integer.\n");
    } else {
        printf("Fibonacci number at position %d is %d\n", num, fibo(num));
    }

    return 0;
}