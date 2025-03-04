#include <stdio.h>

#define N 3

void printMatrix(double matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%0.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

void doolittleLUDecomposition(double matrix[N][N], double lower[N][N], double upper[N][N]) {
    for (int i = 0; i < N; i++) {
        // Upper Triangular
        for (int k = i; k < N; k++) {
            double sum = 0;
            for (int j = 0; j < i; j++) {
                sum += (lower[i][j] * upper[j][k]);
            }
            upper[i][k] = matrix[i][k] - sum;
        }

        // Lower Triangular
        for (int k = i; k < N; k++) {
            if (i == k)
                lower[i][i] = 1; // Diagonal as 1
            else {
                double sum = 0;
                for (int j = 0; j < i; j++) {
                    sum += (lower[k][j] * upper[j][i]);
                }
                lower[k][i] = (matrix[k][i] - sum) / upper[i][i];
            }
        }
    }
}

int main() {
    double matrix[N][N] = {
        {2, -1, -2},
        {-4, 6, 3},
        {-4, -2, 8}
    };

    double lower[N][N] = {0};
    double upper[N][N] = {0};

    doolittleLUDecomposition(matrix, lower, upper);

    printf("Lower Triangular Matrix:\n");
    printMatrix(lower);

    printf("Upper Triangular Matrix:\n");
    printMatrix(upper);

    return 0;
}