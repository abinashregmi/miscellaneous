#include <stdio.h>
#include <math.h>

// Function to be integrated
double f(double x) {
    return 1 / (1 + x * x); // Example function: f(x) = 1 / (1 + x^2)
}

// Composite Simpson's 1/3 Rule
double compositeSimpsons(double a, double b, int n) {
    if (n % 2 != 0) {
        printf("n must be even.\n");
        return -1;
    }

    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 2 == 0) {
            sum += 2 * f(x);
        } else {
            sum += 4 * f(x);
        }
    }

    return (h / 3) * sum;
}

int main() {
    double a = 0; // Lower limit
    double b = 1; // Upper limit
    int n = 6;    // Number of intervals (must be even)

    double result = compositeSimpsons(a, b, n);
    if (result != -1) {
        printf("The integral is: %lf\n", result);
    }

    return 0;
}