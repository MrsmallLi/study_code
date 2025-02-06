/*************************************************************************
	> File Name: 83.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 22 Jan 2025 05:47:05 PM CST
 ************************************************************************/

#include "./my_include.h"
#include <cstring>
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
    int num[205];
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *n = new ListNode(-1, head);
        memset(num, 0, sizeof(int) * 205);
        while (n && n->next) {
            if (!num[n->next->val + 100]) {
                num[n->next->val + 100] = 1;
                n = n->next;
            } else {
                n->next = n->next->next;
            }
        }
        return head;
    }
};
