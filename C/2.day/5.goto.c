/*************************************************************************
	> File Name: 5.goto.c
	> Author: 
	> Mail: 
	> Created Time: Thu 14 Mar 2024 02:13:15 PM CST
 ************************************************************************/

#include <stdio.h>



int main() {
    goto lab_1;//执行完后直接跳转到lab_1:
    printf("hello world\n");
lab_1 ://上面的printf不会被执行，直接被跳过,直接执行下面的代码
    printf("hello hangzhou\n");
    goto lab_2;//同理跳转到lab_2:
    int a = 0, b = 0;
    scanf("%d%d", &a, &b);
lab_2 ://这里可以使用变量a,b但是上面的赋值是无效的
    printf("%d\n", a * b);
    return 0;
}
