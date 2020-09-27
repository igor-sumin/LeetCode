from collections import Counter

def findDuplicate(nums):
    return Counter(nums).most_common()[0][0]

if __name__ == "__main__":
	# Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
	# There is only one duplicate number in nums, return this duplicate number.
	print(findDuplicate([1, 3, 4, 2, 2]))	# 2