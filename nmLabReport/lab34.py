import numpy as np

N = 10
MAX_ITER = 1000
TOL = 1e-5

def initialize(grid):
    for i in range(N):
        for j in range(N):
            if i == 0 or i == N-1 or j == 0 or j == N-1:
                grid[i][j] = 100.0  # Boundary conditions
            else:
                grid[i][j] = 0.0  # Initial guess

def print_grid(grid):
    for row in grid:
        print(" ".join(f"{val:.2f}" for val in row))

def solve_laplace(grid):
    new_grid = np.copy(grid)
    iter = 0
    diff = 0.0

    while iter < MAX_ITER:
        diff = 0.0
        for i in range(1, N-1):
            for j in range(1, N-1):
                new_grid[i][j] = 0.25 * (grid[i+1][j] + grid[i-1][j] + grid[i][j+1] + grid[i][j-1])
                diff = max(diff, abs(new_grid[i][j] - grid[i][j]))

        grid = np.copy(new_grid)
        iter += 1

        if diff < TOL:
            break

def main():
    grid = np.zeros((N, N))
    initialize(grid)
    solve_laplace(grid)
    print_grid(grid)

if __name__ == "__main__":
    main()