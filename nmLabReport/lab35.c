#include <stdio.h>
#include <math.h>

#define N 10  // Number of grid points in each dimension
#define MAX_ITER 1000  // Maximum number of iterations
#define TOL 1e-6  // Tolerance for convergence

void initialize(double grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            grid[i][j] = 0.0;
        }
    }
}

void apply_boundary_conditions(double grid[N][N]) {
    for (int i = 0; i < N; i++) {
        grid[i][0] = 1.0;  // Example boundary condition
        grid[i][N-1] = 1.0;
        grid[0][i] = 1.0;
        grid[N-1][i] = 1.0;
    }
}

void solve_poisson(double grid[N][N]) {
    double new_grid[N][N];
    for (int iter = 0; iter < MAX_ITER; iter++) {
        for (int i = 1; i < N-1; i++) {
            for (int j = 1; j < N-1; j++) {
                new_grid[i][j] = 0.25 * (grid[i+1][j] + grid[i-1][j] + grid[i][j+1] + grid[i][j-1]);
            }
        }

        // Check for convergence
        double max_diff = 0.0;
        for (int i = 1; i < N-1; i++) {
            for (int j = 1; j < N-1; j++) {
                max_diff = fmax(max_diff, fabs(new_grid[i][j] - grid[i][j]));
                grid[i][j] = new_grid[i][j];
            }
        }

        if (max_diff < TOL) {
            printf("Converged after %d iterations\n", iter);
            break;
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

int main() {
    double grid[N][N];
    initialize(grid);
    apply_boundary_conditions(grid);
    solve_poisson(grid);
    print_grid(grid);
    return 0;
}