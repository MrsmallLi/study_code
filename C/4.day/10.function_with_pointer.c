/*************************************************************************
	> File Name: 10.function_with_pointer.c
	> Author: 
	> Mail: 
	> Created Time: Thu 21 Mar 2024 07:45:15 PM CST
 ************************************************************************/

#include<stdio.h>

void add_once(int x) {
    x += 1;
    return ;
}

//这里参数是指针
void add_two(int *p) {
    *p += 1;//那么这里进制修改的是指针指向地址的值，那么传出函数地址里的值也是改变后的 
    return ;
}

//当需要函数进行对参数传出时，可以使用指针来进行实现
void f(int n, int *sum_addr) {
    *sum_addr = (1 + n) * n / 2;
    return ;
}

//在这p可以当作数组来使用
void output(int *p, int n) {
    //[]表示运算符,p[i] = *(p + i);
    for (int i = 0; i < n; i++) {
        printf("p[%d] = %d\n", i, p[i]);
    }
    return ;
}

int main() {
    int a = 123;
    //这里用到了实参和形参
    //形参的改变是不会影响实参的值
    printf("a = %d\n", a);
    add_once(a);
    printf("a = %d\n", a);
    //这里用到了取地址
    //参数传入的是地址
    //因为指针存储的值是地址
    add_two(&a);
    printf("a = %d\n", a);

    //传出参数
    int b = 10, sum;
    f(b, &sum);
    printf("sum = %d\n", sum);

    int arr[10] = {9, 8, 5, 3, 6, 2, 1, 0, 4, 7};
    //arr数组名表示数组的首地址
    output(arr, 10);
    return 0;
}
