/*************************************************************************
	> File Name: 21.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 16 Jan 2025 06:07:34 PM CST
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *q = new ListNode(-1);
        ListNode *head = q;
        while (list1 || list2) {
            if (!list1 || (list2 && list1->val > list2->val)) {
                q->next = list2;
                list2 = list2->next;
            } else {
                q->next = list1;
                list1 = list1->next;
            }
            q = q->next;
        }
        return head->next;
    }
};
