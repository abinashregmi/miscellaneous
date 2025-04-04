import math

def f(x):
    return math.exp(-x * x)

# Weights and abscissas for 2-point Gaussian quadrature
w = [1.0, 1.0]
x = [-0.5773502692, 0.5773502692]

def gaussian_integration(a, b):
    integral = 0.0
    midpoint = (a + b) / 2.0
    half_length = (b - a) / 2.0

    for i in range(2):
        integral += w[i] * f(midpoint + half_length * x[i])

    integral *= half_length
    return integral

def main():
    a = -1.0
    b = 1.0
    result = gaussian_integration(a, b)
    print(f"The integral from {a} to {b} is approximately {result}")

if __name__ == "__main__":
    main()