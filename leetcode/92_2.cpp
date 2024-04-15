/*************************************************************************
	> File Name: 92.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 10 Apr 2024 10:02:07 AM CST
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head) return head;
        map<int, ListNode *> mp;
        ListNode *p = head;
        ListNode new_head;
        new_head.next = head;
        if (mp.find(right + 1) == mp.end()) mp[right + 1] = nullptr;
        for (int i = 1; p; p = p->next, i++) {
            mp[i] = p;
        }
        p = (left == 1 ? &new_head : mp[left - 1]);
        for (int i = left; i <= right; i++) {
            mp[i]->next = p->next;
            p->next = mp[i];
        }
        mp[left]->next = mp[right + 1];
        return new_head.next;
    }
};

