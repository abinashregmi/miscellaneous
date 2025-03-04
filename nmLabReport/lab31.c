#include <stdio.h>

// Define the differential equation dy/dx = f(x, y)
double f(double x, double y) {
    return x + y; // Example: dy/dx = x + y
}

// Heun's Method to solve the ODE
void heunsMethod(double x0, double y0, double h, int n) {
    double x = x0;
    double y = y0;
    double y_predict, y_correct;

    printf("x0 = %lf, y0 = %lf\n", x, y);

    for (int i = 0; i < n; i++) {
        y_predict = y + h * f(x, y);
        y_correct = y + (h / 2) * (f(x, y) + f(x + h, y_predict));
        x += h;
        y = y_correct;

        printf("x%d = %lf, y%d = %lf\n", i + 1, x, i + 1, y);
    }
}

int main() {
    double x0 = 0.0; // Initial value of x
    double y0 = 1.0; // Initial value of y
    double h = 0.1;  // Step size
    int n = 10;      // Number of steps

    heunsMethod(x0, y0, h, n);

    return 0;
}