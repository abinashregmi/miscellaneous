#include <stdio.h>

void newtonForwardDifference(float x[], float y[], int n, float value) {
    float h = x[1] - x[0];
    float diffTable[n][n];
    float derivative;

    // Initialize the difference table
    for (int i = 0; i < n; i++) {
        diffTable[i][0] = y[i];
    }

    // Calculate the forward differences
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            diffTable[i][j] = diffTable[i + 1][j - 1] - diffTable[i][j - 1];
        }
    }

    // Calculate the derivative using Newton's Forward Difference formula
    derivative = diffTable[0][1] / h;

    printf("The derivative at x = %.2f is %.2f\n", value, derivative);
}

int main() {
    int n;
    float value;

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    float x[n], y[n];

    printf("Enter the data points (x and y):\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);
        printf("y[%d] = ", i);
        scanf("%f", &y[i]);
    }

    printf("Enter the value of x at which the derivative is to be calculated: ");
    scanf("%f", &value);

    newtonForwardDifference(x, y, n, value);

    return 0;
}