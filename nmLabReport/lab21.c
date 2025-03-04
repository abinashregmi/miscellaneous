#include <stdio.h>

#define MAX 10

// Function to calculate factorial
int factorial(int n) {
    int fact = 1;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Function to calculate the backward difference table
void backwardDifferenceTable(float x[], float y[][MAX], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = n - 1; j >= i; j--) {
            y[j][i] = y[j][i - 1] - y[j - 1][i - 1];
        }
    }
}

// Function to calculate the derivative using Newton's Backward Difference
float newtonBackwardDifference(float x[], float y[][MAX], int n, float value) {
    float h = x[1] - x[0];
    float u = (value - x[n - 1]) / h;
    float derivative = 0;

    for (int i = 1; i < n; i++) {
        derivative += (y[n - 1][i] * i * pow(u, i - 1)) / factorial(i);
    }

    return derivative / h;
}

int main() {
    int n;
    float x[MAX], y[MAX][MAX], value;

    // Input number of data points
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    // Input data points
    printf("Enter the data points (x and y):\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);
        printf("y[%d] = ", i);
        scanf("%f", &y[i][0]);
    }

    // Input the value to find the derivative at
    printf("Enter the value to find the derivative at: ");
    scanf("%f", &value);

    // Calculate the backward difference table
    backwardDifferenceTable(x, y, n);

    // Calculate the derivative using Newton's Backward Difference
    float result = newtonBackwardDifference(x, y, n, value);

    // Output the result
    printf("The derivative at x = %.2f is %.4f\n", value, result);

    return 0;
}