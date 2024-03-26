/*************************************************************************
	> File Name: 18.typedef.c
	> Author: 
	> Mail: 
	> Created Time: Sun 24 Mar 2024 06:17:30 PM CST
 ************************************************************************/

#include<stdio.h>

//此处我将long long附上一个别名ll
//那么我在这行代码下面定义long long 类型就可以使用ll来定义
typedef long long ll;
//Arr2Dim10是类型名
typedef int (*Arr2Dim10)[10];
//Fucn就是类型名
typedef void (*Func)();

void add() {
    int a = 1, b = 1;
    printf("a + b = %d\n", a + b);
    return ;
}

int main() {
    //用ll定义一个long long 类型的变量
    ll a = 123; 
    //用sizeof测量是否定义的是long long 类型
    printf("sizeof(a) = %lu\n", sizeof(a));
    int arr[5][10];
    arr[0][1] = 1231;
    //这里定义了p就是数组指针
    //用p指向arr二维数组
    Arr2Dim10 p = arr;
    printf("p[0][1] = %d\n", p[0][1]);
    //这里定义了Func类型定义了一个函数指针,指向了add函数
    Func p2 = add;
    p2();
    return 0;
}
