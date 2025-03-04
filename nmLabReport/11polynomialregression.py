# 11polynomialregression.py

import numpy as np

def polynomial_regression(x, y, degree):
    n = len(x)
    A = np.zeros((degree + 1, degree + 1))
    B = np.zeros(degree + 1)

    for i in range(degree + 1):
        for j in range(degree + 1):
            A[i][j] = sum(xi ** (i + j) for xi in x)
        B[i] = sum(yi * (xi ** i) for xi, yi in zip(x, y))

    coeffs = np.linalg.solve(A, B)
    return coeffs

def main():
    n = int(input("Enter the number of data points: "))
    degree = int(input("Enter the degree of the polynomial: "))
    x = []
    y = []
    print("Enter the value of x and fx:")
    for _ in range(n):
        xi, yi = map(float, input().split())
        x.append(xi)
        y.append(yi)

    coeffs = polynomial_regression(x, y, degree)
    print("The polynomial of regression is:")
    print(f"y = {coeffs[0]}", end="")
    for i in range(1, len(coeffs)):
        print(f" + {coeffs[i]}x^{i}", end="")
    print()

if __name__ == "__main__":
    main()