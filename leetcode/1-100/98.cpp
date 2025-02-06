/*************************************************************************
	> File Name: 98.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 04 Feb 2025 07:13:01 PM CST
 ************************************************************************/

#include <iostream>
#include <cinttypes>
#include <climits>
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
    bool isValid(TreeNode *root, long long max_num, long long min_num) {
        if (!root) return true;
        if (root->val >= max_num || root->val <= min_num) return false;
        return isValid(root->left, root->val, min_num) && isValid(root->right, max_num, root->val);
    }
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        return isValid(root, INT64_MAX, INT64_MIN);
    }
};
