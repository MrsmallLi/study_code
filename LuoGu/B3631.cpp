/*************************************************************************
	> File Name: B3631.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 15 Jan 2025 10:45:46 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int f[1000005] = {0};

int main() {
    int t;
    cin >> t;
    f[0] = 1;
    for (int i = 0; i < t; i++) {
        int a, b, c;
        cin >> a >> b;
        switch(a) {
            case 1 : {
                cin >> c;
                f[c] = f[b];
                f[b] = c;
            } break;
            case 2 : {
                printf("%d\n", f[b]);
            } break;
            case 3 : {
                f[b] = f[f[b]];
            } break;
        }
    }
    return 0;
}




/**
struct Node {
    int val;
    Node *next;
};

Node *init(int val, Node *next = nullptr) {
    Node *n = (Node *)calloc(sizeof(int), 1);
    n->val = val;
    n->next = next;
    return n;
}

Node *insert(Node *n, int x, int val) {
    Node *l = n;
    while (l && l->val != x) l = l->next;
    Node *now = init(val, l->next);
    l->next = now;
    return n;
}

void output(Node *n, int val) {
    Node *l = n;
    while (l && l->val != val) l = l->next;
    printf("%d\n", l->next ? l->next->val : 0);
    return ;
}

void erase(Node *n, int val) {
    Node *l = n;
    while (l && l->val != val) l = l->next;
    Node *now = l->next;
    if (now) {
        l->next = now->next;
        now->next = nullptr;
        free(now);
    }
    return ;
}

void clear(Node *n) {
    if (!n) return ;
    clear(n->next);
    free(n);
    return ;
}

void output1(Node *n) {
    while (n) {
        printf("%d->", n->val);
        n = n->next;
    }
    return ;
}
**/
