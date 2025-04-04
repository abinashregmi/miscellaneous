def f(x, y):
    return x + y  # Example: dy/dx = x + y

def runge_kutta(x0, y0, x, h):
    n = int((x - x0) / h)
    y = y0

    print(f"x0 = {x0:.6f}, y0 = {y0:.6f}")

    for i in range(1, n + 1):
        k1 = h * f(x0, y)
        k2 = h * f(x0 + 0.5 * h, y + 0.5 * k1)
        k3 = h * f(x0 + 0.5 * h, y + 0.5 * k2)
        k4 = h * f(x0 + h, y + k3)

        y = y + (1.0 / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4)
        x0 = x0 + h

        print(f"x{i} = {x0:.6f}, y{i} = {y:.6f}")

def main():
    x0 = 0  # Initial conditions
    y0 = 1  # Initial conditions
    x = 2  # Point at which we need the solution
    h = 0.2  # Step size

    runge_kutta(x0, y0, x, h)

if __name__ == "__main__":
    main()