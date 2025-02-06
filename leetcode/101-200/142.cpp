/*************************************************************************
	> File Name: 142.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 10 Apr 2024 09:36:04 AM CST
 ************************************************************************/

#include <./my_include.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next)  return 0;
        ListNode *f = head, *s = head;
        while (f && f->next) {
            f = f->next->next; 
            s = s->next;
            if (s == f) break;
        }
        if (f == NULL || f->next == NULL) return NULL;
        f = head;
        while (s != f) {
            f = f->next;
            s = s->next;
        }
        return s;
    }
};
