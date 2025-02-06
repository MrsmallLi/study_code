/*************************************************************************
	> File Name: 25.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 22 Jan 2025 10:42:21 PM CST
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
    ListNode* get_next_node(ListNode *head, int k) {
        while (head && k--) head = head->next;
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode node, *l, *r, *n;
        node.next = head;
        l = &node;
        r = get_next_node(&node, k);
        while (r) {
            n = l->next;
            while (l->next != r) {
                ListNode *p = l->next;
                l->next = n->next;
                n->next = l->next->next;
                l->next->next = p;
            }
            l = get_next_node(l, k);
            r = get_next_node(n, k);
        }
        return node.next;
    }
};
