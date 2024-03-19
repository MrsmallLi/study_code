/*************************************************************************
	> File Name: 2.function.c
	> Author: 
	> Mail: 
	> Created Time: Fri 15 Mar 2024 06:17:48 PM CST
 ************************************************************************/

#include <stdio.h>
#include <math.h>

//返回值类型 函数名 (参数列表)
int sum(int a, int b) {
    //函数体
    return a + b;//函数里必须有的return,进行对函数值的返回
}
//定义一个函数，有两个参数，一个参数为flag，一个为x
//当flag = 1，返回根号下x
//当flag = 2，返回x * x
//现在就需要去构思，函数名可以随便，但是必须是由字母数字和_组成,并且只能由字母和_开头
//思考返回值类型是什么,由于返回值有根号下x,所以返回值类型为double
//函数名就随便起，满足上面的条件
//然后是参数，x和flag，类型都为int
//最后构建函数体
double  function_1(int flag, int x) {
    //这里用到数学函数,注意不要漏掉头文件
    if (flag == 1) return sqrt(x);
    else if (flag == 2) return x * x;
    //这里需要考虑到flag不等于1，2,所以要else 返回一个0
    else return 0;
}

//设计一个函数，函数的作用就是传入一个n，然后打印n次hello world
//设计思路就是function_1中的思路
//但是这里的返回值是没用的，所以这里引用了void，表示没有返回值
void printf_hello_world(int n) {
    for (int i = 0; i < n; i++) {
        printf("hello world\n");
    }
    return ;//不返回任何东西,表示函数结束
}

int main() {
    //函数使用,直接用函数名(),()里需要填
    //你定义的函数参数列表的类型，以及对应的参数个数
    printf("3 + 4 = %d\n", sum(3, 4));//这里函数使用它返回的值就是3 + 4的值7
    int flag, x;
    printf("intput flag and x\n");
    scanf("%d%d", &flag, &x);
    //注意顺序不能乱写
    //由于返回值类型是double所以格式占位符要用%lf
    printf("function_1 = %lf\n", function_1(flag, x));
    int n;
    printf("input n\n");
    scanf("%d", &n);
    printf_hello_world(n);
    return 0;
}
