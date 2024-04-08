/*************************************************************************
	> File Name: 2.list.c
	> Author: 
	> Mail: 
	> Created Time: Mon 08 Apr 2024 03:46:52 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node{
    int data;
    struct Node *next;
} Node;

Node *getNewNode(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val; 
    p->next = NULL;
    return p;
}

Node *insert(Node *head, int pos, int val) {
    Node *p, new_head;
    new_head.next = head;
    p = &new_head;
    for (int i = 0; p->next && i < pos; i++) p = p->next;
    Node *node = getNewNode(val);
    node->next = p->next;
    p->next = node;
    return new_head.next;
}

Node *erase(Node *head, int pos) {
    if (!head) return head;
    int n = pos;
    Node *p, new_head, *q;
    new_head.next = head;
    p = &new_head;
    while (p && n > 0) p = p->next, n -= 1;
    if (!p || !p->next) {
        printf("erase fail the %d is not at list\n", pos);
        return new_head.next;
    }
    q = p->next;
    p->next = q->next;
    free(q);
    return new_head.next;
}

void output(Node *);

void format(char *s, int n) {
    printf("      ");
    for (int i = 0; i < n; i++) {
        printf("%3c", ' ');
        printf("  ");
    }
    printf("%3s", s);
    putchar(10);
    return ;
}

Node *find(Node *head, int val) {
    if (!head) return head;
    Node *p, new_head, *q;
    new_head.next = head;
    p = &new_head;
    int n = 0;
    while (p && p->data != val) p = p->next, n++;
    if (!p || !p->next) {
        printf("not find the %d is not at list\n", val);
        return new_head.next;
    }
    output(new_head.next);
    format("^", n - 1);
    format("|", n - 1);
    return new_head.next;
}

void clear(Node *head) {
    if (head == NULL) return ;
    for (Node *p = head, *q; p; p = q) {
        q = p->next; 
        free(p);
    }
    return ;
}

void output(Node *head) {
    if (!head) return ;
    printf("List :");
    Node *p = head;
    while (p) {
        printf("%3d", p->data);
        if (p->next) printf("->");
        p = p->next;
    }
    putchar(10);
    int i = 0;
    p = head;
    printf("      ");
    while (p) {
        printf("%3d", i);
        i++;
        printf("  ");
        p = p->next;
    }
    putchar(10);
    return ;
}

int main() {
    srand(time(0));
    #define MAX_OP 20
    Node *head = NULL;
    for (int i = 0; i < MAX_OP; i++) {
        int op = rand() % 4;
        int pos, val = rand() % 100;
        switch (op) {
            case 0:
            case 1:
            case 2: {
                pos = rand() % (i + 1);
                printf("insert %d at %d in list\n", val, pos);
                head = insert(head, pos, val);
                output(head);
            } break;
            case 3: {
                pos = rand() % (i + 3);
                printf("erase %d from list\n", pos);
                head = erase(head, pos);
                output(head);
            } break;
        }
    }
    for (int i = 0; i < MAX_OP; i++) {
        int val = rand() % 100;
        printf("find %d in list\n", val);
        head = find(head, val);
    }
    clear(head);
    return 0;
}
