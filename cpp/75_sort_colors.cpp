#include <iostream>
#include <vector>

using namespace std;

/***********************

Given an array nums with n objects colored red, white, or blue, 
sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Follow up:
Could you solve this problem without using the library's sort function?
Could you come up with a one-pass algorithm using only O(1) constant space?

Example 1:
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Example 2:
Input: nums = [2,0,1]
Output: [0,1,2]

***********************/

void sortColors(vector<int>& nums) {
    int next0 = 0;
    int next2 = nums.size() - 1;
    int i = 0;
    
    while (true) {
        if (i > next2)
            break;
        
        if (nums[i] == 0) {
            swap(nums[i], nums[next0]);
            next0++;
            i++;
        } else if (nums[i] == 2) {
            swap(nums[i], nums[next2]);
            next2--;
        } else {
            assert(nums[i] == 1);
            i++;
        }
    }
}

int main() {
    sortColors({2, 0, 1});  // {0, 1, 2}
    return 0;
}