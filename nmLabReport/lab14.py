import math

def main():
    # Read the dimension of the system of equations
    n = int(input("Enter Dimension of System of equations: "))
    
    # Read the coefficient matrix row-wise
    print("Enter coefficients of the matrix row-wise:")
    a = []  # will be a list of lists (matrix)
    for i in range(n):
        # Expect n coefficients for each row
        row = list(map(float, input(f"Row {i+1} (enter {n} values separated by spaces): ").split()))
        if len(row) != n:
            print("Error: Incorrect number of coefficients.")
            return
        a.append(row)
    
    # Read the RHS vector
    b = list(map(float, input("Enter RHS vector (enter values separated by spaces): ").split()))
    if len(b) != n:
        print("Error: Incorrect number of RHS values.")
        return
    
    # Forward elimination to convert matrix to upper triangular form
    for k in range(n):
        pivot = a[k][k]
        if abs(pivot) < 0.000001:
            print("Method failed: pivot too small")
            return
        for i in range(k + 1, n):
            term = a[i][k] / pivot
            for j in range(n):
                a[i][j] = a[i][j] - a[k][j] * term
            b[i] = b[i] - b[k] * term
    
    # Back substitution to solve for x
    x = [0] * n
    x[n - 1] = b[n - 1] / a[n - 1][n - 1]
    for i in range(n - 2, -1, -1):
        sum_val = 0
        for j in range(i + 1, n):
            sum_val += a[i][j] * x[j]
        x[i] = (b[i] - sum_val) / a[i][i]
    
    # Display the solution
    print("Solution:")
    for i in range(n):
        print(f"x{i+1} = {x[i]:f}", end="\t")
    print()

if __name__ == "__main__":
    main()