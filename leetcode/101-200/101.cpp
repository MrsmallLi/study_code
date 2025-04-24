/*************************************************************************
	> File Name: 101.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 06 Feb 2025 03:25:39 PM CST
 ************************************************************************/

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
    bool isFind(TreeNode *l, TreeNode *r) {
        if (!l && !r) return true;
        if (!l || !r) return false;
        if (l->val != r->val) return false;
        return isFind(l->left, r->right) && isFind(l->right, r->left);
    }
    bool isSymmetric(TreeNode* root) {
        return isFind(root->left, root->right);
    }
};
