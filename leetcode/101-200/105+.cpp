/*************************************************************************
	> File Name: 105+.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 16 Jan 2025 03:38:50 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


int arr[6005] = {0};
class Solution {
public:
    //前序:p_left代表当前子树根节点, p_right代表当前子树结束位置
    //中序:o_left代表当前子树左区间，o_right代表当前子树的右区间
    TreeNode* buildNewTree(vector<int> &preorder, vector<int> &inorder, int p_left, int p_right, int o_left, int o_right) {
        if (p_left > p_right) return nullptr;
        int o_root = arr[preorder[p_left] + 3000];
        TreeNode *root = new TreeNode(preorder[p_left]);
        int size_left = o_root - o_left;
        //遍历当前节点作为根节点的左子树
        root->left = buildNewTree(preorder, inorder, p_left + 1, p_left + size_left, o_left, o_root - 1);
        //遍历当前节点作为根节点的右子树
        root->right = buildNewTree(preorder, inorder, p_left + size_left + 1, p_right, o_root + 1, o_right);
        return root;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            arr[inorder[i] + 3000] = i;
        }
        return buildNewTree(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};
