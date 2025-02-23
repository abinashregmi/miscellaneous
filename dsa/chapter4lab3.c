//A program to compute the Greatest Common Divisor (GCD) of two numbers using recursion. 

#include <stdio.h>

// Function to compute GCD using recursion
int gcd(int a, int b) {
    if (b == 0) {
        return a; // Base case: GCD(a, 0) is a
    } else {
        return gcd(b, a % b); // Recursive case
    }
}

int main() {
    int num1, num2;
    printf("Enter two numbers to find their GCD: ");
    scanf("%d %d", &num1, &num2);

    if (num1 < 0 || num2 < 0) {
        printf("Numbers must be non-negative.\n");
    } else {
        printf("GCD of %d and %d is %d\n", num1, num2, gcd(num1, num2));
    }

    return 0;
}