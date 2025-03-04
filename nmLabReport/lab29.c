#include <stdio.h>
#include <math.h>

// Define the function f(x, y) = dy/dx
double f(double x, double y) {
    return x + y; // Example function
}

// Define the derivative of f with respect to x
double dfdx(double x, double y) {
    return 1; // Example derivative
}

// Define the derivative of f with respect to y
double dfdy(double x, double y) {
    return 1; // Example derivative
}

// Taylor series method to solve ODE
void taylorSeriesMethod(double x0, double y0, double h, int n) {
    double x = x0;
    double y = y0;
    printf("x = %lf, y = %lf\n", x, y);
    for (int i = 0; i < n; i++) {
        double f_val = f(x, y);
        double dfdx_val = dfdx(x, y);
        double dfdy_val = dfdy(x, y);
        y = y + h * f_val + (h * h / 2) * (dfdx_val + f_val * dfdy_val);
        x = x + h;
        printf("x = %lf, y = %lf\n", x, y);
    }
}

int main() {
    double x0 = 0; // Initial x value
    double y0 = 1; // Initial y value
    double h = 0.1; // Step size
    int n = 10; // Number of steps

    taylorSeriesMethod(x0, y0, h, n);

    return 0;
}