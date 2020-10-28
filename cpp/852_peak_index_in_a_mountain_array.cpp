#include <iostream>

using namespace std;

// Сложность - O(logn)
int peakIndexInMountainArray(const vector<int>& arr) {
    // индекс места, которое строго левее вершины
    int left = 0;
    // индекс места, которое правее вершины
    int right = arr.size() - 1;
    
    while (right - left > 2) {
        // чтобы не возникло переполнения int
        int mid = left + (right - left) / 2;
        
        if (arr[mid] < arr[mid + 1]) {
            // mid левее вершины массива
            left = mid;
        } else {
            // mid правее вершины массива
            right = mid + 1;
        }
    }
    
    return left + 1;
}

int main() {
	// Let's call an array arr a mountain if the following properties hold:
	// 		arr.length >= 3
	// 		There exists some i with 0 < i < arr.length - 1 such that:
	// 			arr[0] < arr[1] < ... arr[i-1] < arr[i]
	// 			arr[i] > arr[i+1] > ... > arr[arr.length - 1]

	// Given an integer array arr that is guaranteed to be a mountain, 
	// return any i such that arr[0] < arr[1] < ... arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].

 	// Example 1:
	// Input: arr = [0,1,0]
	// Output: 1
	
	// Example 2:
	// Input: arr = [0,2,1,0]
	// Output: 1

	// Example 3:
	// Input: arr = [0,10,5,2]
	// Output: 1

	// Example 4:
	// Input: arr = [3,4,5,1]
	// Output: 2


	return 0;
}