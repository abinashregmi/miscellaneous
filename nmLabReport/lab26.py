def f(x):
    return 1 / (1 + x * x)  # Example function: f(x) = 1 / (1 + x^2)

def simpsons_38_rule(a, b, n):
    if n % 3 != 0:
        print("n must be a multiple of 3.")
        return -1

    h = (b - a) / n
    sum = f(a) + f(b)

    for i in range(1, n):
        if i % 3 == 0:
            sum += 2 * f(a + i * h)
        else:
            sum += 3 * f(a + i * h)

    return (3 * h / 8) * sum

def main():
    a = float(input("Enter the lower limit a: "))
    b = float(input("Enter the upper limit b: "))
    n = int(input("Enter the number of intervals n (multiple of 3): "))

    result = simpsons_38_rule(a, b, n)
    if result != -1:
        print(f"The integral is: {result}")

if __name__ == "__main__":
    main()