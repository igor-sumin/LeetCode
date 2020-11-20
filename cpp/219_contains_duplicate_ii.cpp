#include <iostream>

using namespace std;

/***************************

Given an array of integers and an integer k, 
find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] 
and the absolute difference between i and j is at most k.

Example 1:
Input: nums = [1,2,3,1], k = 3
Output: true

Example 2:
Input: nums = [1,0,1,1], k = 1
Output: true

Example 3:
Input: nums = [1,2,3,1,2,3], k = 2
Output: false

***************************/

bool containsNearbyDuplicate1(const vector<int>& nums, int k) {
    // Наивный алгоритм 
    // O(n^2) по времени, O(1) по памяти
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] == nums[j] && (j - i) <= k) {
                return true;
            }
        }
    }
    
    return false;
}

bool containsNearbyDuplicate2(const vector<int>& nums, int k) {
    // Эффективный алгоритм 
    // Идем слева направо и поддерживаем в unordered_set, какие числа были последние k элементов
    // Встречается новое число - ищем его в set, было ли такое число.
    // Если было - расстояние между этим числом и предыдущим таким же <= k
    // Если не было - добавляем текущее число в set, выкидываем число, которое было k позиций назад
    
    // O(n) по времени, O(k) по памяти

	if (k <= 0) {
		return false;
	}

    unordered_set<int> last;
    for (int i = 0; i < nums.size(); i++) {
        auto it = last.insert(nums[i]);
        
        // новое число
        if (it.second) {
            // поддерживаем k элементов в set
            if (i >= k) {
                last.erase(nums[i - k]);
            }
        } 
        else {
            return true;
        }
    }
    
    return false;
}

int main() {
	cout << containsNearbyDuplicate1({1, 2, 3, 1}, 3) << endl;		// true
	cout << containsNearbyDuplicate2({1, 2, 3, 1}, 3) << endl;		// true

	return 0;
}