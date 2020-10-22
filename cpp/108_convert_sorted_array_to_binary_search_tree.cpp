#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* BST(const vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        
        int mid = (left + right) / 2;
        // Средний элемент делаем корнем
        TreeNode *root = new TreeNode(nums[mid]);
        // Все, что находится до этого элемента заносим в левое поддерево
        root->left = BST(nums, left, mid - 1);
        // Все, что находится после этого элемента заносим в правое поддерево
        root->right = BST(nums, mid + 1, right);
        
        return root;
        
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return BST(nums, 0, nums.size() - 1);
    }
};

int main() {
	// Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
	// For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

	// Example:
	// Given the sorted array: [-10,-3,0,5,9],
	// One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:
	//       0
	//      / \
	//    -3   9
	//    /   /
	//  -10  5
	 
	return 0;
}