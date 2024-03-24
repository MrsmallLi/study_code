/*************************************************************************
	> File Name: 22.pointer_add_one.c
	> Author: 
	> Mail: 
	> Created Time: Thu 21 Mar 2024 08:08:20 PM CST
 ************************************************************************/

#include<stdio.h>


int main() {
    //1
    int a, *p1 = &a;
    double b, *p2 = &b;
    //可以发现地址+1，是根据类型对应字节大小进行＋的
    printf("&a = %p\n", &a);
    printf("p1 + 0 = %p\n", p1 + 1);
    printf("p1 + 1 = %p\n", p1 + 2);
    printf("p1 + 2 = %p\n", p1 + 3);
    printf("p1 + 3 = %p\n", p1 + 4);
    printf("&b = %p\n", &b);
    printf("p2 + 0 = %p\n", p2 + 1);
    printf("p2 + 1 = %p\n", p2 + 2);
    printf("p2 + 2 = %p\n", p2 + 3);
    printf("-------------------\n");
    //2
    int arr[4] = {1, 2, 3, 4};
    int *p3 = arr;
    for (int i = 0; i < 4; i++) {
        //同通过测试发现，p3 + i 和 &arr[i] + i的地址一样
        printf("p3 + %d = %p\n", i, p3 + i);
        printf("&arr[0] + %d = %p\n", i, &arr[0] + i);
        //通过测试会发现，p3[i]和*(p3 + 1)效果一样
        printf("p3[%d] = %d\n", i, p3[i]);
        printf("*(p3 + %d) = %d\n", i, *(p3 + i));
    }
    printf("-------------------\n");
    //3
    int *p4[10];//指针数组, 每个位置可以存储一个地址
    int arr1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < 10; i++) {
        p4[i] = &arr1[i];
        printf("*p[%d] = %d, arr1[%d] = %d\n", i, *p4[i], i, arr1[i]);
    }
    printf("-------------------\n");
    //4 
    int (*p5)[10] = 0x0;//表示p4指向10个整形元素的指针
    int arr2[30][10];//arr[i]代表10个整形元素
    p5 = arr2;//p4 + 1也相当于跳10个整形元素,就相当于p4 + 4 == arr[1];
    printf("p5 + 0 = %p\n", p5 + 0);
    printf("p5 + 1 = %p\n", p5 + 1);
    printf("p5 + 2 = %p\n", p5 + 2);
    return 0;
}
