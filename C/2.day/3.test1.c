/*************************************************************************
	> File Name: 11.test1.c
	> Author: 
	> Mail: 
	> Created Time: Wed 13 Mar 2024 06:28:44 PM CST
 ************************************************************************/

#include<stdio.h>


int main() {
    int x;
    //利用scanf的返回值，scanf的返回值是成功读入了多少个参数
    //而EOF对应整形值是-1,EOF也称文件结束符
    //scanf读到文件末尾时，就会返回-1
    //就会结束循环
    while (scanf("%d", &x) != EOF) {
        printf("2 * x = %d\n", x * 2);
    }
    return 0;
}
