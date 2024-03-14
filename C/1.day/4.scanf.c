/*************************************************************************
	> File Name: 4.scanf.c
	> Author: 
	> Mail: 
	> Created Time: Sun 10 Mar 2024 03:56:04 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    //定义
    int a, b, n;
    //输出提示信息，提示你该输入a,b需要读入的值了
    printf("normal scanf, input a, b: ");
    //%d整形格式占位符中间可以不加空格
    //如果代码成功运行那个scanf就成功读取两个参数也就是a和b，那么n的值就应该为2，因为scanf的返回值为成功读取参数的个数
    n = scanf("%d%d", &a, &b);
    printf("a = %d, b = %d\n", a, b);
    printf("n = %d\n", n);
    printf("normal scanf, input %%dabc%%d: ");
    //你如果输入的数据为123abc456那么, a, b的值分别为123， 456, 而'abc'被scanf的格式化吞掉了
    //而返回值n的值为2,因为成功读入的参数还是只有a，b两个
    n = scanf("%dabc%d", &a, &b);
    printf("a = %d, b= %d\n", a, b);
    printf("n = %d\n", n);
    return 0;
}
