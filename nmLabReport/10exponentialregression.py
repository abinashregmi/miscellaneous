# 10exponentialregression.py

import math

def exponential_regression(x, y):
    n = len(x)
    sx = sum(x)
    slgy = sum(math.log(yi) for yi in y)
    sxy = sum(x[i] * math.log(y[i]) for i in range(n))
    sx2 = sum(x[i] ** 2 for i in range(n))

    b = ((n * sxy) - (sx * slgy)) / ((n * sx2) - (sx ** 2))
    r = (slgy / n) - (b * sx / n)
    a = math.exp(r)
    return a, b

def main():
    n = int(input("Enter the number of points: "))
    x = []
    y = []
    print("Enter the value of x and fx:")
    for _ in range(n):
        xi, yi = map(float, input().split())
        x.append(xi)
        y.append(yi)

    a, b = exponential_regression(x, y)
    print(f"Fitted curve is: y = {a}e^{b}x")

if __name__ == "__main__":
    main()