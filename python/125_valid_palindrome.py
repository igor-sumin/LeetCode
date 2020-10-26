def isPalindrome(s):
    """
    :type s: str
    :rtype: bool
    """
    s = ''.join([a.lower() for a in s if a.isalnum()])
    return s == s[::-1]

if __name__ == "__main__":
	# Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
	# Note: For the purpose of this problem, we define empty string as valid palindrome.

	# Example 1:
	# Input: "A man, a plan, a canal: Panama"
	# Output: True

	# Example 2:
	# Input: "race a car"
	# Output: False

	print(isPalindrome("A man, a plan, a canal: Panama"))	# True