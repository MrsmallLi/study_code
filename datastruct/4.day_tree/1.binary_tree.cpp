/*************************************************************************
	> File Name: 1.binary_tree.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 15 Apr 2024 04:50:46 PM CST
 ************************************************************************/

#include<iostream>
#include <cstdlib>
#include <ctime>
#include <queue>
using namespace std;

typedef struct Node {
    int key;
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->lchild = p->rchild;
    p->key = key;
    return p;
}

Node *insert(Node *root, int key) {
    if (root == NULL) return getNewNode(key);
    if (rand() % 2) root->lchild = insert(root->lchild, key);
    else root->rchild = insert(root->rchild, key);
    return root;
}

void clear(Node *root) {
    if (root == NULL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

void BFS(Node *root) {
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        Node *n = q.front();
        if (n->lchild) q.push(q.front()->lchild);
        if (n->rchild) q.push(q.front()->rchild);
        printf("%d", q.front()->key);
        q.pop();
        if (!q.empty()) printf(", ");
    }
    cout << endl;
    return ;
}
int deput = 1;
Node *DFS(Node *root) {
    if (!root) return root;
    printf("%d deput = %d\n", root->key, deput);
    deput++;
    DFS(root->lchild);
    DFS(root->rchild);
    deput--;
    return root;
}

int main() {
    srand(time(0));
    Node *root = NULL;
    #define MAX_NODE 10
    for (int i = 0; i < MAX_NODE; i++) {
        root = insert(root, rand() % 100);
    }
    BFS(root);
    DFS(root);
    putchar(10);
    clear(root);
    return 0;
}
