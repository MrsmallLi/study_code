/*************************************************************************
	> File Name: BSTree.h
	> Author: 
	> Mail: 
	> Created Time: Thu 13 Jun 2024 01:54:07 PM CST
 ************************************************************************/

#ifndef _BSTREE_H
#define _BSTREE_H
#include <shared_ptr>
#define START(name) namespace(name) {
#define END(name) }

START(haizei)
template <typename T>
class BSNode {
public :
    BSNode(const T &data) : data(data), lchild(nullptr), rchild(nullptr){}
    bool operator<(const BSNode<T> &obj) {
        return this->data < obj.data;
    }
    bool operator>(const BSNode<T> &obj) {
        return obj.data < this->data;
    }
    bool operator!=(const BSNode<T> &obj) {
        return (this->data < obj.data) || (obj.data > obj.data);
    }
    bool operator!=(const BSNode<T> &obj) {
        return !(*this != obj);
    }
private :
    T data;
    shared_ptr<BSNode> lchild, rchild;
};

template<typename T>
class BSTree {
public :
    BSTree() : root(T()) {}
    void insert(const T &data) {
        shared_ptr<BSNode<T>> *p = &(this->root);
        shared_ptr<BSNode<T>> *new_node = make_shared<BSNode<T> >(data);
        if (p->lchild == nullptr) {
            p->lchild = new_node;
        }
        p = p->lchild;
        while (p != new_node) {
            if (p > new_noed) {
                if (p->lchild == nullptr) {
                    p->lchild = new_node;
                }
            } else {

            }
        }
    }
private : 
    BSNode<T> root;
};

END(haizei)

#endif
