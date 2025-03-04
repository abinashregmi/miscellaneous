#include <stdio.h>

// Define the differential equation dy/dx = f(x, y)
double f(double x, double y) {
    return (x + y); // Example: dy/dx = x + y
}

// Function to implement the Fourth Order Runge-Kutta Method
void rungeKutta(double x0, double y0, double x, double h) {
    int n = (int)((x - x0) / h); // Number of iterations
    double k1, k2, k3, k4, y = y0;

    printf("x0\ty0\n");
    printf("%lf\t%lf\n", x0, y0);

    for (int i = 1; i <= n; i++) {
        k1 = h * f(x0, y);
        k2 = h * f(x0 + 0.5 * h, y + 0.5 * k1);
        k3 = h * f(x0 + 0.5 * h, y + 0.5 * k2);
        k4 = h * f(x0 + h, y + k3);

        y = y + (1.0 / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4);
        x0 = x0 + h;

        printf("%lf\t%lf\n", x0, y);
    }
}

int main() {
    double x0 = 0, y0 = 1; // Initial conditions
    double x = 2; // Point at which we need the solution
    double h = 0.2; // Step size

    rungeKutta(x0, y0, x, h);

    return 0;
}