/*************************************************************************
	> File Name: 19.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 08 Apr 2024 06:59:59 PM CST
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return head;
        ListNode new_head, *p = &new_head, *q;
        p->next = head;
        q = p;
        while (n--) {
            q = q->next;
        }
        while (q) {
            p = p->next;
            q = q->next;
        }
        if (p) {
            q = p->next;
            p->next = q->next;
        }
        free(q);
        return new_head.next; 
    }
};
