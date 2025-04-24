/*************************************************************************
	> File Name: 226.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 06 Feb 2025 07:15:33 PM CST
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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        TreeNode *l = root->left;
        root->left = root->right;
        root->right = l;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
