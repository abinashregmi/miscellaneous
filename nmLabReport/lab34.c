#include <stdio.h>
#include <math.h>

#define N 10
#define MAX_ITER 1000
#define TOL 1e-5

void initialize(double grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == 0 || i == N-1 || j == 0 || j == N-1) {
                grid[i][j] = 100.0; // Boundary conditions
            } else {
                grid[i][j] = 0.0; // Initial guess
            }
        }
    }
}

void print_grid(double grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%6.2f ", grid[i][j]);
        }
        printf("\n");
    }
}

void solve_laplace(double grid[N][N]) {
    double new_grid[N][N];
    int iter = 0;
    double diff;

    do {
        diff = 0.0;
        for (int i = 1; i < N-1; i++) {
            for (int j = 1; j < N-1; j++) {
                new_grid[i][j] = 0.25 * (grid[i+1][j] + grid[i-1][j] + grid[i][j+1] + grid[i][j-1]);
                diff = fmax(diff, fabs(new_grid[i][j] - grid[i][j]));
            }
        }

        for (int i = 1; i < N-1; i++) {
            for (int j = 1; j < N-1; j++) {
                grid[i][j] = new_grid[i][j];
            }
        }

        iter++;
    } while (diff > TOL && iter < MAX_ITER);
}

int main() {
    double grid[N][N];
    initialize(grid);
    solve_laplace(grid);
    print_grid(grid);
    return 0;
}