#include <iostream>
#include <vector>
#include <cassert>
#include <numeric>

/*******************************************************

*******************************************************/

int pivotIndex(const std::vector<int>& nums) {
    int left = 0;
    int right = std::accumulate(nums.begin(), nums.end(), 0);

    for (int i = 0; i < nums.size(); i++) {
        right -= nums[i];

        if (left == right) {
            return i;
        }

        left += nums[i];
    }

    return -1;
}

int main() {
    std::cout << pivotIndex({ 1, 7, 3, 6, 5, 6 }) << std::endl;             // 3
    std::cout << pivotIndex({ 2, -1, 1 }) << std::endl;                     // 0
    std::cout << pivotIndex({ 1, 2, 3 }) << std::endl;                      // -1
    std::cout << pivotIndex({ -1, -1, -1, -1, -1, -1 }) << std::endl;       // -1

	return 0;
}
