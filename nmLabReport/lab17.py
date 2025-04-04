import numpy as np

def gauss_seidel(a, b, tol=1e-6, max_iter=100):
    n = len(a)
    x = np.zeros(n)
    for _ in range(max_iter):
        x_new = np.copy(x)
        for i in range(n):
            s = sum(a[i][j] * x_new[j] for j in range(n) if j != i)
            x_new[i] = (b[i] - s) / a[i][i]
        if np.allclose(x, x_new, atol=tol):
            break
        x = x_new
    return x

def main():
    n = int(input("Enter the number of equations: "))
    a = np.zeros((n, n))
    b = np.zeros(n)

    print("Enter the coefficients of the matrix A:")
    for i in range(n):
        a[i] = list(map(float, input().split()))

    print("Enter the constants vector B:")
    b = list(map(float, input().split()))

    x = gauss_seidel(a, b)

    print("The solution is:")
    for i in range(n):
        print(f"x[{i}] = {x[i]:.6f}")

if __name__ == "__main__":
    main()