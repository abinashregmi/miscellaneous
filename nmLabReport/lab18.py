import math

def forward_difference(func, x, h):
    return (func(x + h) - func(x)) / h

def func(x):
    return math.sin(x)  # Example function, you can change it to any other function

def main():
    angle = float(input("Enter the angle in radians: "))
    increment = float(input("Enter the increment: "))

    # Convert angle from degrees to radians
    angle = angle * math.pi / 180.0

    derivative = forward_difference(func, angle, increment)

    print(f"The derivative at angle {angle:.2f} with increment {increment:.2f} is {derivative:.5f}")

if __name__ == "__main__":
    main()