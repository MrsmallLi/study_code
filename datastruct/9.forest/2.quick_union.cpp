/*************************************************************************
	> File Name: 2.quick_union.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 31 May 2024 10:31:38 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 10000
int fa[MAX_N + 5];

void init(int n) {
    for (int i = 0; i <= n; i++) {
        fa[i] = i;
    }
    return ;
}

int find(int x) {
    return fa[x] == x ? x : find(fa[x]);
}

int merge(int a, int b) {
    int aa = find(a), bb = find(b);
    if (aa == bb) return 0;
    fa[aa] = bb;
    return 1;
}

void output(int n) {
    int ret = 0;
    for (int i = 0; i <= n; i++) {
        ret += printf("%3d", i);
    }
    putchar(10);
    for (int i = 0; i < ret; i++) printf("-");
    putchar(10);
    for (int i = 0; i <= n; i++) {
        printf("%3d", fa[i]);
    }
    putchar(10);
    return ;
}

int main() {
    int n, a, b;
    cin >> n;
    init(n);
    while (cin >> a >> b) {
        printf("merge %d wite %d : %d\n", a, b, merge(a, b));
        output(n);
    }
    return 0;
}
