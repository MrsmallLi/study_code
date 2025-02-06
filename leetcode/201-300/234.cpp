/*************************************************************************
	> File Name: 234.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 16 Jan 2025 09:19:31 PM CST
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


//双指针, 转数组
/*
class Solution {
public:
    vector<int> arr;
    bool isPalindrome(ListNode* head) {
        while (!head) {
            arr.push_back(head->val);
            head = head->next;
        }
        int n = arr.size();
        for (int i = 0, j = n - 1; i <= j; i++, j--) {
            if (arr[i] != arr[j]) return false;
        }
        return true;
    }
};
**/

//递归
class Solution {
public:
    ListNode *p;
    bool fun(ListNode *q) {
        if (q) {
            if (!fun(q->next)) return false;
            if (q->val == p->val) {
                p = p->next;
                return true;
            } 
            return false;
        }
        return true;
    }


    bool isPalindrome(ListNode* head) {
        p = head;
        return fun(head);
    }
};




