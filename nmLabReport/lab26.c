#include <stdio.h>
#include <math.h>

// Define the function to be integrated
double f(double x) {
    return 1 / (1 + x * x); // Example function: f(x) = 1 / (1 + x^2)
}

// Simpson's 3/8 Rule function
double simpsons_38_rule(double a, double b, int n) {
    if (n % 3 != 0) {
        printf("n must be a multiple of 3.\n");
        return -1;
    }

    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i++) {
        if (i % 3 == 0) {
            sum += 2 * f(a + i * h);
        } else {
            sum += 3 * f(a + i * h);
        }
    }

    return (3 * h / 8) * sum;
}

int main() {
    double a, b;
    int n;

    // Input the limits of integration and number of intervals
    printf("Enter the lower limit a: ");
    scanf("%lf", &a);
    printf("Enter the upper limit b: ");
    scanf("%lf", &b);
    printf("Enter the number of intervals n (multiple of 3): ");
    scanf("%d", &n);

    // Calculate the integral using Simpson's 3/8 Rule
    double result = simpsons_38_rule(a, b, n);
    if (result != -1) {
        printf("The integral is: %lf\n", result);
    }

    return 0;
}