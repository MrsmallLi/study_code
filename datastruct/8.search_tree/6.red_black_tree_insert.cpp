/*************************************************************************
	> File Name: 6.red_black_tree_insert.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 31 May 2024 06:37:54 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED    0
#define BLACK  1
#define DBLACK 2
#define NIL (&__NIL)
#define K(n) (n->key)
#define L(n) (n->lchild)
#define R(n) (n->rchild)
#define C(n) (n->color)

typedef struct Node {
    int key, color; // 0 red, 1 black, 2 double black
    struct Node *lchild, *rchild;
} Node;

Node __NIL;

__attribute__((constructor))
void init_NIL() {
    NIL->key   = -1;
    NIL->color = BLACK;
    NIL->lchild = NIL->rchild = NIL;
    return ;
}

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key   = key;
    p->color = RED;
    p->lchild = p->rchild = NIL;
    return p;
}

//判断当前节点的左右孩子是否有红色
bool has_red_node(Node *root) {
    return root->lchild->color == RED || root->rchild->color == RED;
}

//左旋操作
Node *left_rotate(Node *root) {
    Node *new_root = root->rchild;
    root->rchild = new_root->lchild;
    new_root->lchild = root;
    return new_root;
}

//右旋操作
Node *right_rotate(Node *root) {
    Node *new_root = root->lchild;
    root->lchild = new_root->rchild;
    new_root->rchild = root;
    return new_root;
}

//平衡操作
Node *insert_maintain(Node *root) {
    int flag = 0;
    //站在祖父节点来看
    //判断是在左子树还是右子树失衡
    //左子树失衡flag = 1
    if (C(L(root)) == RED && has_red_node(L(root))) flag = 1;
    //右子树失衡flag = 2
    if (C(R(root)) == RED && has_red_node(R(root))) flag = 2;
    if (flag == 0) return root;
    //如果当前祖父节点的左右孩子都为红色
    //那么就是情况1,也就是父节点和叔叔节点都是红色的情况
    if (C(L(root)) == RED && C(R(root)) == RED) goto red_up_maintain;
    //这里就是L类型
    if (flag == 1) {
        //判断是否是LR类型
        if (C(R(L(root))) == RED) {
            L(root) = left_rotate(L(root));
        }
        root = right_rotate(root);
    } 
    //这里就是R类型
    else {
        //判断是否是RL类型
        if (C(L(R(root))) == RED) {
            R(root) = right_rotate(R(root));
        }
        root = left_rotate(root);
    }
red_up_maintain:
    //通过旋转或者判断之后
    //现在子树最顶上的三个节点进行修改颜色
    C(root) = RED;
    C(L(root)) = C(R(root)) = BLACK;
    return root;
}

Node *__insert(Node *root, int key) {
    //二叉树排序树的基本插入方法
    if (root == NIL) return getNewNode(key);
    if (root->key == key) return root;
    if (key < root->key) root->lchild = __insert(root->lchild, key);
    else root->rchild = __insert(root->rchild, key);
    //最后返回平衡后的根节点
    return insert_maintain(root);
}

//红黑树的插入方法
Node *insert(Node *root, int key) {
    //封装
    root = __insert(root, key);
    //性质2根节点一定是黑色
    root->color = BLACK;
    return root;
}

void clear(Node *root) {
    if (root == NIL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

void output(Node *root) {
    if (root == NIL) return ;
    printf("(%d| %d; %d, %d)\n", 
        C(root), K(root),
        K(L(root)), K(R(root))
    );
    output(root->lchild);
    output(root->rchild);
    return ;
}

int main() {
    srand(time(0));
    #define MAX_N 10
    Node *root = NIL;
    for (int i = 0; i < MAX_N; i++) {
        int x = rand() % 100;
        printf("\ninsert %d to red black tree : \n", x);
        root = insert(root, x);
        output(root);
    }
    return 0;
}
