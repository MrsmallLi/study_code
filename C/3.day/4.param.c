/*************************************************************************
	> File Name: 4.param.c
	> Author: 
	> Mail: 
	> Created Time: Mon 18 Mar 2024 12:36:30 PM CST
 ************************************************************************/

#include <stdio.h>

void function_A(int a, int b) {//函数定义中()a,b是形参
    a = a + 1;
    b = b * 2;
    printf("in function_A : a = %d, b = %d\n", a, b);
    return ; 
}



int main() {
    int a = 1, b = 2;
    function_A(a, b);//调用函数()中a,b是实参
    printf("in main : a = %d, b = %d\n", a, b);
    return 0;
}
