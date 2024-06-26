/*************************************************************************
	> File Name: 6.goto_if_else.c
	> Author: 
	> Mail: 
	> Created Time: Thu 14 Mar 2024 02:27:02 PM CST
 ************************************************************************/

#include <stdio.h>


int main() {
    //判断n是偶数，还是基数
    int n;
    scanf("%d", &n);
    //{}里可以放多条表达式，而小括号的作用就是将大括号里的内容变为具有返回值的表达式
    //而返回值的是多少，就是最后一条表达式的值
    //这里括号里面的返回值是最后表达式的值，那么就是1
    //通过逻辑与的判断,只要前面的语句为真就会执行后面的语句
    //因为后面的语句为1，所以一定为真
    //然后通过goto语句直接跳转,从而模拟了if_else 语句
    n % 2 == 0 && ({ goto if_stmt; 1; });
    !(n % 2) == 0 && ({ goto else_stmt; 1;});

if_stmt:
    printf("%d is even\n", n);
    goto if_end;
else_stmt:
    printf("%d is odd\n", n);
if_end:
    return 0;
}
