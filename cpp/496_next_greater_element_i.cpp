#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>


using namespace std;

/***********************

You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2. 
Find all the next greater numbers for nums1's elements in the corresponding places of nums2.

The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not exist, output -1 for this number.

Example 1:
Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
Output: [-1,3,-1]
Explanation:
    For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
    For number 1 in the first array, the next greater number for it in the second array is 3.
    For number 2 in the first array, there is no next greater number for it in the second array, so output -1.

Example 2:
Input: nums1 = [2,4], nums2 = [1,2,3,4].
Output: [3,-1]
Explanation:
    For number 2 in the first array, the next greater number for it in the second array is 3.
    For number 4 in the first array, there is no next greater number for it in the second array, so output -1.

***********************/

// 1 способ - наивный O(size1 * size2)
vector<int> nextGreaterElement1(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res;
    for (int i = 0; i < nums1.size(); i++) {
        bool flag = true;
        int greater = -1;
        
        for (int j = 0; j < nums2.size(); j++) {
            if (nums2[j] == nums1[i]) {
                flag = false;
            }
            
            if (!flag && nums2[j] > nums1[i]) {
                greater = nums2[j];
                break;
            }
        }
        
        res.push_back(greater);
    }
    
    return res;
}
    
// 2 способ - (гораздо лучше) использование стека и unordered_map - O(size1 + size2)
vector<int> nextGreaterElement2(const vector<int>& nums1, const vector<int>& nums2) {
    // Пойдем по второму массиву от конца к началу
    // и за O(size2) найдем для каждого элемента ближайший справа бОльший
    
    // Кидаем в стек числа, которые могут быть бОльшими для каких-то других чисел
    
    // unordered_map: ключ - элемент nums2, для которого находим бОльший элемент,
    //                значение - какой ответ для этого элемента - ближайший справа бОльший
    
    // Перенастраиваем stack так, чтобы он использовал vector<int>, следовательно
    // количество выделений динамической памяти будет меньше - это выгодно
    stack<int, vector<int>> greater;
    // unordered_map - не гарантированный O(1) на операцию - снижает сложность
    // map           - гарантированный O(logn) на операцию
    unordered_map<int, int> numToAns;
    for (int i = (int)nums2.size() - 1; i >= 0; i--) {
        while (!greater.empty() && greater.top() < nums2[i]) {
            greater.pop();
        }
        
        if (!greater.empty()) {
            numToAns[nums2[i]] = greater.top();
        } else {
            numToAns[nums2[i]] = -1;
        }
        
        greater.push(nums2[i]);
    }
    
    vector<int> res(nums1.size());
    for (int i = 0; i < (int)nums1.size(); i++) {
        res[i] = numToAns[nums1[i]];
    }
    
    return res;
}

int main() {
    cout << nextGreaterElement1({4, 1, 2}, {1, 3, 4, 2}) << endl;      // {-1, 3, -1} за 24ms
    cout << nextGreaterElement2({4, 1, 2}, {1, 3, 4, 2}) << endl;      // {-1, 3, -1} за 12ms

    return 0;
}