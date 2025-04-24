/*************************************************************************
	> File Name: 235.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 06 Feb 2025 07:18:04 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return root;
        while (root) {
            if (root->val > p->val && root->val > p->val) root = root->left;
            else if (root->val < p->val && root->val < p->val) root = root->right;
            else return root;
        }
    }
};
