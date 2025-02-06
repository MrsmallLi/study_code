/*************************************************************************
	> File Name: 61+.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 22 Jan 2025 06:47:15 PM CST
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !k) return head;
        ListNode p, *n = &p, *q = head;
        int num = 0;
        while (n->next) {
            ++num; 
            n = n->next; 
        }
        n->next = head;
        num -= (k % num);
        n = &p;
        while (num--) {
            n = n->next; 
        }
        p.next = n->next;
        n->next = nullptr;
        return p.next;
    }
};


