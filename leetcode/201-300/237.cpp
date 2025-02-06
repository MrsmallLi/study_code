/*************************************************************************
	> File Name: 237.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 22 Jan 2025 09:30:13 PM CST
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
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
        return ;
    }
};
