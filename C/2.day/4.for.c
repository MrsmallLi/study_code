/*************************************************************************
	> File Name: 4.for.c
	> Author: 
	> Mail: 
	> Created Time: Wed 13 Mar 2024 06:40:07 PM CST
 ************************************************************************/

#include<stdio.h>



int main() {
    //实现打印1-n;
    int n, i;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        printf("%d ", i);
    }
    printf("\n---------------\n");
    //条件可以为空，三个条件都可以为空，但是需要注意避免死循环
    for (i = 1; ; i++) {
        //遇见break 就会跳出循环
        if (i > n) break;
        printf("%d ", i);
    }
    printf("\n---------------\n");
    //只输出单数
    for (i = 1; i <= n; i++) {
        if (i % 2 == 0) continue;
        printf("i = %d\n", i);
    }
    printf("\n");
    return 0;
}
