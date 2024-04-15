/*************************************************************************
	> File Name: 61.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 08 Apr 2024 06:18:41 PM CST
 ************************************************************************/

#include <./my_include.h>
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
        if (!head || !head->next) return head;
        ListNode now_head, *p = &now_head,*q = head;
        now_head.next = head;
        int n = 0;
        while (++n && q && q->next) q = q->next; 
        q->next = head;
        n = n - (k % n);
        while (p && n--) p = p->next;
        now_head.next = p->next;
        p->next = nullptr;
        return now_head.next;
    }
};
