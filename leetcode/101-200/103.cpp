/*************************************************************************
	> File Name: 103.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 06 Feb 2025 05:10:13 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


#include "./my_include.h"
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> ret;
        deque<TreeNode *> q;
        q.push_back(root);
        int flag = 1;
        while(!q.empty()) {
            vector<int> s;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode *now;
                if (flag) {
                    now = q.front();
                    q.pop_front();
                    s.push_back(now->val);
                    if (now->left) q.push_back(now->left);
                    if (now->right) q.push_back(now->right);
                } else {
                    now = q.back();
                    q.pop_back();
                    s.push_back(now->val);
                    if (now->right) q.push_front(now->right);
                    if (now->left) q.push_front(now->left);
                }
            }
            ret.push_back(s);
            flag ^= 1;
        }
        return ret;
    }
};
