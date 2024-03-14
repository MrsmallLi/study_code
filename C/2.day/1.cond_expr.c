/*************************************************************************
	> File Name: 1.cond_expr.c
	> Author: 
	> Mail: 
	> Created Time: Wed 13 Mar 2024 04:23:25 PM CST
 ************************************************************************/

#include <stdio.h>


int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    //输出每个条件表达式对应的整形值
    printf("a == b (%d)\n",     a == b);
    printf("a != b (%d)\n",     a != b);
    printf("a < b (%d)\n",      a < b);
    printf("a > b (%d)\n",      a > b);
    printf("a <= b (%d)\n",     a <= b);
    printf("a >= b (%d)\n",     a >= b);
    printf("!(a == b) (%d)\n", !(a == b));
    printf("a = %d\n", a);
    //看关系表达式对应整形值是否可以参与运算
    a += (a == b);
    printf("a = %d\n", a);

    //实践判断逻辑与和逻辑或的判断逻辑
    printf("a < b && a == 3 (%d)\n", a < b && a == 3);
    printf("a < b || a == 3 (%d)\n", a < b || a == 3);
    printf("1 && 1 (%d)\n", 1 && 1);
    printf("1 && 0 (%d)\n", 1 && 0);
    printf("0 && 1 (%d)\n", 0 && 1);
    printf("0 && 0 (%d)\n", 0 && 0);
    printf("1 || 1 (%d)\n", 1 || 1);
    printf("1 || 0 (%d)\n", 1 || 0);
    printf("0 || 1 (%d)\n", 0 || 1);
    printf("0 || 0 (%d)\n", 0 || 0);
    return 0;
}

