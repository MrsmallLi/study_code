/*************************************************************************
	> File Name: 8.goto_while.c
	> Author: 
	> Mail: 
	> Created Time: Thu 14 Mar 2024 02:49:28 PM CST
 ************************************************************************/

#include <stdio.h>



int main() {
    //代码要求，输出1-n的值
    int n, i = 1;
    scanf("%d", &n);
judge:
    //这里判断i是否小于等于n, 如果满足那就继续执行
    if (i <= n) goto lab_1;//循环判断条件
    //不满足就跳出循环
    else goto while_end;//这里就是结束循环

lab_1:
    //这里需要i++,不然会死循环一直输出1
    //也可以不用i++,在下面使用i += 1;
    printf("%d ", i++);
    //这个位置使用i += 1;
    goto judge;//这里judge的作用就是返回到判断条件除
while_end:
    printf("\n");
    return 0;
}
