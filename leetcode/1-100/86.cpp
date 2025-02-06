/*************************************************************************
	> File Name: 86.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 22 Jan 2025 08:56:26 PM CST
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
    ListNode* partition(ListNode* head, int x) {
        ListNode a, b, now_head, *s = &a, *m = &b, *n;
        now_head.next = head;
        n = &now_head;
        while (n && n->next) {
            if (n->next->val < x) {
                s->next = n->next;
                s = s->next;
            } else {
                m->next = n->next;
                m = m->next;
            }
            n->next = n->next->next;
        }
        m->next = nullptr;
        s->next = b.next;
        return a.next;
    }
};
