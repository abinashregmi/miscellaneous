def f(x):
    return 1 / (1 + x * x)  # Example: f(x) = 1 / (1 + x^2)

def simpsons_one_third_rule(a, b, n):
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
    a = float(input("Enter the lower limit a: "))
    b = float(input("Enter the upper limit b: "))
    n = int(input("Enter the number of intervals n (must be even): "))

    result = simpsons_one_third_rule(a, b, n)
    if result != -1:
        print(f"The integral is: {result}")

if __name__ == "__main__":
    main()