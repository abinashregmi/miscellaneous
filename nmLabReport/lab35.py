import numpy as np

N = 10
MAX_ITER = 1000
TOL = 1e-6

def initialize(grid):
    for i in range(N):
        for j in range(N):
            grid[i][j] = 0.0

def apply_boundary_conditions(grid):
    for i in range(N):
        grid[i][0] = 1.0
        grid[i][N-1] = 1.0
        grid[0][i] = 1.0
        grid[N-1][i] = 1.0

def solve_poisson(grid):
    new_grid = np.copy(grid)
    for iter in range(MAX_ITER):
        for i in range(1, N-1):
            for j in range(1, N-1):
                new_grid[i][j] = 0.25 * (grid[i+1][j] + grid[i-1][j] + grid[i][j+1] + grid[i][j-1])

        max_diff = np.max(np.abs(new_grid - grid))
        grid = np.copy(new_grid)

        if max_diff < TOL:
            print(f"Converged after {iter} iterations")
            break

def print_grid(grid):
    for row in grid:
        print(" ".join(f"{val:.2f}" for val in row))

def main():
    grid = np.zeros((N, N))
    initialize(grid)
    apply_boundary_conditions(grid)
    solve_poisson(grid)
    print_grid(grid)

if __name__ == "__main__":
    main()