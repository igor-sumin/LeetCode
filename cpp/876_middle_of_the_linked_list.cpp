#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;

	ListNode(int x) : val(x), next(nullptr) {}
};

// Первый способ
ListNode* middleNode(ListNode* head) {
    // head - adress head node singly linked list
    ListNode* first = head;
    
    // int cnt = 0;
    // while(first != nullptr) {
    //     first = first->next;
    //     cnt++;
    // }
    
    int cnt = 1;
    while(first->next != nullptr) {
        first = first->next;
        cnt++;
    }
    
    int middle = cnt / 2;
    while(middle) {
        head = head->next;
        --middle;
    }
    
    return head;
}

// Второй способ
ListNode* middleNode(ListNode* head) {
    ListNode* a = head;
    ListNode* b = head;

    while(b != nullptr) {
        
        b = b->next;
        if(b == nullptr) {
            return a;
        }

        a = a->next;
        b = b->next;
    }

    return a;
}

int main() {
	ListNode head;
	for(int i = 0; i < 6; i++) {
		head.push_back(i);
	}

	ListNode res = middleNode(head);

	return 0;
}