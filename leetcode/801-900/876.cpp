/*************************************************************************
	> File Name: 876.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 16 Jan 2025 09:52:08 PM CST
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
/**
//哈希表
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (!head) return head;
        map<int, ListNode *> mp;
        int n = 1;
        while (head) {
            mp[n++] = head;
            head = head->next;
        }
        return mp[(n - 1) / 2 + 1];
    }
};
**/

//快慢指针
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *f = head;
        ListNode *s = head;
        while (f && f->next) {
            s = s->next;
            f = f->next;
        }
        return s;
    }
};


