/*************************************************************************
	> File Name: 206_2.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 08 Apr 2024 05:49:21 PM CST
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
    ListNode* reverseList(ListNode* head) {
        ListNode *p = head;
        ListNode *arr[5005] = {0};
        int i = 0;
        while (p) {
            arr[i++] = p;
            p = p->next;
        }
        for (int j = i - 1; j > 0; j--) {
            arr[j]->next = arr[j - 1];
        }
        if (arr[0]) arr[0]->next = nullptr;
        return arr[i - 1];
    }
};


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode new_head, *p;
        p = &new_head;
        new_head.next = nullptr;
        while (head) {
            head->next = p->next;
            p->next = head; 
            head = head->next;
        }
        return head;
    }
};
