/*************************************************************************
	> File Name: 5.haffman.c
	> Author: 
	> Mail: 
	> Created Time: Fri 19 Apr 2024 04:47:42 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    //ch表示当前节点的字符
    char ch;
    //这里用频次表示频率
    int freq;
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(int freq, char ch) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->ch = ch;
    p->freq = freq;
    p->lchild = p->rchild = NULL;
    return p;
}

void clear(Node *root) {
    if (!root) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

void swap_node(Node **node_arr, int i, int j) {
    Node *temp = node_arr[i];
    node_arr[i] = node_arr[j];
    node_arr[j] = temp;
    return ;
}

//将最小值的位置进行找到并返回
int find_min_node(Node **node_arr, int n) {
    int ind = 0;
    for (int j = 0; j <= n; j++) {
        if (node_arr[ind]->freq > node_arr[j]->freq) ind = j;
    }
    return ind;
}


Node *buildHaffmanTree(Node **node_arr, int n) {
    //这里的循环表示n - 1次构建第二步
    for (int i = 1; i < n; i++) {
        //找到当前指针数组种第一小的freq值,也就是频率
        int min_ind1 = find_min_node(node_arr, n - i);
        //第一次将第一最小的放在数组最后一位
        swap_node(node_arr, min_ind1, n - i);
        //找到当前指针数组种第二小的freq值, 第一小的位置是当前最后的位置,已经被排除
        int min_ind2 = find_min_node(node_arr, n - i - 1);
        //n - i位置就是最小的，所以把第二小元素的位置放在n - i - 1，也就是当前倒数第二个位置
        swap_node(node_arr, min_ind2, n - i - 1);
        //然后得到它们的频率和
        int freq = node_arr[n - i]->freq + node_arr[n - i - 1]->freq;
        //创建新的节点
        Node *node = getNewNode(freq, 0);
        //进行将两个节点接在新节点上
        node->lchild = node_arr[n - i - 1];
        node->rchild = node_arr[n - i];
        //最后将新创建的节点放在倒数第二个数组的位置
        //下次循环就不会用到当前循环的最后一个位置了
        node_arr[n - i - 1] = node;
    }
    return node_arr[0];
}

#define MAX_CHAR_NUM 128
char *char_code[MAX_CHAR_NUM] = {0};

void extractHaffmanCode(Node *root, char *buff, int k) {
    buff[k] = 0;
    //当没有子节点时说明当前位置有字符，需要进行操作，并回溯
    if (!root->lchild && !root->rchild) {
        char_code[root->ch] = strdup(buff);
        return ;
    }
    //设置当前为遍历左子树那么当前位置就应该为0
    buff[k] = '0';
    extractHaffmanCode(root->lchild, buff, k + 1);
    //设置当前为遍历右子树那么当前位置就应该为1
    buff[k] = '1';
    extractHaffmanCode(root->rchild, buff, k + 1);
    return ;
}

int main() {
    //n表示读入多少种字符
    char s[10];
    int n, freq;
    scanf("%d", &n);
    Node **node_arr = (Node **)malloc(sizeof(Node *) * n);
    //将每个字符的数据进行节点化
    for (int i = 0; i < n; i++) {
        scanf("%s%d", s, &freq);
        node_arr[i] = getNewNode(freq, s[0]);
    }
    //最终将节点进行哈夫曼编码
    Node *root = buildHaffmanTree(node_arr, n);
    char buff[1000];
    //将转换的哈夫曼编码进行输出打印看到效果
    extractHaffmanCode(root, buff, 0);
    for (int i = 0; i < MAX_CHAR_NUM; i++) {
        if (!char_code[i]) continue;
        printf("%c : %s\n", i, char_code[i]);
    }
    return 0;
}
