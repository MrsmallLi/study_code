/*************************************************************************
	> File Name: 82.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 22 Jan 2025 10:05:28 PM CST
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode new_node, *n = &new_node;
        n->next = head;
        while (n && n->next) {
            int num = n->next->val;
            int flag = 0;
            if (n->next->next && num == n->next->next->val) flag = 1; 
            while (flag && n->next && num == n->next->val) {
                n->next = n->next->next;
            }
            if (!flag) n = n->next;
        }
        return new_node.next;
    }
};
