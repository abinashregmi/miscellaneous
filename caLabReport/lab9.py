def non_restoring_division(dividend, divisor, n):
    # Initialize variables
    A = 0
    Q = dividend
    M = divisor

    # Perform n iterations
    for _ in range(n):
        # Left shift A and Q
        A = (A << 1) | ((Q >> (n - 1)) & 1)
        Q = (Q << 1) & ((1 << n) - 1)

        # Subtract M from A
        A = A - M

        # Check the sign of A
        if A < 0:
            Q = Q & ~1  # Set LSB of Q to 0
            A = A + M  # Restore A
        else:
            Q = Q | 1  # Set LSB of Q to 1

    return Q, A  # Return quotient and remainder


# Example usage
if __name__ == "__main__":
    dividend = int(input("Enter dividend: "))
    divisor = int(input("Enter divisor: "))
    n = int(input("Enter number of bits: "))

    quotient, remainder = non_restoring_division(dividend, divisor, n)
    print(f"Quotient: {quotient}")
    print(f"Remainder: {remainder}")