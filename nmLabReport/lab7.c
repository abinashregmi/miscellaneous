#include <stdio.h>

// Function to calculate the divided differences
void dividedDifferenceTable(float x[], float fx[], float a[], int n) {
    for (int i = 0; i < n; i++) {
        a[i] = fx[i];
    }
    for (int j = 1; j < n; j++) {
        for (int i = n - 1; i >= j; i--) {
            a[i] = (a[i] - a[i - 1]) / (x[i] - x[i - j]);
        }
    }
}

// Function to interpolate the value at xv
float interpolate(float xv, float x[], float a[], int n) {
    float v = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        v = v * (xv - x[i]) + a[i];
    }
    return v;
}

int main() {
    int n;
    float x[10], fx[10], a[10], xv;

    // Read the number of points
    printf("Enter the number of points: ");
    scanf("%d", &n);

    // Read the x and fx values
    for (int i = 0; i < n; i++) {
        printf("Enter the value of x and fx at i = %d: ", i);
        scanf("%f%f", &x[i], &fx[i]);
    }

    // Read the value to interpolate
    printf("Enter the value of x to interpolate: ");
    scanf("%f", &xv);

    // Calculate the divided difference table
    dividedDifferenceTable(x, fx, a, n);

    // Interpolate the value at xv
    float result = interpolate(xv, x, a, n);

    // Print the result
    printf("Interpolated value at x = %f is %f\n", xv, result);

    return 0;
}