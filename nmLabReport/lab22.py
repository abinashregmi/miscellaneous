def trapezoidal_rule(f, a, b, n):
    h = (b - a) / n
    sum = 0.5 * (f(a) + f(b))
    
    for i in range(1, n):
        sum += f(a + i * h)
    
    return sum * h

def function(x):
    # Example function: f(x) = x^2
    return x * x

def main():
    a = 0.0  # Lower limit
    b = 1.0  # Upper limit
    n = 100  # Number of subintervals

    result = trapezoidal_rule(function, a, b, n)
    print(f"The integral is: {result}")

if __name__ == "__main__":
    main()