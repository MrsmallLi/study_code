/*************************************************************************
	> File Name: 141.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 08 Apr 2024 06:04:42 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *f = head, *s = head;        
        while (f && f->next) {
            s = s->next;
            f = f->next->next;
            if (s == f) return true;
        }
        return false;
    }
};
