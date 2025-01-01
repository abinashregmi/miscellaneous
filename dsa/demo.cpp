#include <stdio.h>

int fibonacci(int n) {
    if (n == 0) return 0; //Base case
    if (n == 1) return 1; //Base case
    return fibonacci(n - 1) + fibonacci(n - 2); //Recursive case
}

int main() {
    int terms = 10; 
    printf("Fibonacci series: ");
    for (int i = 0; i < terms; ++i) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
    return 0;
}