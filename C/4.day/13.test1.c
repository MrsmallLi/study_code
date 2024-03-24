/*************************************************************************
	> File Name: 13.test1.c
	> Author: 
	> Mail: 
	> Created Time: Fri 22 Mar 2024 01:03:03 PM CST
 ************************************************************************/

#include<stdio.h>


int main() {
    int a, b, c, d;
    scanf("%d.%d.%d.%d", &a, &b, &c, &d);
    //unsigned int代表无符号整形，那么就没有符号位了
    unsigned int n;
    //由于n是int类型,所以对他的地址需要强转为char *类型
    char *p = (char *)&n; 
    p[3] = a;
    p[2] = b;
    p[1] = c;
    p[0] = d;
    //%u为无符号整形的占位符
    printf("n = %u\n", n);
    return 0;
}

