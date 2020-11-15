#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

#include <iostream>
using namespace std;

/*******************

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:
Input: [0,1,0,3,12]
Output: [1,3,12,0,0]

*******************/

// 1 способ
void moveZeroes(vector<int>& nums) {
	int nxt = 0;
	for(auto s : nums) {
		if(s != 0) {
			nums[nxt] = s;
			nxt++;
		}
	}

	for(int i = nxt; i < nums.size(); i++) {
		nums[i] = 0;
	}
}

// 2 способ - итерационный STD
void moveZeroes2(vector<int>& nums) {
    // Переупорядочивает элементы в диапазоне [first, last) таким образом, 
    // чтобы все элементы, для которых предикат p возвращает true, предшествовали элементам, 
    // для которых предикат p возвращает false. Относительный порядок элементов сохраняется.
    stable_partition(nums.begin(), nums.end(), [](int p) {
        return p;
    });
}

int main() {
	vector<int> nums = {0, 1, 0, 3, 1, 2};
	moveZeroes2(nums);
	return 0;
}