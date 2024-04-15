/*************************************************************************
	> File Name: 3.stack.c
	> Author: 
	> Mail: 
	> Created Time: Wed 10 Apr 2024 02:30:49 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Stack {
    int *data;
    int size, top;
} Stack;

Stack *initStack(int n) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (int *)malloc(sizeof(int) * n);
    s->size = n;
    s->top = -1;
    return s;
}

int empty(Stack *s) {
    return s->top == -1;
}

int top(Stack *s) {
    if (empty(s)) return -1;
    return s->data[s->top];
}

int push(Stack *s, int val) {
    if (s->top + 1 >= s->size) return 0;
    s->data[++s->top] = val;
    return 1;
}

int pop(Stack *s) {
    if (empty(s)) return 0;
    s->top -= 1;
    return 1;
}

void clear(Stack *s) {
    if (!s) return ;
    free(s->data);
    free(s);
    return ;
}

void output(Stack *s) {
    printf("Stack(%d) : ", s->top + 1);
    for (int i = 0; i <= s->top; i++) {
        i && printf(" ");
        printf("%d", s->data[i]);
    }
    putchar(10);
    return ;
}

int main() {
    srand(time(0));
    #define MAX_OP 20
    Stack *s = initStack(MAX_OP);
    for (int i = 0; i < MAX_OP; i++) {
        int val = rand() % 100;
        int op = rand() % 4;
        switch(op) {
            case 0:
            case 1:
            case 2: {
                printf("push %d in stack is %d\n", val, push(s, val));
                output(s);
            } break;
            case 3: {
                int top_val = top(s);
                printf("pop %d to stack is %d\n", top_val, pop(s));
                output(s);
            } break;
        }
    }
    clear(s);
    return 0;
}
