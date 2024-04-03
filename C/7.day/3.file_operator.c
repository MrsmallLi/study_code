/*************************************************************************
	> File Name: 3.file_operator.c
	> Author: 
	> Mail: 
	> Created Time: Tue 02 Apr 2024 03:07:51 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//定义一个文件名
const char *file_name = "data3.txt";
//定义一个整形数组，用来写入文件的数据
#define MAX_N 10000
int arr[MAX_N + 5], n = 0;//n代表存储了多少个数据

void output_arr(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        //如果不理解这句代码可以看看之前逻辑关系的知识点
        //和 if (i) printf(" ");的功能一样
        i && printf(" ");
        printf("%d", arr[i]);
    }
    putchar(10);
    return ;
}

//1.写入文件
void output_to_file(int *arr, int n) {
    //需要在文件中追加写入内容，所以打开模式用 a
    FILE *fp = fopen(file_name, "a");
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d ", arr[i]);
    }
    //打开文件，一定要记得关闭
    fclose(fp);
    return ;
}

//返回值代表读入了多少个整形
//2.从文件中读取数据
int read_from_file(int *arr) {
    int i = 0;
    //由于要向文件中读取数据，所以打开模式用r
    FILE *fp = fopen(file_name, "r");
    //如果文件打开失败，说明读取0个数据返回0
    if (fp == NULL) return 0;
    //循环读入，fscanf的返回值和scanf的返回值一样
    //当读到文件末尾时fscanf会返回EOF，也就是-1
    while (fscanf(fp, "%d", arr + i) != EOF) i++;
    //记得关闭
    fclose(fp);
    return i;
}

//3.清空文件内容
void clear_file() {
    //在打开模式中w和w+模式打开文件都会得到一个清空的文件
    FILE *fp = fopen(file_name, "w");
    fclose(fp);
    return ;
}

//将功能封装为函数是为了减少记忆负担,减小代码出错概率
//测试写入功能是否成功
int output_test() {
    //获取随机种子
    srand(time(0));
    //进行对数组赋值
    for (n = 0; n < 10; n++) {
       arr[n] = rand() % 100;
    }
    //输出数组
    output_arr(arr, n);
    output_to_file(arr, n);
    return 0;
}

//测试从文件中读取数据是否成功
int read_test() {
    n = read_from_file(arr);
    output_arr(arr, n);
    printf("total read %d numbers\n", n);
    return 0;
}


//可以看到我的主函数的代码量非常少,我的功能都封装在函数中
//通过每个函数之间的调用,可以一步一步的吧思路理清
int main() {
    output_test();
    read_test();
    clear_file();
    return 0;
}
