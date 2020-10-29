#include <iostream>

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
    // Dfs reverse in-order - собираемся рекурсивно пройти правыый корень, зате левый.
    // Каждую проходимую вершину записываем в качестве вершины стека
    
    // ссылка на указатель - планируем менять
    void rvs_dfs(TreeNode* node, TreeNode* &res) {
        if (node == nullptr) 
            return;
        
        // Зашли в правое поддерево
        rvs_dfs(node->right, res);
        
        // Заносим node в res
        node->right = res;
        res = node;
        
        // Зашли в левое поддерево
        rvs_dfs(node->left, res);
        
        // Убрали ссылку на левое поддерево
        node->left = nullptr;
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* res = nullptr;
        rvs_dfs(root, res);
        
        return res;
    }
};


int main() {
    // Given a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, 
    // and every node has no left child and only 1 right child.

    // Example 1:
    // Input: [5,3,6,2,4,null,8,1,null,null,null,7,9]

    //        5
    //       / \
    //     3    6
    //    / \    \
    //   2   4    8
    //  /        / \ 
    // 1        7   9

    // Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

    //  1
    //   \
    //    2
    //     \
    //      3
    //       \
    //        4
    //         \
    //          5
    //           \
    //            6
    //             \
    //              7
    //               \
    //                8
    //                 \
    //                  9  

    return 0;
}