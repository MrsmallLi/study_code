/*************************************************************************
	> File Name: 1.binary_search_tree.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 20 May 2024 07:47:17 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define KEY(a) (a ? a->key : -1)

class Node {
public :
    Node() : key(0), r(nullptr), l(nullptr){}
    Node(int key) : key(key), r(nullptr), l(nullptr){}
    static Node *insert(Node *, int);
    static Node *erase(Node *, int);
    static Node *precessNode(Node *);
    static void output(Node *);
    static void oderout(Node *);
    static void clear(Node *);
    int key;
    Node *r, *l;
};

Node *Node::insert(Node *root, int key) {
    if (!root) return new Node(key);
    if (root->key == key) return root;
    else if (root->key < key) root->r = Node::insert(root->r, key);
    else root->l = Node::insert(root->l, key);
    return root;
}

Node *Node::precessNode(Node *root) {
    Node *temp = root->l;
    while (temp->r) temp = temp->r;
    return temp;
}

Node *Node::erase(Node *root, int key) {
    if (!root) return root;
    if (key > root->key) root->r = erase(root->r, key);
    else if (key < root->key) root->l = erase(root->l, key);
    else {
        if (!root->l && !root->r) {
            delete(root);
            return nullptr;
        }
        else if (!root->l || !root->r) {
            Node *temp = root->l ? root->l : root->r;
            delete root;
            return temp;
        }
        else {
            Node *temp = Node::precessNode(root);
            root->key = temp->key;
            root->l = erase(root->l, temp->key);
        }
    }
    return root;
}


void Node::oderout(Node *root) {
    if (!root) return ;
    Node::oderout(root->l);
    printf("%d ", root->key);
    Node::oderout(root->r);
    return ;
}

void Node::output(Node *root) {
    if (!root) return ;
    printf("%d( %d, %d)\n",
          KEY(root), 
          KEY(root->l),
          KEY(root->r)
          );
    Node::output(root->l);
    Node::output(root->r);
    return ;
}

void Node::clear(Node *root) {
    if (!root) return ;
    clear(root->l);
    clear(root->r);
    delete root;
    return ;
}

int main() {
    srand(time(0));
    Node *root = nullptr;
    #define MAX_N 10
    for (int i = 0; i < MAX_N; i++) {
        root = Node::insert(root, rand() % 100);
    }
    Node::output(root);
    Node::oderout(root);
    int x;
    while (~scanf("%d", &x)) {
        if (x == -1) break;
        Node::erase(root, x);
        Node::output(root);
        Node::oderout(root);
    }
    Node::clear(root);
    return 0;
}
