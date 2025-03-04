#include <stdio.h>

double trapezoidal_rule(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b));
    
    for (int i = 1; i < n; i++) {
        sum += f(a + i * h);
    }
    
    return sum * h;
}

double function(double x) {
    // Example function: f(x) = x^2
    return x * x;
}

int main() {
    double a = 0.0; // Lower limit
    double b = 1.0; // Upper limit
    int n = 100;    // Number of subintervals

    double result = trapezoidal_rule(function, a, b, n);
    printf("The integral is: %lf\n", result);

    return 0;
}