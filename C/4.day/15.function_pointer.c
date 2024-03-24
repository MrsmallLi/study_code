/*************************************************************************
	> File Name: 15.function_pointer.c
	> Author: 
	> Mail: 
	> Created Time: Fri 22 Mar 2024 03:29:49 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void test1() {
    printf("function test1\n");
    return ;
}

void test2() {
    printf("function test2\n");
    return ;
}

void test3() {
    printf("function test3\n");
    return ;
}
//这里的函数中指针p，指向的就是返回值为void,参数列表为空的函数
void (*p)();

int main() {
    srand(time(0));//产生随机种子
    p = test1;//让指针指向test1
    p();
    p = test2;
    p();
    p = test3;
    p();
    printf("---------------\n");
    //定义一个函数指针数组,初始化0,1,2位置分别为test1,test2,test3
    void (*arr[3])() = {test1, test2, test3};
    for (int i = 0; i < 10; i++) {
        //rand() 取随机数，%3取随机数0,1,2
        arr[rand() % 3]();
    }
    return 0;
}
