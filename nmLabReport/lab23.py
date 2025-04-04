def f(x):
    return x * x  # Example function: f(x) = x^2

def trapezoidal(a, b, n):
    h = (b - a) / n
    sum = 0.5 * (f(a) + f(b))
    
    for i in range(1, n):
        sum += f(a + i * h)
    
    return sum * h

def main():
    a = float(input("Enter the lower limit a: "))
    b = float(input("Enter the upper limit b: "))
    n = int(input("Enter the number of subintervals n: "))
    
    result = trapezoidal(a, b, n)
    print(f"The integral is: {result}")

if __name__ == "__main__":
    main()