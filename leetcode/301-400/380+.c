/*************************************************************************
	> File Name: 380+.c
	> Author: 
	> Mail: 
	> Created Time: Fri 24 Jan 2025 10:06:43 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#define swap(a, b) {\
    __typeof(a) __a = a;\
    a = b;\
    b = __a;\
}

typedef struct Node{
    int val, ind;
    struct Node *next;
} Node;

typedef struct {
    Node **n;
    int cnt, size;
    int *arr, arr_size;
} RandomizedSet;


RandomizedSet* randomizedSetCreate() {
    srand(time(0));
    RandomizedSet *r = (RandomizedSet *)malloc(sizeof(RandomizedSet));
    r->n = (Node **)calloc(sizeof(Node *), 25000);
    for (int i = 0; i < 25000; i++) {
        r->n[i] = (Node *)calloc(sizeof(Node), 1);
        r->n[i]->ind = -1;
        r->n[i]->next = NULL;
    }
    r->arr = (int *)calloc(sizeof(int), 25000);
    r->size = 25000;
    r->cnt = 0;
    r->arr_size = 0;
    return r;
}

int HashFun(RandomizedSet *obj, int val) {
    long long temp = val;
    temp *= temp;
    int key = (temp & 0x7fffffff) % obj->size;
    return key;
}


bool randomizedSetInsert(RandomizedSet* obj, int val) {
    int key = HashFun(obj, val);
    Node *n = obj->n[key];
    while (n->next) {
        if (n->next->val == val) return false; 
        n = n->next;
    }
    n = obj->n[key];
    Node *new_node = (Node *)calloc(sizeof(Node), 1);
    new_node->val = val;
    new_node->ind = obj->arr_size;
    obj->arr[obj->arr_size++] = val;
    new_node->next = n->next;
    n->next = new_node;
    return true;
}

bool randomizedSetRemove(RandomizedSet* obj, int val) {
    int key = HashFun(obj, val) ;
    Node *n = obj->n[key];
    while (n->next && n->next->val != val) n = n->next;
    if (!n->next) return false;
    //在哈希表中的节点中的链表，删除该节点
    Node *free_node = n->next;
    n->next = n->next->next;
    //将数组中存的该数值删除
    //将最后一个位置的元素进行叫唤删除的元素
    //并将最后位置元素在哈希表中记录的位置进行重新记录
    int ind = free_node->ind;
    key = HashFun(obj, obj->arr[obj->arr_size - 1]);
    swap(obj->arr[ind], obj->arr[obj->arr_size - 1]);
    n = obj->n[key];
    val = obj->arr[ind];
    while (n->next && n->next->val != val) n = n->next;
    if (n->next) n->next->ind = ind;
    obj->arr_size -= 1;
    free(free_node);
    return true;
}

int randomizedSetGetRandom(RandomizedSet* obj) {
    int ind = rand() % obj->arr_size;
    return obj->arr[ind];
}

void free_node(Node *n) {
    while (n){
        Node *next = n->next;
        free(n);
        n = next;
    } 
    return ;
}

void randomizedSetFree(RandomizedSet* obj) {
    for (int i = 0; i < 25000; i++) {
        free_node(obj->n[i]);
    }
    free(obj->n);
    free(obj);
    return ;
}
