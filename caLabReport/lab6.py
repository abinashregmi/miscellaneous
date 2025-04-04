# Function to perform 4-bit binary addition
def binary_addition_4bit(a, b):
    # Ensure inputs are 4-bit binary strings
    if len(a) != 4 or len(b) != 4 or not all(bit in '01' for bit in a+b):
        raise ValueError("Inputs must be 4-bit binary strings.")

    # Convert binary strings to integers
    num1 = int(a, 2)
    num2 = int(b, 2)

    # Perform addition
    result = num1 + num2

    # Convert result back to binary and ensure it's 4 bits
    result_binary = bin(result)[2:]  # Remove '0b' prefix
    if len(result_binary) > 4:
        result_binary = result_binary[-4:]  # Take the last 4 bits (overflow handling)

    return result_binary

# Example usage
if __name__ == "__main__":
    binary1 = input("Enter the first 4-bit binary number: ")
    binary2 = input("Enter the second 4-bit binary number: ")

    try:
        result = binary_addition_4bit(binary1, binary2)
        print(f"The 4-bit binary addition result is: {result}")
    except ValueError as e:
        print(e)  # Function to perform 4-bit binary addition
def binary_addition_4bit(a, b):
    # Ensure inputs are 4-bit binary strings
    if len(a) != 4 or len(b) != 4 or not all(bit in '01' for bit in a+b):
        raise ValueError("Inputs must be 4-bit binary strings.")

    # Convert binary strings to integers
    num1 = int(a, 2)
    num2 = int(b, 2)

    # Perform addition
    result = num1 + num2

    # Convert result back to binary and ensure it's 4 bits
    result_binary = bin(result)[2:]  # Remove '0b' prefix
    if len(result_binary) > 4:
        result_binary = result_binary[-4:]  # Take the last 4 bits (overflow handling)

    return result_binary

# Example usage
if __name__ == "__main__":
    binary1 = input("Enter the first 4-bit binary number: ")
    binary2 = input("Enter the second 4-bit binary number: ")

    try:
        result = binary_addition_4bit(binary1, binary2)
        print(f"The 4-bit binary addition result is: {result}")
    except ValueError as e:
        print(e)  