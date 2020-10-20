def isPowerOfTwo(n: int):
    return n > 0 and str(bin(n)).count('1') == 1

if __name__ == "__main__":
    # Given an integer n, write a function to determine if it is a power of two.

    # Input: n = 16
    # Output: true
    # Explanation: 2^4 = 16

    print(isPowerOfTwo(5))	# False