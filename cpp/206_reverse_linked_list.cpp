#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* next = NULL;
        ListNode* curr = head;
        
        while (curr) {
            // двигаем next на следующий узел
            next = curr->next;
            // связываем curr с предыдущим узлом
            curr->next = prev;
            
            // двигаем вперед prev и curr
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
};

int main() {
    // Reverse a singly linked list.

    // Example:

    // Input: 1->2->3->4->5->NULL
    // Output: 5->4->3->2->1->NULL
    
    return 0;
}