def dydx(x, y):
    return x + y  # Example: dy/dx = x + y

def euler(x0, y0, h, n):
    x = x0
    y = y0

    print(f"x0 = {x:.6f}, y0 = {y:.6f}")

    for i in range(1, n + 1):
        y = y + h * dydx(x, y)
        x = x + h
        print(f"x{i} = {x:.6f}, y{i} = {y:.6f}")

def main():
    x0 = 0  # Initial value of x
    y0 = 1  # Initial value of y
    h = 0.1  # Step size
    n = 10  # Number of steps

    euler(x0, y0, h, n)

if __name__ == "__main__":
    main()