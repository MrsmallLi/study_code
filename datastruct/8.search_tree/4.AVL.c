/*************************************************************************
	> File Name: 4.AVL.c
	> Author: 
	> Mail: 
	> Created Time: Tue 21 May 2024 03:51:50 PM CST
 ************************************************************************/

#include<stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//定义节点
typedef struct Node {
    int key, h;
    struct Node *lchild, *rchild;
} Node;

//定义一个全局变量__NIL，用来表示空节点
Node __NIL;
#define NIL (&__NIL)
#define K(n) (n->key)
#define H(n) (n->h)
#define L(n) (n->lchild)
#define R(n) (n->rchild)
//利用__attribute__((constructor)) 用来设置init_NIL函数先于main主函数执行
//用来初始化NIL节点
//NIL节点用来表示空节点，这是一个编码小技巧
__attribute__((constructor))
void init_NIL() {
    NIL->key = -1;
    NIL->h = 0;
    NIL->lchild = NIL->rchild = NIL;
    return ;
}

//获取新节点的初始化操作
Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->h = 1;
    p->lchild = p->rchild = NIL;
    return p;
}

//更新高度
void update_height(Node *root) {
    //当前节点的高度等于左右子树最高的高度+1
    H(root) = (H(L(root)) > H(R(root)) ? H(L(root)) : H(R(root))) + 1;
    return ;
}

//左旋操作
Node *left_rotate(Node *root) {
    //左旋操作后
    //当前节点的右孩子应该在当前节点的位置
    //让后当前节点变为了，他右孩子的左子树
    //然后当前节点的右孩子的左子树指向了当前节点
    //所以当前节点的右子树应该去指向它之前的右孩子的左子树
    printf("left rotate : %d\n", root->key);
    //创建一个节点用来记录当前节点的右孩子
    Node *new_node = root->rchild;
    //那么当前节点的右子树就可以指向它之前的右孩子的左子树
    root->rchild = new_node->lchild;
    //右孩子的左子树指向了当前节点，那么右孩子就通过左旋操作
    //到了当前节点的位置上了
    //也就完成了左旋操作
    new_node->lchild = root;
    //然后更新当前节点的高度
    update_height(root);
    //更新右孩子的高度
    update_height(new_node);
    //其他节点的高度是没有改变的
    //因为右孩子替代了当前节点的位置
    //那么就返回右孩子
    return new_node;
}

//右旋操作
Node *right_rotate(Node *root) {
    //右旋操作同理反过来思考就可以了
    printf("right rotate : %d\n", root->key);
    Node *new_node = root->lchild;
    root->lchild = new_node->rchild;
    new_node->rchild = root;
    update_height(root);
    update_height(new_node);
    return new_node;
}

const char *type_str[5] = {
    "",
    "maintain type : LL",
    "maintain type : LR",
    "maintain type : RR",
    "maintain type : RL"
};

//平衡操作，也就是判断是LL,RR或者LR和RL类型
//然后再进行左右旋后平衡二叉树
Node *maintain(Node *root) {
    //判断当前子树是否左右子树平衡
    if (abs(H(L(root)) - H(R(root))) <= 1) return root;
    //这里的type只是起了最终演示的效果，用来进行debug和演示的
    int type = 0;
    //判断前面的字母,例如LR中的L
    if (H(L(root)) > H(R(root))) {
        //进入到这里说明是L？类型
        //下面if判断就是是否是LR类型，如果是先进行左旋
        if (H(R(L(root))) > H(L(L(root)))) {
            //说明是LR类型，那么先对当前节点的左子树进行左旋变为LL类型
            //下面会一起对LL类型进行处理
            root->lchild = left_rotate(root->lchild);
            type += 1;
        }
        //因为通过上面的if判断后，如果是LR类型，已经通过左旋变为LL类型
        //如果是LL类型那么上面的if里面的代码段也不会执行
        //所以这里直接右旋处理LL类型，将当前节点进行平衡
        root = right_rotate(root);
        type += 1;
    
    } 
    //这里就是前面字母是R类型了
    else {
        type = 2;
        //if判断是否是RL类型
        if (H(L(R(root))) > H(R(R(root)))) {
            //说明是RL类型，那么先将当前节点的右子树进行右旋
            root->rchild = right_rotate(root->rchild);
            type += 1;
        }
        //对于RR类型处理
        root = left_rotate(root);
        type += 1;
    }
    printf("%s\n", type_str[type]);
    //完成当前节点的平衡操作，返回
    return root;
}

Node *insert(Node *root, int key) {
    //正常的二叉排序节点插入操作
    if (root == NIL) return getNewNode(key);
    if (root->key == key) return root;
    if (key < root->key) root->lchild = insert(root->lchild, key);
    else root->rchild = insert(root->rchild, key);
    //这是一个回溯的过程，所以是从下往上节点进行的下面的操作
    //更新每个节点的高度
    update_height(root);
    //返回平衡后的节点
    return maintain(root);
}

Node *predecessor(Node *root) {
    Node *temp = root->lchild;
    while (temp->rchild != NIL) temp = temp->rchild;
    return temp;
}

Node *erase(Node *root, int key) {
    //删除节点的操作和平衡二叉树一样
    if (root == NIL) return root;
    if (key < root->key) root->lchild = erase(root->lchild, key);
    else if (key > root->key) root->rchild = erase(root->rchild, key);
    else {
        if (root->lchild == NIL || root->rchild == NIL) {
            Node *temp = root->lchild != NIL ? root->lchild : root->rchild;
            free(root);
            return temp;
        } else {
            Node *temp = predecessor(root);
            root->key = temp->key;
            root->lchild = erase(root->lchild, temp->key);
        }
    }
    //然后主要的就是更新高度和平衡操作
    update_height(root);
    return maintain(root);
}

Node *find(Node *root, int key) {
    if (root == NIL) return NIL;
    if (root->key == key) return root;
    if (key < root->key) return find(root->lchild, key);
    return find(root->rchild, key);
}

//清除操作
void clear(Node *root) {
    if (root == NIL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

void output(Node *root) {
    if (root == NIL) return ;
    printf("(%d[%d] | %d, %d)\n", 
        K(root), H(root), 
        K(L(root)), K(R(root))
    );
    output(root->lchild);
    output(root->rchild);
    return ;
}

int main() {
    srand(time(0));
    Node *root = NIL;
    int x;
    // insert
    while (~scanf("%d", &x)) {
        if (x == -1) break;
        printf("insert %d to avl tree\n", x);
        root = insert(root, x);
        output(root);
    }
    // erase
    while (~scanf("%d", &x)) {
        if (x == -1) break;
        printf("erase %d from avl tree\n", x);
        root = erase(root, x);
        output(root);
    }
    // find
    while (~scanf("%d", &x)) {
        if (x == -1) break;
        printf("find %d in avl : %d\n", x, find(root, x) != NIL);
    }
    return 0;
}



