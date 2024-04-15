/*************************************************************************
	> File Name: 1.queue_vector.c
	> Author: 
	> Mail: 
	> Created Time: Wed 10 Apr 2024 11:51:20 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *getNewNode(int val) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = val;
    n->next = NULL;
    return n;
}

int insert_tail_Node(Node *n, Node *new_Node) {
    if (!n) return 0;
    while (n && n->next) n = n->next;
    new_Node->next = n->next;
    n->next = new_Node;
    return 1;
}

int erase_Head_Node(Node *n) {
    if (!n || !n->next) return 0;
    //由于队列中存储的是虚拟头节点，那么弹出，就可以直接删除头节点就可以了
    //记录一下头节点，用于后面对弹出的节点释放空间
    Node *p = n->next;
    n->next = n->next->next;
    free(p);
    return 0;
}

typedef struct Queue {
    Node *head;//存储队列中的数据用链表进行存储
    int count;
} Queue;

Queue *initQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->head = getNewNode(-1);//队列中存储的链表节点是虚拟头节点
    q->count = 0;
    return q;
}

int empty(Queue *);
int front(Queue *q) {
    //如果队列为空，说明没有队头元素，返回-1
    if (empty(q)) return -1;
    return q->head->next->data;
}

int empty(Queue *q) {
    return q->count == 0; 
}

//入队操作
int push(Queue *q, int val) {
    if (!q) return 0;
    //对应链表就是在链表尾部进行添加节点
    insert_tail_Node(q->head, getNewNode(val));
    q->count += 1;
    return 1;
}
//队列的弹出头部操作
int pop(Queue *q) {
    if (empty(q)) return 0;
    //对应链表就是删除链表头节点
    erase_Head_Node(q->head);
    q->count -= 1;
    return 1; 
}
//释放链表在堆区开辟的空间
void clearNode(Node *head) {
    if (!head) return ;
    clearNode(head->next);//通过递归来进行对链表的释放
    free(head);
    return ;
}
//释放队列在堆区开辟的空间
void clear(Queue *q) {
    if (!q) return ;
    clearNode(q->head);
    free(q);
    return ;
}

void output(Queue *q) {
    int len = 0;
    len += printf("Queue(%02d) : ", q->count);
    Node *p = q->head->next;
    while (p) {
        p != q->head->next && printf(" ");
        len += printf("%02d", p->data);
        p = p->next;
    }
    putchar(10);
    for (int i = 0; i < len; i++) printf("-");
    putchar(10);
    return ;
}

int main() {
    //测试
    #define MAX_OP 20
    srand(time(0));
    Queue *q = initQueue();
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
                int front_num = front(q);
                printf("pop %d at Queue is %d\n", front_num, pop(q));
                output(q);
            } break;
        }
    }
    clear(q);
    return 0;
}
