/*************************************************************************
	> File Name: test1.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 03 May 2024 04:41:31 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Node {
public :
    Node (int n, int win_flag = 1) : n(n), win_flag(win_flag){}
    int n, win_flag;
    vector<Node *> next;
    void output() {
        printf("[%d, %d] : ", n, win_flag);
        for (int i = 0; i < next.size(); i++) {
            i && printf(", ");
                printf("%d", this->next[i]->n);
        }
        cout << endl;
        return ;
    }
};

Node *getNewNode(int n) {
    return new Node(n);
}

Node *getTree(int n) {
    if (n == 1) {
        return getNewNode(n);
    }
    Node *root = getNewNode(n);
    root->next.push_back(getTree(n - 1));
    root->next.push_back(getTree(n - n / 2));
    for (int i = 0; i < root->next.size(); i++) {
        if (!root->next[i]->win_flag) continue;
        root->win_flag = 0;
        break;
    }
    return root;
}

void output_tree(Node *root) {
    if (!root) return ;
    root->output();
    for (int i = 0; i < root->next.size(); i++) output_tree(root->next[i]);
    return ;
}

int main() {
    int n;
    cin >> n;
    Node *root = getTree(n);
    cout << (root->win_flag ? "A win" : "B win" )<< endl;
    return 0;
}
