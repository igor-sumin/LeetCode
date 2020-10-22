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
    
    struct Stat {
        // перестраховались
        long long sum;
        int count;
    };
    
public:
    void visitNode(TreeNode* node, int level, vector<Stat>& levels) {
        if (node == nullptr)
            return;
        
        if (level == levels.size()) {
            levels.push_back(Stat{0, 0});
        }
        
        visitNode(node->left, level + 1, levels);
        visitNode(node->right, level + 1, levels);
        
        levels[level].sum += node->val;
        levels[level].count++;
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        // Выделить все уровни дерева в явном виде - вектор, содержащий набор значений, найти среднее
        // Сложность - O(n) по времени, O(n) по памяти - копируем значения всех узлов дерева
        
        // Про каждый уровень дерева будет своя статистика
        vector<Stat> levels;
        visitNode(root, 0, levels);
        
        vector<double> ans;
        for (int i = 0; i < levels.size(); i++) {
            ans.push_back((double)levels[i].sum / levels[i].count);
        }
        
        return ans;
    }
};

int main(int argc, char const *argv[]) {

    // Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
    // Example 1:
    // Input:
    //     3
    //    / \
    //   9  20
    //     /  \
    //    15   7
    // Output: [3, 14.5, 11]
    // Explanation:
    // The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
    
    return 0;
}