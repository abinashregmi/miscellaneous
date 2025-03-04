# 9linearregression.py

def linear_regression(x, y):
    n = len(x)
    sx = sum(x)
    sy = sum(y)
    sxy = sum(x[i] * y[i] for i in range(n))
    sx2 = sum(x[i] ** 2 for i in range(n))

    b = ((n * sxy) - (sx * sy)) / ((n * sx2) - (sx ** 2))
    a = (sy / n) - (b * sx / n)
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

    a, b = linear_regression(x, y)
    print(f"Fitted line is: {a} + {b}x")

if __name__ == "__main__":
    main()