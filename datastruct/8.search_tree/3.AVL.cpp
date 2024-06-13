/*************************************************************************
	> File Name: 3.AVL.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 21 May 2024 03:51:45 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#define NIL (&__NIL)
#define H(a) (a->h)
#define L(a) (a->lchild)
#define R(a) (a->rchild)
#define K(a) (a->key)


class Node {
public :
    Node() : key(-1), h(0){}
    Node(int);
    int key, h;
    static Node *insert(Node *, int);
    static void update_height(Node *);
    static Node *bulid_tree(Node *);
    static Node *left_rotate(Node *);
    static Node *right_rotate(Node *);
    static Node *erase(Node *, int);
    static Node *precess(Node *);
    static Node *find(Node *, int);
    static void output(Node *);
    static void clear(Node *);
    Node *lchild, *rchild;
};

Node __NIL;
__attribute__((constructor)) 
void init_NIL() {
    __NIL.lchild = __NIL.rchild = NIL;
    return ;
}

Node::Node(int x = -1) : key(x), lchild(NIL), rchild(NIL), h(1){}

void Node::update_height(Node *root) {
    root->h = max(H(L(root)), H(R(root))) + 1;
    return ;
}

Node *Node::left_rotate(Node *root) {
    Node *new_node = R(root);
    R(root) = L(new_node);
    L(new_node) = root;
    Node::update_height(root);
    Node::update_height(new_node);
    return new_node;
}

Node *Node::right_rotate(Node *root) {
    Node *new_node = L(root);
    L(root) = R(new_node);
    R(new_node) = root;
    Node::update_height(root);
    Node::update_height(new_node);
    return new_node;
}


Node *Node::bulid_tree(Node *root) {
    if (abs(H(L(root)) - H(R(root))) <= 1) return root;
    if (H(L(root)) > H(R(root))) {
        if (H(L(L(root))) < H(L(R(root)))) {
            L(root) = left_rotate(L(root)); 
        }
        root = right_rotate(root);
    } else {
        if (H(R(L(root))) > H(R(R(root)))) {
            R(root) = right_rotate(R(root));
        }
        root = left_rotate(root);
    }
    return root;
}


Node *Node::insert(Node *root, int key) {
    if (root == NIL) return new Node(key);
    if (K(root) == key) return root;
    else if (K(root) < key) R(root) = Node::insert(R(root), key);
    else L(root) = Node::insert(L(root), key);
    Node::update_height(root);
    return bulid_tree(root);
}

Node *Node::precess(Node *root) {
    Node *temp = L(root);
    while (R(temp) != NIL) temp = R(temp);
    return temp;
}

Node *Node::erase(Node *root, int key) {
    if (root == NIL) return root;
    if (K(root) > key) L(root) = Node::erase(L(root), key);
    else if (K(root) < key) R(root) = Node::erase(R(root), key);
    else {
        if (R(root) == NIL && L(root) == NIL) {
            delete root;
            return NIL;
        } else if (R(root) == NIL || L(root) == NIL) {
            Node *temp = (R(root) == NIL) ? L(root) : R(root);
            delete root;
            return temp;
        } else {
            Node *temp = Node::precess(root);
            K(root) = K(temp);
            L(root) = erase(L(root), K(temp));
        }
    }
    update_height(root);
    return bulid_tree(root);
}

Node *Node::find(Node *root, int key) {
    if (root == NIL) return root;
    if (K(root) > key) return find(L(root), key);
    else if (K(root) < key) return find(R(root), key);
    return root;
}

void Node::output(Node *root) {
    if (root == NIL) return ;
    printf("%d( ", K(root));
    Node::output(L(root));
    printf(", ");
    Node::output(R(root));
    printf(")");
    return ;
}

void Node::clear(Node *root) {
    if (root == NIL) return ;
    Node::clear(L(root));
    Node::clear(R(root));
    delete root;
    return ;
}

int main() {
    srand(time(0));
    #define MAX_N 10
    Node *root = NIL;
    for (int i = 0; i < MAX_N; i++) {
        int x = rand() % 100;
        cout << "insert " << x << endl;
        root = Node::insert(root, x);
        Node::output(root);
        putchar(10);
    }
    int x;
    cout << "1 : find" << endl;
    cout << "2 : erase" << endl;
    while (scanf("%d", &x) != EOF) {
        if (x == 1) {
            scanf("%d", &x);
            cout << "find " << (Node::find(root, x))->key << endl;
        } else {
            scanf("%d", &x);
            root = Node::erase(root, x);
            Node::output(root);
        }
        cout << "1 : find" << endl;
        cout << "2 : erase" << endl;
    }
    Node::clear(root);
    return 0;
}
