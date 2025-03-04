#include <stdio.h>

// Function to compute the derivative dy/dx
double dydx(double x, double y) {
    return (x + y); // Example: dy/dx = x + y
}

// Function to implement Euler's Method
void euler(double x0, double y0, double h, int n) {
    double x = x0;
    double y = y0;

    printf("x0 = %lf, y0 = %lf\n", x, y);

    for (int i = 1; i <= n; i++) {
        y = y + h * dydx(x, y);
        x = x + h;
        printf("x%d = %lf, y%d = %lf\n", i, x, i, y);
    }
}

int main() {
    double x0 = 0; // Initial value of x
    double y0 = 1; // Initial value of y
    double h = 0.1; // Step size
    int n = 10; // Number of steps

    euler(x0, y0, h, n);

    return 0;
}