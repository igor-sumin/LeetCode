#include <iostream>

using namespace std;

/************************************************************

Given head which is a reference node to a singly-linked list. 
The value of each node in the linked list is either 0 or 1. 
The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.


Example 1:
Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10

Example 2:
Input: head = [0]
Output: 0

Example 3:
Input: head = [1]
Output: 1

Example 4:
Input: head = [1,0,0,1,0,0,1,1,1,0,0,0,0,0,0]
Output: 18880

Example 5:
Input: head = [0,0]
Output: 0

***********************************************************/


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
    ListNode* reverse(ListNode* node) {
        ListNode* next1 = nullptr;
        ListNode* prev = nullptr;
        ListNode* cur = node;
        
        while (cur) {
            // сдвигаем next1 на след узел
            next1 = cur->next;
            // связываем cur с пред узлом
            cur->next = prev;
            
            // двигаем вперед prev, cur
            prev = cur;
            cur = next1;
        }
        
        return prev;
    }
    
    // 1 способ
    int getDecimalValue1(ListNode* head) {
        int res = 0;
        head = reverse(head);
        for (int i = 0; head; i++) {
            if (head->val == 1) {
                res += pow(2, i);
            }
            head = head->next;
        }
        
        return res;
    }
    
    // 2 способ - лучше
    int getDecimalValue2(ListNode* head) {
        // Не будем смещать (портить) head
        ListNode* node = head;
        
        int res = node->val;
        while (node->next) {
            res = (res << 1) | node->next->val;
            node = node->next;
        }
        
        return res;
    }
};

int main() {
	
	return 0;
}