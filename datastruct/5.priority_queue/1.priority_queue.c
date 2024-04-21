/*************************************************************************
	> File Name: 1.priority_queue.c
	> Author: 
	> Mail: 
	> Created Time: Sun 21 Apr 2024 10:39:15 AM CST
 ************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROOT 1
#define cmp >
#define FATHER(n) ((n) / 2)
#define LEFT(n) ((n) << 2)
#define RIGHT(n) ((n) * 2 + 1)
#define swap(a, b) {\
    __typeof(a) __c = (a);\
    a = b;\
    b = __c;\
}


typedef struct PriorityQueue {
    int *__data, *data;
    int size, n;
} priority_queue;

priority_queue *initPQ(int size) {
    priority_queue *p = (priority_queue *)malloc(sizeof(priority_queue));
    p->__data = (int *)malloc(sizeof(int) * (size + 1));
    p->data = p->__data - ROOT;
    p->size = size;
    p->n = 0;
    return p;
}

int empty(priority_queue *p) {
    return p->n == 0;
}

int full(priority_queue *p) {
    return p->n == p->size;
}

int top(priority_queue *p) {
    if (empty(p)) return -1;
    return p->data[ROOT];
}

void up_updata(int *data, int n) {
    if (n == ROOT) return ;
    if (data[n] cmp data[FATHER(n)]) {
        swap(data[n], data[FATHER(n)]);
        up_updata(data, FATHER(n));
    } 
    return ;    
}


int push(priority_queue *p, int x) {
    if (full(p)) return 0;
    p->n += 1;
    p->data[p->n] = x;
    up_updata(p->data, p->n);
    return 1;
}

void down_updata(int *data, int i, int n) {
    if (i == n) return ;
    int ind = i;
    if (LEFT(i) <= n && data[ind] cmp data[LEFT(ind)]) ind = LEFT(ind);
    if (RIGHT(ind) <= n && data[ind] cmp data[RIGHT(ind)]) ind = RIGHT(ind);
    if (ind != i) {
        swap(data[ind], data[i]);
        down_updata(data, ind, n);
    }
    return ;
}

int pop(priority_queue *p) {
    if (empty(p)) return 0;
    int num = top(p);
    p->data[ROOT] = p->data[p->n];
    p->n -= 1;
    down_updata(p->data, ROOT, p->n);
    return num;
}


void clear(priority_queue *p) {
    if (!p) return ;
    free(p->__data);
    free(p);
    return ;
}
    
void output(priority_queue *p) {
    for (int i = 1; i <= p->n; i++) {
        i != 1 && printf(" ");
        printf("%d", p->data[i]);
    }
    putchar(10);
    return ;
}

int main() {
    srand(time(0));
    #define MAX_OP 20
    priority_queue *p = initPQ(MAX_OP);
    for (int i = 0; i < MAX_OP; i++) {
        int op = rand() % 4;
        int val = rand() % 100;
        switch (op) {
            case 0:    
            case 1:    
            case 2: {
                printf("push %d in priority_queue is %d\n", val, push(p, val));
            } break;
            case 3: {
                int num = pop(p);
                printf("pop %d in priority_queue is %s\n", num, num ? "Yes" : "No");
            } break;
        }
        output(p);
    }
    clear(p);
    return 0;
}

