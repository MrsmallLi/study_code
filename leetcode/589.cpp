/*************************************************************************
	> File Name: 589.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 19 Apr 2024 06:21:12 PM CST
 ************************************************************************/

#include <./my_include.h>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
 
class Solution {
public:
    vector<int> ans;
    vector<int> preorder(Node* root) {
        if (!root)  return {};
        ans.push_back(root->val);
        for (auto x : root->children) {
            preorder(x);
        }
        return ans;
    }
};
