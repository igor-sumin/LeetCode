#include <iostream>
using namespace std;

/*******

Given an array nums with n integers, your task is to check if it could become non-decreasing by modifying at most 1 element.

We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for every i (0-based) such that (0 <= i <= n - 2).

Example 1:
Input: nums = [4,2,3]
Output: true
Explanation: You could modify the first 4 to 1 to get a non-decreasing array.

Example 2:
Input: nums = [4,2,1]
Output: false
Explanation: You can't get a non-decreasing array by modify at most one element.

*******/

bool checkPossibility(const vector<int>& nums) {
    int border = nums.size();
    for (int i = 0; i < nums.size() - 1; i++) {
        if (nums[i] > nums[i + 1]) {
            border = i;
            break;
        } 
    }
    
    if (border == nums.size())
        return true;
    
    for (int i = border + 1; i < nums.size() - 1; i++) {
        if (nums[i] > nums[i + 1]) {
            return false;
        } 
    }
    
    // border + 1 - последний элемент массива
    if (border == 0 || border + 1 == nums.size() - 1) {
        return true;
    }
    
    return nums[border] <= nums[border + 2] || nums[border - 1] <= nums[border + 1];
}

int main() {
	cout << checkPossibility({3, 4, 5, 2, 3}) << endl;		// false

	return 0;
}
