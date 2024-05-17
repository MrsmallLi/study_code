/*************************************************************************
	> File Name: 1.skiplist.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 14 May 2024 07:23:48 PM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <climits>
using namespace std;

class Node {
public :
    Node() : key(0), next(nullptr), up(nullptr), down(nullptr){}
    static Node *getNewList(int, int);
    static void clearNode(Node *);
    int key, level;
    Node *next, *up, *down;
};

class Skiplist {
public :
    Skiplist() : head(nullptr), tail(nullptr), max_level(0) {}
    static Skiplist *getNewSkiplist(int );
    static void clearSkiplist(Skiplist *);
    static int insert(Skiplist *, int);
    static int erase(Skiplist *, int);
    static int randLevel(Skiplist *);
    static Node *find(Skiplist *, int);
    static void output(Skiplist *s);
    Node *head, *tail;
    int max_level;
};

Node *Node::getNewList(int key, int n) {
    Node *nodes = new Node[n];
    for (int i = 0; i < n; i++) {
        nodes[i].key = key;
        nodes[i].level = i;
        nodes[i].next = nullptr;
        nodes[i].down = (i ? nodes + i - 1 : nullptr);
        nodes[i].up = (i + 1 < n ? nodes + i + 1 : nullptr);
    }
    return nodes + n - 1;
}

double randDoubleNum() {
    #define MAX_RAND_N 10000
    return (rand() % MAX_RAND_N)* 1.0 / MAX_RAND_N;
    #undef MAX_RAND_N
}

int Skiplist::randLevel(Skiplist *s) {
    int level = 1; 
    double p = 1.0 / 2.0;
    while (randDoubleNum() < p) level += 1;
    return min(s->max_level, level);
}

int Skiplist::insert(Skiplist *s, int key) {
    if (!s) return 0;
    int level = randLevel(s);
    while (s->head->level < level) s->head = s->head->up;
    Node *node = Node::getNewList(key, level);
    Node *p = s->head;
    while (p->level != node->level) p = p->down;
    while (p) {
        while (p->next->key < node->key) p = p->next;
        node->next = p->next;
        p->next = node;
        p = p->down;
        node = node->down;
    }
    return 1;
}

Node *Skiplist::find(Skiplist *s, int key) {
    if (!s) return nullptr;
    Node *p = s->head;
    while (p && p->key != key) {
        if (p->next->key <= key) p = p->next;
        else p = p->down;
    }
    return p;
}

Skiplist *Skiplist::getNewSkiplist(int n) {
    Skiplist *s = new Skiplist();
    s->max_level = n;
    s->head = Node::getNewList(INT_MIN, n);
    s->tail = Node::getNewList(INT_MAX, n);
    Node *p = s->head, *q = s->tail;
    while (s->head->down) s->head = s->head->down;
    while (s->tail->down) s->tail = s->tail->down;
    while (p) {
        p->next = q;
        p = p->down;
        q = q->down;
    }
    return s;
}

void Skiplist::output(Skiplist *s) {
    if (!s) return ;
    Node *p = s->head; 
    int len = 0;
    int level_str_len = printf("level : ");
    len += level_str_len;
    char buff[level_str_len + 5] = {0};
    for (int i = 0; i < level_str_len;) buff[i++] = ' ';
    for (int i = 0; i < s->head->level; i++) {
        len += printf("%4d", i);
    }
    cout << endl;
    while (p->level > 0) p = p->down;
    while (p) {
        cout << buff;
        if (p->key == INT_MIN || p->key == INT_MAX) {
            printf("%4c", p->key > 0 ? '+' : '-');
        }
        else {
            for (Node *q = p; q; q = q->up) {
                printf("%4d", q->key);
            }
        }
        cout << endl;
        p = p->next;
    }
    for (int i = 0; i < len; i++) cout << "-";
    cout << endl;
}

void Node::clearNode(Node *n) {
    if (!n) return ;
    delete n;
    return ;
}

void Skiplist::clearSkiplist(Skiplist *s) {
    if (!s) return ;
    Node *p = s->head, *q;
    while (p) {
        q = p->next;
        Node::clearNode(p);
        p = q;
    }
    delete s;
    return ;
}


int main() {
    srand(time(0));
    int x;
#define MAX_LEVEL 32
    Skiplist *s = Skiplist::getNewSkiplist(20);
#undef MAX_LEVEL
    Skiplist::output(s);
    for (int i = 0; i < 5; i++) {
        int x = rand() % 50;
        cout << "insert " << x << endl;
        Skiplist::insert(s, x);
        Skiplist::output(s);
    }
    while (~scanf("%d", &x)) {
        int x;
        if (x == -1) break;
        cin >> x;
        if (Skiplist::find(s, x)) {
            printf("Yes Find\n") ;
        } else {
            printf("Not find\n");
        }
    }
    Skiplist::clearSkiplist(s);
    return 0;
}

