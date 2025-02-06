/*************************************************************************
	> File Name: 92_3.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 22 Jan 2025 07:55:12 PM CST
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;
        ListNode *n, *l, *r, p;
        p.next = head;
        n = &p;
        int num = 0;
        while (n) {
            if (num == left - 1) l = n;
            if (num == right + 1) {
                r = n;
                break;
            }
            num++;
            if (n) n = n->next;
        }
        n = l;
        l = l->next;
        while (l && l->next != r) {
            ListNode *p = n->next;
            n->next = l->next;
            l->next = l->next->next;
            n->next->next = p;
        }
        return p.next;
    }
};
