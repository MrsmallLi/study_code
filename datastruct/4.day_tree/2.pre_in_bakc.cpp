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
    int key, lflag, rflag;
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->lchild = p->rchild;
    p->key = key;
    p->lflag = p->rflag = 0;
    return p;
}

Node *insert(Node *root, int key) {
    if (!root) return getNewNode(key);
    if (rand() % 2) root->lchild = insert(root->lchild, key);
    else root->rchild = insert(root->rchild, key);
    return root;
}

void clear(Node *root) {
    if (root == NULL) return ;
    Node *p = root;
    Node *n = NULL;
    while (p) {
        if (p->rflag) n = p->rchild;
        else break;
        free(p);
        p = n;
    }
    return ;
}

Node *pre = NULL; 
void build_pre(Node *root) {
    if (!root) return ;
    Node *left = root->lchild;
    Node *right = root->rchild;
    if (!root->lflag) {
        root->lchild = pre;
        root->lflag = 1;
    }
    if (pre && !pre->rflag) {
        pre->rchild = root;
        pre->rflag = 1;
    }
    pre = root;
    build_pre(left);
    build_pre(right);
    return ;
}

Node *pre2 = NULL;
void build_in(Node *root) {
    if (!root) return ;
    build_in(root->lchild);
    if (!root->lflag) {
        root->lchild = pre2; 
        root->lflag = 1;
    }
    if (pre2 && !pre2->rflag) {
        pre2->rchild = root;
        pre2->rflag = 1;
    }
    pre2 = root;
    build_in(root->rchild);
    return ;
}


Node *most_left(Node *root) {
    Node *n = root;
    while (n->lchild) n = n->lchild;
    return n;
}

void in_out(Node *root) {
    if (!root) return ;
    Node *p = most_left(root);
    while (p)  {
        printf("%d ", p->key);
        if (p->rflag) p = p->rchild;
        else break;
    }
    cout << endl;
    return ;
}

void pre_out(Node *root) {
    if (!root) return ;
    Node *p = root;
    while (p)  {
        printf("%d ", p->key);
        if (p->rflag) p = p->rchild;
        else break;
    }
    cout << endl;
    return ;
}

void in_orderNode(Node *root) {
    if (!root) return ;
    in_orderNode(root->lchild);
    printf("%d ", root->key);
    in_orderNode(root->rchild);
    return ;
}

void pre_orderNode(Node *root) {
    if (!root) return ;
    printf("%d ", root->key);
    pre_orderNode(root->lchild);
    pre_orderNode(root->rchild);
    return ;
}

void back_orderNode(Node *root) {
    if (!root) return ;
    back_orderNode(root->lchild);
    back_orderNode(root->rchild);
    printf("%d ", root->key);
    return ;
}

Node *pre3 = NULL;
void build_back(Node *root) {
    if (!root)  return ;
    build_back(root->lchild);
    build_back(root->rchild);
    if (!root->lflag) {
        root->lchild = pre3;
        root->lflag = 1;
    }
    if (pre3 && !pre3->rflag) {
        pre3->rchild = root;
        root->rflag = 1;
    }
    pre3 = root;
    return ;
}

void back_out(Node *root) {
    if (!root) return ; 
    Node *p = most_left(root);
    while (p) {
        printf("%d ", p->key);
        if (p->rflag) p = p->rchild;
        else break;
    }
    return ;
}

int main() {
    //srand(time(0));
    Node *root = NULL;
    #define MAX_NODE 10
    for (int i = 0; i < MAX_NODE; i++) {
        root = insert(root, i);
    }
    pre_orderNode(root);
    putchar(10);
    in_orderNode(root);
    putchar(10);
    //build_pre(root);
    //pre_out(root);
    //build_in(root);
    //in_out(root);
    build_back(root);
    back_out(root);
    clear(root);
    return 0;
}
