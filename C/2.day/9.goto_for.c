/*************************************************************************
	> File Name: 9.goto_for.c
	> Author: 
	> Mail: 
	> Created Time: Thu 14 Mar 2024 02:58:05 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    //输出1-n
    int n;
    scanf("%d", &n);
    int i;
//初始化
for_1:
    i = 1;
    goto for_2;
for_2:
    if (i <= n) goto for_4;//为真执行代码块
    else goto for_end;//为假循环结束
//执行后操作
for_3:
    i += 1;//或者i++;
    goto for_2; //回到条件判断
//执行代码块
for_4:
    printf("%d ", i);
    goto for_3;
//循环结束
for_end:
    printf("\n");
    return 0;
}
