#include <stdio.h>
#include <math.h>

double f(double x) {
    // Define the function to integrate here
    return x * x; // Example: f(x) = x^2
}

double trapezoidal_rule(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b));
    for (int i = 1; i < n; i++) {
        sum += f(a + i * h);
    }
    return sum * h;
}

void romberg_integration(double (*f)(double), double a, double b, double R[10][10], int n) {
    for (int i = 0; i < n; i++) {
        R[i][0] = trapezoidal_rule(f, a, b, pow(2, i));
    }
    for (int j = 1; j < n; j++) {
        for (int i = j; i < n; i++) {
            R[i][j] = (pow(4, j) * R[i][j-1] - R[i-1][j-1]) / (pow(4, j) - 1);
        }
    }
}

int main() {
    int n = 5; // Number of rows/columns in Romberg table
    double a = 0; // Lower limit of integration
    double b = 1; // Upper limit of integration
    double R[10][10] = {0};

    romberg_integration(f, a, b, R, n);

    printf("Romberg Integration Table:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%f ", R[i][j]);
        }
        printf("\n");
    }

    printf("Estimated value of the integral: %f\n", R[n-1][n-1]);

    return 0;
}