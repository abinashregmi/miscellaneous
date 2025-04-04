def newton_forward_difference(x, y, n, value):
    h = x[1] - x[0]
    diff_table = [[0 for _ in range(n)] for _ in range(n)]

    # Initialize the difference table
    for i in range(n):
        diff_table[i][0] = y[i]

    # Calculate the forward differences
    for j in range(1, n):
        for i in range(n - j):
            diff_table[i][j] = diff_table[i + 1][j - 1] - diff_table[i][j - 1]

    # Calculate the derivative using Newton's Forward Difference formula
    derivative = diff_table[0][1] / h

    print(f"The derivative at x = {value:.2f} is {derivative:.2f}")

def main():
    n = int(input("Enter the number of data points: "))
    x = []
    y = []

    print("Enter the data points (x and y):")
    for i in range(n):
        x.append(float(input(f"x[{i}] = ")))
        y.append(float(input(f"y[{i}] = ")))

    value = float(input("Enter the value of x at which the derivative is to be calculated: "))

    newton_forward_difference(x, y, n, value)

if __name__ == "__main__":
    main()