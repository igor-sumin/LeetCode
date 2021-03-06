#include <bits/stdc++.h>

using namespace std;

int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (target == nums[mid]) {
            return mid;
        } else if (target > nums[mid]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1;
}

int main() {
    // Given a sorted (in ascending order) integer array nums of n elements and a target value, write a function to search target in nums. 
    // If target exists, then return its index, otherwise return -1.

    // Input: nums = [-1,0,3,5,9,12], target = 9
    // Output: 4
    // Explanation: 9 exists in nums and its index is 4

    cout << search({-1, 0, 3, 5, 9, 12}, 9) << endl;    // 4
    return 0;
}