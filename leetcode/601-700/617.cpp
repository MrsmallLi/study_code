/*************************************************************************
	> File Name: 617.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 06 Feb 2025 07:31:57 PM CST
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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1) return root2;
        if (!root2) return root1;
        TreeNode *now = new TreeNode(root1->val + root2->val);
        now->left = mergeTrees(root1->left, root2->left);
        now->right = mergeTrees(root1->right, root2->right);
        return now;
    }

};
