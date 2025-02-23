#include <stdio.h>
#include <conio.h>

int main() {
    int i, j, n;
    float v = 0, p, xv, x[10], fx[10], a[10];

    // Input the number of data points
    printf("Enter the number of data points: \n");
    scanf("%d", &n);

    // Input the value of x for interpolation
    printf("Enter the value of x to interpolate: \n");
    scanf("%f", &xv);

    // Input the x and fx values
    for (i = 0; i < n; i++) {
        printf("Enter the value of x and fx at i = %d: \n", i);
        scanf("%f%f", &x[i], &fx[i]);
    }

    // Copy fx values to a[] for divided difference calculations
    for (i = 0; i < n; i++) {
        a[i] = fx[i];
    }

    // Calculate the divided differences
    for (i = 1; i < n; i++) {
        for (j = n - 1; j >= i; j--) {
            a[j] = (a[j] - a[j - 1]) / (x[j] - x[j - i]);
        }
    }

    // Compute the final interpolated value using Newton's formula
    p = 1;  // Initialize p to 1
    v = a[0];  // Start with the first value of a[]
    for (i = 1; i < n; i++) {
        p *= (xv - x[i - 1]);  // Multiply by (xv - x0)(xv - x1)...(xv - xi-1)
        v += a[i] * p;  // Add the current term to the result
    }

    // Output the interpolated value
    printf("The interpolated value at x = %.2f is: %.2f\n", xv, v);

    getch();
    return 0;
}