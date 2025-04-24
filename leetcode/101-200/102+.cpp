/*************************************************************************
	> File Name: 102+.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 06 Feb 2025 03:40:03 PM CST
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> ret;
        queue<TreeNode *> q;
        q.push(root);
        int i = 0;
        while (!q.empty()) {
            vector<int> s;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode *now = q.front();
                q.pop();
                if (now->left) q.push(now->left);
                if (now->right) q.push(now->right);
                s.push_back(now->val);
            }
            ret.push_back(s);
        }
        return ret;
    }
};
