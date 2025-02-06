/*************************************************************************
	> File Name: 203.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 16 Jan 2025 08:54:02 PM CST
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
    ListNode* fun(ListNode *head, int val) {
        if (!head) return head;
        if (head->next && head->next->val == val) {
            head->next = head->next->next;
            fun(head, val);
        } else {
            fun(head->next, val);
        }
        return head; 
    }
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return head;
        ListNode *l = new ListNode(-1);
        l->next = head;
        fun(l, val);
        return l->next;
    }
};
