#include <stdio.h>
#include <math.h>

double forward_difference(double (*func)(double), double x, double h) {
    return (func(x + h) - func(x)) / h;
}

double func(double x) {
    return sin(x); // Example function, you can change it to any other function
}

int main() {
    double angle, increment, derivative;

    printf("Enter the angle in radians: ");
    scanf("%lf", &angle);

    printf("Enter the increment: ");
    scanf("%lf", &increment);

    // Convert angle from degrees to radians
    angle = angle * M_PI / 180.0;

    derivative = forward_difference(func, angle, increment);

    printf("The derivative at angle %.2lf with increment %.2lf is %.5lf\n", angle, increment, derivative);

    return 0;
}