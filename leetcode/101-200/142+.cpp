/*************************************************************************
	> File Name: 142+.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 22 Jan 2025 05:54:36 PM CST
 ************************************************************************/

#include "./my_include.h"
using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *f = head, *s = head;
        while (f && f->next) {
            f = f->next->next;
            s = s->next;
            if (s == f) {
                ListNode *p = head;
                while (p != s) {
                    p = p->next;
                    s = s->next;
                }
                return p;
            }
        }
        return nullptr;
    }
};
