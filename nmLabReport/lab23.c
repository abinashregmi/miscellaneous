#include <stdio.h>

// Function to be integrated
double f(double x) {
    return x * x; // Example function: f(x) = x^2
}

// Composite Trapezoidal Rule function
double trapezoidal(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b));
    
    for (int i = 1; i < n; i++) {
        sum += f(a + i * h);
    }
    
    return sum * h;
}

int main() {
    double a, b;
    int n;
    
    // Input the limits of integration and number of subintervals
    printf("Enter the lower limit a: ");
    scanf("%lf", &a);
    printf("Enter the upper limit b: ");
    scanf("%lf", &b);
    printf("Enter the number of subintervals n: ");
    scanf("%d", &n);
    
    // Calculate the integral
    double result = trapezoidal(a, b, n);
    
    // Output the result
    printf("The integral is: %lf\n", result);
    
    return 0;
}