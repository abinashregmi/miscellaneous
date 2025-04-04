import math

def f(x):
    return x * x  # Example: f(x) = x^2

def trapezoidal_rule(f, a, b, n):
    h = (b - a) / n
    sum = 0.5 * (f(a) + f(b))
    for i in range(1, n):
        sum += f(a + i * h)
    return sum * h

def romberg_integration(f, a, b, n):
    R = [[0 for _ in range(n)] for _ in range(n)]
    for i in range(n):
        R[i][0] = trapezoidal_rule(f, a, b, 2**i)
    for j in range(1, n):
        for i in range(j, n):
            R[i][j] = (4**j * R[i][j-1] - R[i-1][j-1]) / (4**j - 1)
    return R

def main():
    n = 5  # Number of rows/columns in Romberg table
    a = 0  # Lower limit of integration
    b = 1  # Upper limit of integration

    R = romberg_integration(f, a, b, n)

    print("Romberg Integration Table:")
    for i in range(n):
        for j in range(i + 1):
            print(f"{R[i][j]:.6f}", end=" ")
        print()

    print(f"Estimated value of the integral: {R[n-1][n-1]:.6f}")

if __name__ == "__main__":
    main()