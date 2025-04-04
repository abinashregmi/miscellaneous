def main():
    # Read the dimension of the system
    n = int(input("Enter Dimension of System of equations: "))
    
    # Read augmented matrix row-wise (each row has n+1 numbers)
    print("Enter coefficients of the augmented Matrix row-wise (each row must have n+1 values):")
    a = []
    for i in range(n):
        row = list(map(float, input(f"Row {i+1}: ").split()))
        if len(row) != n + 1:
            print(f"Error: Row {i+1} must have {n+1} values.")
            return
        a.append(row)
    
    # Perform Gaussian elimination with pivot normalization
    for k in range(n):
        pivot = a[k][k]
        for p in range(n + 1):
            a[k][p] /= pivot
        
        for i in range(n):
            if i != k:
                term = a[i][k]
                for j in range(n + 1):
                    a[i][j] -= a[k][j] * term
    
    # Print the solution (which lies in the last column of the augmented matrix)
    print("Solution:")
    for i in range(n):
        print(f"x{i+1} = {a[i][n]:f}")
    
if __name__ == "__main__":
    main()