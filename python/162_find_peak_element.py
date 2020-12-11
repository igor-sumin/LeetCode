"""

A peak element is an element that is strictly greater than its neighbors.

Given an integer array nums, find a peak element, and return its index. 
If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞.

"""

def findPeakElement(nums):
    import numpy as np
    
    # 0(n) по времени
    # 0(1) по памяти
    return np.argmax(nums)

if __name__ == '__main__':
    findPeakElement([1, 2, 3, 1])     # 2