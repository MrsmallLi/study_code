/*************************************************************************
	> File Name: 111.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 06 Feb 2025 05:35:38 PM CST
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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        int min_dep = INT_MAX;
        if (root->left) {
            min_dep = min(minDepth(root->left), min_dep);
        }
        if (root->right) {
            min_dep = min(minDepth(root->right), min_dep);
        }
        return min_dep + 1;
    }
};
