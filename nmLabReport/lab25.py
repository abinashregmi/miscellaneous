def f(x):
    return 1 / (1 + x * x)  # Example function: f(x) = 1 / (1 + x^2)

def composite_simpsons(a, b, n):
    if n % 2 != 0:
        print("n must be even.")
        return -1

    h = (b - a) / n
    sum = f(a) + f(b)

    for i in range(1, n):
        x = a + i * h
        if i % 2 == 0:
            sum += 2 * f(x)
        else:
            sum += 4 * f(x)

    return (h / 3) * sum

def main():
    a = 0  # Lower limit
    b = 1  # Upper limit
    n = 6  # Number of intervals (must be even)

    result = composite_simpsons(a, b, n)
    if result != -1:
        print(f"The integral is: {result}")

if __name__ == "__main__":
    main()