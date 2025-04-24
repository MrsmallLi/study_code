/*************************************************************************
	> File Name: 705.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 11 Feb 2025 04:25:43 PM CST
 ************************************************************************/

#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node *next;
}Node;
/*
int insert_node(Node *n, Node *new_node) {
    if (!n || !new_node) return 0;
    new_node->next = n->next;
    n->next = new_node;
    return 1;
}
*/

Node *init(int val) {
    Node *n = (Node *)calloc(sizeof(Node), 1);
    n->val = val;
    return n;
}

typedef struct {
    Node **arr;
    int size;
} MyHashSet;


MyHashSet* myHashSetCreate() {
    MyHashSet *mp = (MyHashSet *)malloc(sizeof(MyHashSet) * 1);
    mp->arr = (Node **)calloc(sizeof(Node *), 1005);
    for(int i = 0; i < 1005; i++) mp->arr[i] = (Node *)calloc(sizeof(Node), 1);
    mp->size = 1005;
    return mp;
}

int Hash_func(MyHashSet *obj, int key) {
    return (key & 0x7fffffff) % obj->size;
}

//添加元素方法
bool myHashSetContains(MyHashSet* obj, int key);
void myHashSetAdd(MyHashSet* obj, int key) {
    int ind = Hash_func(obj, key);
    Node *n = obj->arr[ind];
    if (myHashSetContains(obj, key)) return ;
    Node *new_node = init(key);
    new_node->next = n->next;
    n->next = new_node;
    return ;
}

//移除元素方法
void myHashSetRemove(MyHashSet* obj, int key) {
    int ind = Hash_func(obj, key);
    Node *n = obj->arr[ind];
    while (n && n->next) {
        if (n->next->val == key) {
            Node *f = n->next;
            n->next = f->next;
            free(f);
            break;
        }
        n = n->next;
    }
    return ;
}

//查询方法
bool myHashSetContains(MyHashSet* obj, int key) {
    int ind = Hash_func(obj, key);
    Node *n = obj->arr[ind]->next;
    while (n) {
        if (n->val == key) return true;
        n = n->next;
    }
    return false;
}

//释放哈希表
void free_node(Node *n) {
    if (!n) return ;
    free_node(n->next);
    free(n);
    return ;
}
void myHashSetFree(MyHashSet* obj) {
    for (int i = 0; i < obj->size; i++) {
        free_node(obj->arr[i]);
    }
    free(obj->arr);
    free(obj);
    return ;
}

