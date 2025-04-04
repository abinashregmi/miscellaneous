def restoring_division(dividend, divisor):
    # Initialize variables
    n = len(bin(dividend)[2:])  # Number of bits in dividend
    A = 0  # Accumulator
    Q = dividend  # Dividend (Quotient register)
    M = divisor  # Divisor
    steps = []

    for _ in range(n):
        # Left shift A and Q
        A = (A << 1) | (Q >> (n - 1))
        Q = (Q << 1) & ((1 << n) - 1)

        # Subtract M from A
        A = A - M

        # Check if A is negative
        if A < 0:
            Q = Q & ~1  # Set Q[0] to 0
            A = A + M  # Restore A
        else:
            Q = Q | 1  # Set Q[0] to 1

        # Save step for debugging
        steps.append((A, Q))

    return Q, A, steps


# Example usage
if __name__ == "__main__":
    dividend = int(input("Enter dividend: "))
    divisor = int(input("Enter divisor: "))

    if divisor == 0:
        print("Error: Division by zero is not allowed.")
    else:
        quotient, remainder, steps = restoring_division(dividend, divisor)
        print(f"Quotient: {quotient}")
        print(f"Remainder: {remainder}")
        print("\nSteps:")
        for i, (A, Q) in enumerate(steps):
            print(f"Step {i + 1}: A = {A}, Q = {Q}")