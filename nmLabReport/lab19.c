#include <stdio.h>

// Function to approximate
double f(double x) {
    return x * x; // Example function: f(x) = x^2
}

// Three Point Formula for derivative
double three_point_formula(double x, double h) {
    return (f(x + h) - f(x - h)) / (2 * h);
}

int main() {
    double x, h;

    // Input the point and step size
    printf("Enter the point at which to approximate the derivative: ");
    scanf("%lf", &x);
    printf("Enter the step size: ");
    scanf("%lf", &h);

    // Calculate the derivative using Three Point Formula
    double derivative = three_point_formula(x, h);

    // Output the result
    printf("The approximate derivative at x = %lf is %lf\n", x, derivative);

    return 0;
}