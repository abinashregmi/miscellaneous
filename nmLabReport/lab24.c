#include <stdio.h>
#include <math.h>

// Define the function to be integrated
double f(double x) {
    return 1 / (1 + x * x); // Example: f(x) = 1 / (1 + x^2)
}

// Simpson's 1/3 Rule function
double simpsonsOneThirdRule(double a, double b, int n) {
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
    double a, b;
    int n;

    // Input the limits of integration and number of intervals
    printf("Enter the lower limit a: ");
    scanf("%lf", &a);
    printf("Enter the upper limit b: ");
    scanf("%lf", &b);
    printf("Enter the number of intervals n (must be even): ");
    scanf("%d", &n);

    // Calculate the integral using Simpson's 1/3 Rule
    double result = simpsonsOneThirdRule(a, b, n);
    if (result != -1) {
        printf("The integral is: %lf\n", result);
    }

    return 0;
}