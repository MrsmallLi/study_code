/*************************************************************************
	> File Name: 24.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 22 Jan 2025 09:33:38 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head) return head;
        ListNode *p = head;
        while (p && p->next) {
            int a = p->val, b = p->next->val;
            p->val = b;
            p->next->val = a;
            p = p->next->next;
        }
        return head;
    }
};
