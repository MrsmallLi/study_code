/*************************************************************************
	> File Name: 102.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 19 Apr 2024 06:55:40 PM CST
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

class Solution1 {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode *> q;
        q.push(root);
        vector<vector<int>> ans;
        while (!q.empty()) {
            vector<int> a;
            int cnt = q.size();
            for (int i = 0; i < cnt; i++) {
                TreeNode *node = q.front();
                a.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                q.pop();
            }
            ans.push_back(a);
        }
        return ans;
    }
};

class Solution {
public :
    void dfs(TreeNode *root, int k, vector<vector<int>> &ans) {
        if (!root) return ;
        if (k == ans.size()) ans.push_back(vector<int>());
        ans[k].push_back(root->val);
        dfs(root->left, k + 1, ans);
        dfs(root->right, k + 1, ans);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> ans;
        dfs(root, 0, ans);
        return ans;
    }
};
