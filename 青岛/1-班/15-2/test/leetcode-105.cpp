/*************************************************************************
	> File Name: leetcode-105.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 14 Feb 2025 10:59:47 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <cstdlib>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int o_root_ind = 0;
        while (preorder[0] != inorder[o_root_ind]) o_root_ind++;
        TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode) * 1);
        //分别找到前序遍历和中序遍历中对应数组中的数字，并把他们放在新数组中
        vector<int> pre, in;
        for (int i = 0; i < o_root_ind; i++) in.push_back(inorder[i]);
        for (int i = 1; i < o_root_ind + 1; i++) pre.push_back(preorder[i]);
        root->left = buildTree(pre, in);
        pre.clear();
        in.clear();
        for (int i = o_root_ind + 1; i < inorder.size(); i++) in.push_back(inorder[i]);
        for (int i = o_root_ind + 1; i < preorder.size(); i++) pre.push_back(preorder[i]);
        root->right = buildTree(pre, in);
        return root;
    }
};
