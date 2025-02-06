/*************************************************************************
	> File Name: 141+.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 16 Jan 2025 05:20:01 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <map>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode *, int> mp;
        ListNode *n = head;
        while (n) {
            if (mp[n]) return true;
            mp[n] = 1;
            n = n->next;
        }
        return false;
    }
};
*/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *f = head, *s = head;
        while (f && s) {
            f = f->next;
            s = s->next;
            if (!f) f = f->next;
            else break;
            if (f == s)  return true;
        }
        return false;
    }
};




