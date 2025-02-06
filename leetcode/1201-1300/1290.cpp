/*************************************************************************
	> File Name: 1290.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 22 Jan 2025 05:36:26 PM CST
 ************************************************************************/

#include "./my_include.h"
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
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        while (head) {
            ans = ans * 2 + head->val;
            head = head->next;
        }
        return ans;
    }
};
