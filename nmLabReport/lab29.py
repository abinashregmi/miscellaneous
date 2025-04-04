def f(x, y):
    return x + y  # Example function

def dfdx(x, y):
    return 1  # Example derivative

def dfdy(x, y):
    return 1  # Example derivative

def taylor_series_method(x0, y0, h, n):
    x = x0
    y = y0
    print(f"x = {x:.6f}, y = {y:.6f}")
    for _ in range(n):
        f_val = f(x, y)
        dfdx_val = dfdx(x, y)
        dfdy_val = dfdy(x, y)
        y = y + h * f_val + (h * h / 2) * (dfdx_val + f_val * dfdy_val)
        x = x + h
        print(f"x = {x:.6f}, y = {y:.6f}")

def main():
    x0 = 0  # Initial x value
    y0 = 1  # Initial y value
    h = 0.1  # Step size
    n = 10  # Number of steps

    taylor_series_method(x0, y0, h, n)

if __name__ == "__main__":
    main()