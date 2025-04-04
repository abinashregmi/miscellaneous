def f(x):
    return x * x  # Example function: f(x) = x^2

def three_point_formula(x, h):
    return (f(x + h) - f(x - h)) / (2 * h)

def main():
    x = float(input("Enter the point at which to approximate the derivative: "))
    h = float(input("Enter the step size: "))

    derivative = three_point_formula(x, h)

    print(f"The approximate derivative at x = {x:.2f} is {derivative:.5f}")

if __name__ == "__main__":
    main()