#include <stdio.h>
#include <math.h>

#define MAX_ITER 100
#define TOL 1e-6

void jacobi(int n, double a[n][n], double b[n], double x[n]) {
    double x_new[n];
    int iter = 0;
    double error;

    do {
        error = 0.0;
        for (int i = 0; i < n; i++) {
            x_new[i] = b[i];
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    x_new[i] -= a[i][j] * x[j];
                }
            }
            x_new[i] /= a[i][i];
            error += fabs(x_new[i] - x[i]);
        }

        for (int i = 0; i < n; i++) {
            x[i] = x_new[i];
        }

        iter++;
    } while (error > TOL && iter < MAX_ITER);
}

int main() {
    int n;
    printf("Enter the number of equations: ");
    scanf("%d", &n);

    double a[n][n], b[n], x[n];

    printf("Enter the coefficients of the matrix A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &a[i][j]);
        }
    }

    printf("Enter the constants vector B:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &b[i]);
        x[i] = 0; // Initial guess
    }

    jacobi(n, a, b, x);

    printf("The solution is:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = %lf\n", i, x[i]);
    }

    return 0;
}