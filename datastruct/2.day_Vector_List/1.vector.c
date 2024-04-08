/*************************************************************************
	> File Name: 1.vector.c
	> Author: 
	> Mail: 
	> Created Time: Mon 08 Apr 2024 03:08:59 PM CST
 ************************************************************************/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct vector {
    int size, count;
    int *data;
} vector;

vector *getNewvector(int n) {
    vector *p = (vector *)malloc(sizeof(vector));
    p->size = n;
    p->count = 0;
    p->data = (int *)malloc(sizeof(int) * n);
    return p;
}

int expend(vector *v) {
    if (!v) return 0;
    int *p = (int *)realloc(v->data, sizeof(int) * 2 * v->size);
    if (!p) return 0;
    v->data = p;
    v->size *= 2;
    printf("expend is success, vector->size = %d\n", v->size);
    return 1;
}

int insert(vector *v, int pos, int val) {
    if (pos < 0 || pos > v->count) return 0;
    if (v->size == v->count && expend(v)) return 0;
    for (int i = v->count - 1; i >= pos; i--) {
        v->data[i + 1] = v->data[i];
    }
    v->data[pos] = val;
    v->count += 1;
    return 1;
}

int erase(vector *v, int pos) {
    if (pos < 0 || pos >= v->count) return -1;
    int erase_num = v->data[pos];
    for (int i = pos + 1; i < v->count - 1; i++) {
        v->data[i - 1] = v->data[i];
    }
    v->count -= 1;
    return erase_num;
}

void output(vector *v) {
    int len = 0;
    for (int i = 0; i < v->count; i++) {
        len += printf("%3d", v->data[i]);
    }
    putchar(10);
    for (int i = 0; i < len; i++) printf("-");
    putchar(10);
    for (int i = 0; i < v->count; i++) {
        printf("%3d", i);
    }
    putchar(10);
    return ;
}


void clear(vector *v) {
    if (!v) return ;
    free(v->data);
    free(v);
    return ;
}

int main() {
    srand(time(0));
    #define MAX_OP 20
    vector *v = getNewvector(5);
    for (int i = 0; i < MAX_OP; i++) {
        int op = rand() % 4;
        int val = rand() % 100;
        int ind;
        switch (op) {
            case 0:
            case 1: 
            case 2: {
                ind = rand() % (v->count + 2);
                printf("insert %d at %d in vector is %d\n", val, ind, insert(v, ind, val));
                output(v);
            } break;
            case 3: {
                ind = rand() % (v->count + 1);
                printf("erase %d from vector is %s\n", erase(v, ind), erase(v, ind) == -1 ? "Fail" : "success");
                output(v);
            } break;
        }
    }
    clear(v);
    return 0;
}
