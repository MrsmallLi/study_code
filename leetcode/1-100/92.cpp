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
    ListNode *re(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *p = re(head->next);
        head->next->next = head;
        head->next = nullptr;
        return p;
    }
        
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head) return head;
        map<int, ListNode *> mp;
        ListNode *p = head;
        for (int i = 1; p; p = p->next, i++) {
            mp[i] = p;
        }
        mp[right]->next = nullptr;
        re(mp[left]);
        if (mp.find(left - 1) != mp.end()) mp[left - 1]->next = mp[right];
        else head = mp[right];
        if (mp.find(right + 1) != mp.end())mp[left]->next = mp[right + 1];
        return head;
    }
};
