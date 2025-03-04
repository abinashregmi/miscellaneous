#include <stdio.h>
#include <math.h>

#define MAX 100
#define EPSILON 0.001

void gaussSeidel(float a[MAX][MAX], float b[MAX], float x[MAX], int n) {
    float x_new[MAX];
    int i, j, k;
    float sum;

    for (i = 0; i < n; i++) {
        x[i] = 0;
    }

    for (k = 0; k < MAX; k++) {
        for (i = 0; i < n; i++) {
            sum = b[i];
            for (j = 0; j < n; j++) {
                if (i != j) {
                    sum -= a[i][j] * x[j];
                }
            }
            x_new[i] = sum / a[i][i];
        }

        int converged = 1;
        for (i = 0; i < n; i++) {
            if (fabs(x_new[i] - x[i]) > EPSILON) {
                converged = 0;
                break;
            }
        }

        if (converged) {
            break;
        }

        for (i = 0; i < n; i++) {
            x[i] = x_new[i];
        }
    }
}

int main() {
    int n, i, j;
    float a[MAX][MAX], b[MAX], x[MAX];

    printf("Enter the number of equations: ");
    scanf("%d", &n);

    printf("Enter the coefficients of the matrix A:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    printf("Enter the constants vector B:\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &b[i]);
    }

    gaussSeidel(a, b, x, n);

    printf("The solution is:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = %f\n", i, x[i]);
    }

    return 0;
}