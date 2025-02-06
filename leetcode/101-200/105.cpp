/*************************************************************************
	> File Name: 105.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 19 Apr 2024 06:35:55 PM CST
 ************************************************************************/

#include <./my_include.h>
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
        if (preorder.size() == 0) return NULL;
        int pos = 0;
        while (inorder[pos] != preorder[0]) pos++;
        TreeNode *root = new TreeNode(preorder[0]);
        vector<int> preArr, inArr;
        for (int i = 1; i <= pos; i++) preArr.push_back(preorder[i]);
        for (int i = 0; i <= pos - 1; i++) inArr.push_back(inorder[i]);
        root->left = buildTree(preArr, inArr);
        preArr.clear();
        inArr.clear();
        for (int i = pos + 1; i < preorder.size(); i++) preArr.push_back(preorder[i]);
        for (int i = pos + 1; i < preorder.size(); i++) inArr.push_back(inorder[i]);
        root->right = buildTree(preArr, inArr);
        return root;
    }
};
