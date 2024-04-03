/*************************************************************************
	> File Name: 2.file_access.c
	> Author: 
	> Mail: 
	> Created Time: Sun 31 Mar 2024 10:46:50 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void r_access() {
    //以只读方式打开data.txt
    FILE *fp = fopen("./data.txt", "r");
    if (fp == NULL) {
        printf("r : failed to open file\n");
        exit(1);
    }
    char s[100];
    //读取文件中的内容
    fscanf(fp, "%[^\n]", s);
    printf("r : s = %s\n", s);
    fclose(fp);
    fp = fopen("temp.txt", "r");
    //如果以r模式打开不存在的文件，那么会打开失败返回NULL空地址
    if (fp == NULL) {
        printf("r : open erroe\n");
    }
    //使用过后记得关闭
    return ;
}

void rand_file_name(char *file_name, int n) {
    for (int i = 0; i < n; i++) {
        file_name[i] = rand() % 26 + 'a';
    }
    file_name[n] = 0;
    //在文件名末尾加上.txt
    //strcat作用将第一个参数的后面加上第二个参数的字符串
    strcat(file_name, ".txt");
    return ;
}

void w_access() {
    //测试存在的文件
    FILE *fp = fopen("data.txt", "w");
    if (fp == NULL) {
        printf("w : failed to open file\n");
        exit(1);
    }
    //向文件中输入内容，并且在输入前会清空文件中的内容
    fprintf(fp, "w :hahahahah, world\n");
    fprintf(fp, "hello nihao\n");
    fclose(fp);
    char file_name[100] = {0};
    rand_file_name(file_name, 10);
    //当用w打开不存在的文件时，会创建新的文件，并且文件名就是fopen的第一个参数
    printf("w : open new name : %s\n", file_name);
    fp = fopen(file_name, "w");
    fclose(fp);
    return ;
}

void r_plus_access() {
    //现在打开data.txt可以对文件进行读取和写入内容
    FILE *fp = fopen("data.txt", "r+");
    if (fp == NULL) {
        printf("r+ : failed to open file\n");
        exit(1);
    }
    char s[100];
    fscanf(fp, "%s", s);
    printf("r+ : s = %s\n", s);
    //在r+模式下写入内容，默认会在文件末尾进行写入
    fprintf(fp, "000000");
    fclose(fp);
    //打开不存在的文件
    fp = fopen("data2.txt", "r+");
    if (fp == NULL) {
        printf("r+ : open error\n");
    }
    return ;
}

void w_plus_access() {
    //测试存在的文件
    FILE *fp = fopen("data.txt", "w+");
    if (fp == NULL) {
        printf("w : failed to open file\n");
        exit(1);
    }
    //向文件中输入内容，并且在输入前会清空文件中的内容
    fprintf(fp, "w+ :hahahahah, world\n");
    char s[100] = {0};
    fscanf(fp, "%s", s);
    //对于这里为什么读取的内容为空，在后续代码会进行解释
    printf("w+ : %s\n", s);
    fclose(fp);
    char file_name[100] = {0};
    rand_file_name(file_name, 10);
    //当用w+打开不存在的文件时，会创建新的文件，并且文件名就是fopen的第一个参数
    printf("w+ : open new name : %s\n", file_name);
    fp = fopen(file_name, "w+");
    fclose(fp);
    return ;
}

int main() {
    srand(time(0));
    r_access();
    w_access();
    r_plus_access();
    w_plus_access();
    return 0;
}
