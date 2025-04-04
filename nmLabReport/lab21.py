import math

def factorial(n):
    fact = 1
    for i in range(2, n + 1):
        fact *= i
    return fact

def backward_difference_table(x, y, n):
    for i in range(1, n):
        for j in range(n - 1, i - 1, -1):
            y[j][i] = y[j][i - 1] - y[j - 1][i - 1]

def newton_backward_difference(x, y, n, value):
    h = x[1] - x[0]
    u = (value - x[n - 1]) / h
    derivative = 0

    for i in range(1, n):
        derivative += (y[n - 1][i] * i * math.pow(u, i - 1)) / factorial(i)

    return derivative / h

def main():
    n = int(input("Enter the number of data points: "))
    x = []
    y = [[0 for _ in range(n)] for _ in range(n)]

    print("Enter the data points (x and y):")
    for i in range(n):
        x.append(float(input(f"x[{i}] = ")))
        y[i][0] = float(input(f"y[{i}] = "))

    value = float(input("Enter the value to find the derivative at: "))

    backward_difference_table(x, y, n)
    result = newton_backward_difference(x, y, n, value)

    print(f"The derivative at x = {value:.2f} is {result:.4f}")

if __name__ == "__main__":
    main()