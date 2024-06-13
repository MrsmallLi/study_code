/*************************************************************************
	> File Name: 5.red_black.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 31 May 2024 02:39:22 PM CST
 ************************************************************************/

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

//二叉树排序树的基本插入方法
Node *__insert(Node *root, int key) {
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

//找到当前节点的前驱节点
Node *predecessor(Node *root) {
    Node *temp = root->lchild;
    while (temp->rchild != NIL) temp = temp->rchild;
    return temp;
}

Node *erase_maintain(Node *root) {
    //站在父节点来看
    //如果当前节点的左右孩子没有双重黑说明平衡
    if (C(L(root)) != DBLACK && C(R(root)) != DBLACK) return root;
    //如果兄弟节点为红色, 情况4
    if (has_red_node(root)) {
        //最开始的父节点变红色
        root->color = RED;
        if (root->lchild->color == RED) {
            //如果兄弟节点在左,就右旋
            root = right_rotate(root);
            //然后对旋转后双重黑节点的父节点，进行调整
            root->rchild = erase_maintain(root->rchild);
        } else {
            //对称同理
            root = left_rotate(root);
            root->lchild = erase_maintain(root->lchild);
        }
        //最开始的兄弟节点变黑色
        root->color = BLACK;
        return root;
    }
    //情况1,兄弟节点的子孩子都为黑
    //直接将父节点加一重黑
    //父节点的左右孩子减一重黑
    if ((root->lchild->color == DBLACK && !has_red_node(root->rchild)) 
        || (root->rchild->color == DBLACK && !has_red_node(root->lchild))) {
        root->color += 1;
        root->lchild->color -= 1;
        root->rchild->color -= 1;
        return root;
    }
    //判断双重黑在那个子树
    if (root->rchild->color == DBLACK) {
        //直接减一重黑
        root->rchild->color = BLACK;
        //情况3
        //如果不是LL类型，那么就需要进行对兄弟节点的左旋
        //然后不进行节点颜色处理
        if (root->lchild->lchild->color != RED) {
            root->lchild = left_rotate(root->lchild);
        }
        //因为旋转后兄弟节点的颜色要变为父节点的颜色
        root->lchild->color = root->color;
        //然后对于父节点的右旋
        root = right_rotate(root);
    } else {
        //对称同理
        root->lchild->color = BLACK;
        if (root->rchild->rchild->color != RED) {
            root->rchild = right_rotate(root->rchild);
        }
        root->rchild->color = root->color;
        root = left_rotate(root);
    }
    //情况2的统一处理
    //通过旋转后那，当前根节点的左右孩子都要变为黑色
    root->lchild->color = root->rchild->color = BLACK;
    return root;
}

//二叉树排序树的删除操作
Node *__erase(Node *root, int key) {
    if (root == NIL) return root;
    if (key < root->key) {
        root->lchild = __erase(root->lchild, key);
    } else if (key > root->key) {
        root->rchild = __erase(root->rchild, key);
    } else {
        //在这里需要加黑
        if (root->lchild == NIL || root->rchild == NIL) {
            //度为0和1的节点一起处理
            //获取到当前节点的子孩子，如果没有子孩子,那么这里就体现处理NIL虚拟空节点的用处了
            Node *temp = root->lchild == NIL ? root->rchild : root->lchild;
            temp->color += root->color;
            free(root);
            return temp;
        }
        //将删除度为2的节点，变为删除度为0或1的节点进行处理
        Node *temp = predecessor(root);
        root->key = temp->key;
        root->lchild = __erase(root->lchild, temp->key);
    }
    //删除调整平衡
    return erase_maintain(root);
}

//红黑树的删除操作
Node *erase(Node *root, int key) {
    //封装
    root = __erase(root, key);
    //根节点一定是黑色，为了防止双重黑跑到根节点来
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
    int x;
    while (~scanf("%d", &x)) {
        printf("\nerase %d from red black tree\n", x);
        root = erase(root, x);
        output(root);
    }
    return 0;
}
