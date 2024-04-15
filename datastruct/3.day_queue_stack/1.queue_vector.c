/*************************************************************************
	> File Name: 1.queue.c
	> Author: 
	> Mail: 
	> Created Time: Wed 10 Apr 2024 11:01:35 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct vector {
    int *data;  
    int size, count;
} vector;

vector *initVector(int n) {
    vector *v = (vector *)malloc(sizeof(vector));
    v->data = (int *)malloc(sizeof(int) * n);
    v->size = n;
    v->count = 0;
    return v;
}

int vectorSeek(vector *v, int ind) {
    return v->data[ind];
}

int insertVector(vector *v, int ind, int val) {
    if (v->size == v->count) return 0;
    if (ind < 0 || ind > v->count) return 0; 
    for (int i = v->count; i > ind; i--) {
        v->data[i] = v->data[i - 1];
    }
    v->data[ind] = val;
    v->count += 1;
    return 1;
}


typedef struct Queue {
    vector *data;
    int size, head, tail, count;
} Queue;

Queue *initQueue(int n) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = initVector(n);
    q->size = n;
    q->head = q->tail = q->count = 0;
    return q;
}

int empty(Queue *q) {
    return q->count == 0;
}

int push(Queue *q, int val) {
    if (q->count == q->size) return 0;
    insertVector(q->data, q->tail, val);
    q->tail += 1;
    if (q->tail == q->size) q->tail = 0;
    q->count += 1;
    return 1;
}

int pop(Queue *q) {
    if (empty(q)) return 0;
    q->head += 1;
    q->count -= 1;
    return 1;
}

int front(Queue *q) {
    return vectorSeek(q->data, q->head);
}

void clearVector(vector *v) {
    if (!v) return ;
    free(v->data);
    free(v);
    return ;
}

void clear(Queue *q) {
    if (!q) return ;
    clearVector(q->data);
    free(q);
    return ;
}

void output(Queue *q) {
    printf("Queue(%02d) : ", q->count);
    for (int i = q->head; i != q->tail; i++)  {
        i != q->head && printf(" ");
        printf("%02d", vectorSeek(q->data, i % q->size));
    }
    putchar(10);
    return ;
}

int main() {
    srand(time(0));
    #define MAX_OP 20    
    Queue *q = initQueue(MAX_OP);
    for (int i = 0; i < MAX_OP; i++) {
        int val = rand() % 100;
        int op = rand() % 4;
        switch (op) {
            case 0:
            case 1:
            case 2: {
                printf("push %d in Queue is %d\n", val, push(q, val));
                output(q);
            } break;
            case 3: {
                int pop_val = front(q);
                printf("pop %d at Queue is %d\n", pop_val, pop(q));
                output(q);
            } break;
        }
    }

    clear(q);
    return 0;
}
