/*************************************************************************
	> File Name: 4.array.c
	> Author: 
	> Mail: 
	> Created Time: Thu 21 Mar 2024 04:30:36 PM CST
 ************************************************************************/

#include<stdio.h>

//数组定义和使用
void test1() {
    int a[5] = {0};
    for (int i = 0; i < 5; i++) {
        //a[i] 就可以访问数组对应下标为i的位置
        //也可以进行赋值
        a[i] = 2 * i;
    }
    for (int i = 0; i < 5; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }
    return ;
}

//动态数组的定义和使用
void test2() {
    //通过执行程序时来定义数组想要的大小
    int n;
    scanf("%d", &n);
    //动态数组是无法初始化的
    int a[2 * n];
    for (int i = 0; i < 2 * n; i++) {
        a[i] = i * i;
    }
    for (int i = 0; i < 2 * n; i++) {
        printf("a[%d] = %d\n", i, a[i]) ;
    }
    return ;
}
//初始化进行对数组赋值
void test3() {
    // int a[5] = {0}; 这种初始化是将每个位置初始化为0
    int a[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)  {
        printf("a[%d] = %d\n", i, a[i]);
    }
    return ;
}
//数组定义时不在[]中输入大小
void test4() {
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    //sizeof(a)获取数组字节大小
    //sizeof(int)获取int类型字节大小
    //相除就可以得到数组元素的个数
    int len = sizeof(a) / sizeof(int);
    printf("sizeof(a) / sizeof(int) = %d\n", len);
    for (int i = 0; i < len; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }
    return ;
}
//数组的地址理解
void test5() {
    int a[5] = {1, 2, 3, 4, 5};
    printf("a = %p\n", a);
    for (int i = 0; i < 5; i++) {
        printf("&a[%d] = %p\n", i, &a[i]);
    }
    return ;
}

int main() {
    printf("test1()\n");
    test1();
    printf("test2()\n");
    test2();
    printf("test3()\n");
    test3();
    printf("test4()\n");
    test4();
    printf("test5()\n");
    test5();
    return 0;
}
