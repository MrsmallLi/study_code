/*************************************************************************
	> File Name: 1.binary_search_tree.cpp
	> Author: huguang
	> Mail: hug@haizeix.com
	> Created Time: 
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define KEY(n) (n ? n->key : -1)

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

//和之前学习树时的插入节点是差不多的
//只是多了对二叉排序树性质的判断
Node *insert(Node *root, int key) {
    if (root == NULL) return getNewNode(key);
    //当插入值等于当前节点值时,返回当前节点，说明不用插入该节点
    if (key == root->key) return root;
    //当插入值小于当前节点值时，往左子树递归进行插入
    if (key < root->key) root->lchild = insert(root->lchild, key);
    //当插入值大于当前节点值时，往右子树递归进行插入
    else root->rchild = insert(root->rchild, key);
    return root;
}

//找到删除节点的前驱节点
Node *predecessor(Node *root) {
    Node *temp = root->lchild;
    while (temp->rchild) temp = temp->rchild;
    return temp;
}

Node *erase(Node *root, int key) {
    if (root == NULL) return root;
    //先通过二叉树的性质,递归找到需要删除的节点
    if (key < root->key) root->lchild = erase(root->lchild, key);
    else if (key > root->key) root->rchild = erase(root->rchild, key);
    //找到需要删除的节点
    else {
        //度为0的节点删除
        if (root->lchild == NULL && root->rchild == NULL) {
            free(root);
            return NULL;
        } 
        //度为1的节点删除
        else if (root->lchild == NULL || root->rchild == NULL) {
            //先通过一个变量记录删除节点的左子树或者右子树
            Node *temp = root->lchild ? root->lchild : root->rchild;
            //删除节点
            free(root);
            //然后将删除节点的左子树或右子树接上
            return temp;
        } 
        //度为2的节点删除
        else {
            //这里是用的是找前驱节点
            Node *temp = predecessor(root);
            //直接把删除节点的值用前驱节点的值覆盖掉
            root->key = temp->key;
            //然后通过递归调用去删除前驱节点
            root->lchild = erase(root->lchild, key);
        }
    }
    return root;
}

void clear(Node *root) {
    if (root == NULL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

void output(Node *root) {
    if (root == NULL) return ;
    printf("(%d ; %d, %d)\n", 
        KEY(root), 
        KEY(root->lchild),
        KEY(root->rchild)
    );
    output(root->lchild);
    output(root->rchild);
    return ;
}

void in_order(Node *root) {
    if (root == NULL) return ;
    in_order(root->lchild);
    printf("%d ", root->key);
    in_order(root->rchild);
    return ;
}

int main() {
    srand(time(0));
    #define MAX_OP 10
    Node *root = NULL;
    for (int i = 0; i < MAX_OP; i++) {
        int key = rand() % 100;
        printf("insert key %d to BST\n", key);
        root = insert(root, key);
    }
    output(root);
    printf("in order : ");
    in_order(root);
    printf("\n");
    

    int x;
    while (~scanf("%d", &x)) {
        printf("erase %d from BST\n", x);
        root = erase(root, x);
        in_order(root); printf("\n");
    }
    return 0;

}
