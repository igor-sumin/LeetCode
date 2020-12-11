#include <iostream>

using namespace std;

/***********************

A peak element is an element that is strictly greater than its neighbors.

Given an integer array nums, find a peak element, and return its index. 
If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞.

Example 1:
Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.

Example 2:
Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.

***********************/

// Эффективный алгоритм
// 
// Двоичный поиск:
// Берем элемент посередине - и выбираем, какую из половин оставить.
// Весь массив содержит пик. Берем элемент в середине
// и оставляем только одну половину - она и содержит пик.
//
// Больше обоих соседей - это пик, можно его выводить
// Если он меньше какого-то соседа, то утверждается, 
// что в направлении этого соседа есть пик.
int findPeakElement(const vector<int>& a) {
	// до пика
	int before = -1;
	// после пика
	int after = (int)a.size();

	// before mid mid+1 after
	while (before + 2 < after) {
		int mid = before + (after - before) / 2;

		if (a[mid] > a[mid + 1]) {
			after = mid + 1;
		} else {
			before = mid;
		}
	}

	return before + 1;

}

int main() {
	cout << findPeakElement({1, 2, 3, 1}) << endl;	// 2

	return 0;
}