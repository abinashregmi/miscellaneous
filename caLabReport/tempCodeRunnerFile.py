# Booth's Multiplication Algorithm Implementation

def binary(n, bits):
    """Convert a number to binary with a fixed number of bits."""
    if n < 0:
        n = (1 << bits) + n
    return format(n, f'0{bits}b')

def booth_multiplication(m, r, bits=8):
    """Perform Booth's multiplication on two integers."""
    # Convert inputs to binary
    m_bin = binary(m, bits)
    r_bin = binary(r, bits)
    m_neg = binary(-m, bits)
    
    # Initialize registers
    A = int(m_bin, 2) << bits
    S = int(m_neg, 2) << bits
    P = int(r_bin, 2)
    P = (P << bits) | 0  # Append an extra bit for Q-1
    
    print(f"Initial values: A={binary(A, 2 * bits)}, S={binary(S, 2 * bits)}, P={binary(P, 2 * bits)}")
    
    # Perform Booth's algorithm
    for i in range(bits):
        print(f"Step {i + 1}:")
        if P & 3 == 1:  # Last two bits are 01
            P += A
            print(f"  P = P + A -> {binary(P, 2 * bits)}")
        elif P & 3 == 2:  # Last two bits are 10
            P += S
            print(f"  P = P + S -> {binary(P, 2 * bits)}")
        
        # Arithmetic right shift
        P = (P >> 1) & ((1 << (2 * bits)) - 1)
        print(f"  Arithmetic right shift -> {binary(P, 2 * bits)}")
    
    # Extract the result
    result = P >> bits
    print(f"Final result in binary: {binary(result, bits)}")
    return result

# Example usage
m = 3  # Multiplier
r = -4  # Multiplicand
bits = 5  # Number of bits for representation

print(f"Multiplying {m} and {r} using Booth's Algorithm:")
result = booth_multiplication(m, r, bits)
print(f"Result: {result}")