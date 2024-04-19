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

#define MAX_NODE 10

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
        len += sprintf(buff + len, ",");
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

Node *deserialize(char *buff, int n) {
    //创建栈进行辅助操作
    Node **arr = (Node **)malloc(sizeof(Node *) * MAX_NODE);
    //scode表示用来表示当前执行流程
    //flag 0 表示当前处理左子树，1表示处理右子树
    int top = -1, flag = 0, scode = 0;
    Node *p = NULL, *root = NULL;
    for (int i = 0; buff[i]; i++) {
        switch(scode) {
            case 0:  {
                //当前位置为数字时设置为状态1，处理新节点
                if (buff[i] >= '0' && buff[i] <= '9') scode = 1;
                //当前位置为左括号时设置为状态2,入栈当前位置的根节点,修改标记为左子树
                else if (buff[i] == '(') scode = 2;
                //为逗号时设置状态3,标记当前为右子树
                else if (buff[i] == ',') scode = 3;
                //为右括号设置状态4，弹栈
                else scode = 4;
                //因为0状态没有对当前字符做任何处理所以需要回溯循环
                i -= 1;
            } break;
            case 1:  {
                int num = 0;
                while (buff[i] <= '9' && buff[i] >= '0') {
                    num = num * 10 + (buff[i] - '0');
                    i += 1;
                }
                p = getNewNode(num);
                if (top >= 0 && flag == 0) arr[top]->lchild = p;
                if (top >= 0 && flag == 1) arr[top]->rchild = p;
                i--;
                scode = 0;
            } break; 
            case 2: {
                arr[++top] = p;
                flag = 0;
                scode = 0;
            } break;
            case 3: {
                flag = 1; 
                scode = 0;
            } break;
            case 4: {
                root = arr[top--];
                scode = 0;
            } break;
        }
    }

    return p;
}

int main() {
    srand(time(0));
    Node *root = getRandomBinaryTree(MAX_NODE);
    serialize(root);
    printf("%s\n", buff);
    pre_out(root);
    putchar(10);
    Node *new_root = deserialize(buff, len);
    pre_out(root);
    putchar(10);
    return 0;
}
