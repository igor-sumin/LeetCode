class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        return sum(1 for x in nums if len(str(x)) % 2 == 0)

# # description:
# Given an array nums of integers, return how many of them contain an even number of digits.
# Input: nums = [12, 345, 2, 6, 7896]
# Output: 2
# Therefore only 12 and 7896 contain an even number of digits.