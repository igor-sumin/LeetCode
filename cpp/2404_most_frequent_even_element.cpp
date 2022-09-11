#include <iostream>
#include <vector>
#include <map>

/*******************************************************

Given an integer array nums, return the most frequent even element.

If there is a tie, return the smallest one. If there is no such element, return -1.

Example 1:
Input: nums = [0,1,2,2,4,4,1]
Output: 2
Explanation:
The even elements are 0, 2, and 4. Of these, 2 and 4 appear the most.
We return the smallest one, which is 2.

Example 2:
Input: nums = [4,4,4,9,2,4]
Output: 4
Explanation: 4 is the even element appears the most.

Example 3:
Input: nums = [29,47,21,41,13,37,25,7]
Output: -1
Explanation: There is no even element.

*******************************************************/

int mostFrequentEven(std::vector<int>& nums) {
    std::map<int, int> evens;

    for (const auto& num : nums) {
        evens[num]++;
    }

    int res = -1;
    int freqEven = -1;
    for (const auto& [key, value] : evens) {
        if (key % 2 == 0 && freqEven < value) {
            freqEven = value;
            res = key;
        }
    }

    return res;
}

int main() {
    std::vector<std::vector<int>> nums = { 
        {0, 1, 2, 2, 4, 4, 1},
        {4, 4, 4, 9, 2, 4},
        {29, 47, 21, 41, 13, 37, 25, 7}
    };
    std::vector<int> answers = { 2, 4, -1 };

    for (int i = 0; i < nums.size(); i++) {
        std::cout << (mostFrequentEven(nums[i]) == answers[i] ? "YES" : "NO") << std::endl;
    }

	return 0;
}
