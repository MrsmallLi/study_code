/*************************************************************************
	> File Name: 16.memory.c
	> Author: 
	> Mail: 
	> Created Time: Fri 22 Mar 2024 03:49:02 PM CST
 ************************************************************************/

#include<stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void get_value(int *arr) {
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 100;
    }
    return ;
}

void output(int *arr, int n) {
    for (int i = 0; i < 10; i++) {
        if (i == 5) printf("\n");
        else i && printf(" ");
        printf("arr%d[%d] = %.2d", n, i, arr[i]);
    }
    printf("\n-------------------------\n");
    return ;
}

int main() {
    srand(time(0));
    //利用malloc开辟40个字节大小的空间，int为4字节，乘10那就是40个字节大小
    //由于malloc返回的是void *类型的地址然后
    //需要强转为int *类型的地址
    //让后赋值给一个指针变量
    //然后指针变量就可以当作拥有10个int类型的元素进行使用
    //也就是int类型的数组，然后大小为10
    int *arr1 = (int *)malloc(sizeof(int) * 10);
    get_value(arr1);
    output(arr1, 1);
    //使用方法和malloc差不多
    //但是calloc会将每个字节初始化为0
    int *arr2 = (int *)calloc(sizeof(int), 10);
    output(arr2, 2);
    get_value(arr2);
    output(arr2, 2);
    //因为你是在堆区借用的一块区域
    //所以在不使用后需要还回去
    //因为你不还回去，系统就一直以为你在占用这块区域
    //所以在使用后必须要换回
    free(arr1);
    free(arr2);

    char s1[100] = "hello world";
    char s2[100];
    char s3[100];
    //第一个参数目标地址
    //第二个参数被copy地址
    //第三个参数copy字节数量
    //为什么要多一个字节,因为字符串还有一个\0
    memcpy(s2, s1, 12);
    memmove(s3, s1, 12);
    printf("s2 = %s\n", s2);
    printf("s3 = %s\n", s3);
    //这里需要使用到copy功能，建议用memmove
    //因为在copy时内存重叠，memcpy可能会造成错误
    //而memmove会避免这种情况，所以建议使用memmove
    memcpy(s2 + 4, s2, 12);
    memmove(s3 + 4, s3, 12);
    printf("s2 = %s\n", s2);
    printf("s3 = %s\n", s3);
    return 0;
}
