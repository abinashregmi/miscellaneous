def f(x, y):
    return x + y  # Example: dy/dx = x + y

def heuns_method(x0, y0, h, n):
    x = x0
    y = y0

    print(f"x0 = {x:.6f}, y0 = {y:.6f}")

    for i in range(n):
        y_predict = y + h * f(x, y)
        y_correct = y + (h / 2) * (f(x, y) + f(x + h, y_predict))
        x += h
        y = y_correct

        print(f"x{i+1} = {x:.6f}, y{i+1} = {y:.6f}")

def main():
    x0 = 0.0  # Initial value of x
    y0 = 1.0  # Initial value of y
    h = 0.1  # Step size
    n = 10  # Number of steps

    heuns_method(x0, y0, h, n)

if __name__ == "__main__":
    main()