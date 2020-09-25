class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        # nums:   4  5  1  8   2
        # left:   1  4 20 20 180
        # right: 80 16 16  2   1
        
        # res = left[i] * right[i]
        
        res = [1] * len(nums)
        for i in range(1, len(nums)):
            res[i] = res[i - 1] * nums[i - 1]
            
        temp = 1
        for i in range(len(nums) - 2, -1, -1):
            temp *= nums[i + 1]
            res[i] *= temp
        return res
        
# # main()
# Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

# Example:
# Input:  [1,2,3,4]
# Output: [24,12,8,6]

# Note: Please solve it without division and in O(n).

# Follow up:
# Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)