/*************************************************************************
	> File Name: 3.serialize_deserialize.c
	> Author: 
	> Mail: 
	> Created Time: Fri 19 Apr 2024 01:33:45 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Node {
    int key;
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->lchild = p->rchild = NULL;
    return p;
}
//插入节点
Node *insert(Node *root, int key) {
    if (!root) return getNewNode(key);
    if (rand() % 2) root->lchild = insert(root->lchild, key);
    else root->rchild = insert(root->rchild, key);
    return root;
}

//随机生成二叉树函数
Node *getRandomBinaryTree(int n) {
    Node *root = NULL;
    for (int i = 0; i < n; i++) {
        root = insert(root, rand() % 100);
    }
    return root;
}


void clear(Node *root) {
    if (!root) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

char buff[1000];
int len = 0;
//二叉树转广义表
//二叉树转广义表和前序遍历差不多
//所以可以按着前序遍历进行处理
void __serialize(Node *root) {
    if (!root) return ;
    //处理根节点，先将根节点进行表示
    len += sprintf(buff + len, "%d", root->key);
    //然后判断当前节点是否还有左右子树
    if (!root->lchild && !root->rchild) return ;
    //到了这里说明有左子树或者有右子树
    //那么就需要括号，先输入进左括号
    len += sprintf(buff + len, "(");
    //递归左子树
    __serialize(root->lchild);
    //判断是否有右子树
    if (root->rchild) {
        //有右子树就需要 ‘,‘来隔开进行表示右子树
        len += sprintf(buff + len, ", ");
        __serialize(root->rchild);
    }
    //最后说明当前左右子树递归完成，用右）进行包起来
    len += sprintf(buff + len, ")");
    return ;
}

void pre_out(Node *root) {
    if (!root) return ;
    printf("%d ", root->key);
    pre_out(root->lchild);
    pre_out(root->rchild);
    return ;
}

void serialize(Node *root) {
    memset(buff, 0, sizeof(buff));
    len = 0;
    __serialize(root);
    return ;
}

int main() {
    srand(time(0));
    #define MAX_NODE 10
    Node *root = getRandomBinaryTree(MAX_NODE);
    serialize(root);
    printf("%s\n", buff);
    pre_out(root);
    putchar(10);
    return 0;
}
