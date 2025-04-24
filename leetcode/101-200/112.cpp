/*************************************************************************
	> File Name: 112.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 06 Feb 2025 06:48:45 PM CST
 ************************************************************************/

#include<iostream>
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
    int s;
    bool isTrue(TreeNode *root, int num) {
        if (!root) return false;
        if (root && !root->left && !root->right) return num == s;
        return isTrue(root->left, num + root->val) || isTrue(root->right, num + root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        s = targetSum;
        return isTrue(root, 0);
    }
};
