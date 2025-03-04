
#include <stdio.h>
#include <math.h>

// Function to integrate
double f(double x) {
    return exp(-x * x);
}

// Weights and abscissas for 2-point Gaussian quadrature
const double w[2] = {1.0, 1.0};
const double x[2] = {-0.5773502692, 0.5773502692};

double gaussianIntegration(double a, double b) {
    double integral = 0.0;
    double midpoint = (a + b) / 2.0;
    double half_length = (b - a) / 2.0;

    for (int i = 0; i < 2; i++) {
        integral += w[i] * f(midpoint + half_length * x[i]);
    }

    integral *= half_length;
    return integral;
}

int main() {
    double a = -1.0;
    double b = 1.0;
    double result = gaussianIntegration(a, b);
    printf("The integral from %f to %f is approximately %f\n", a, b, result);
    return 0;
}