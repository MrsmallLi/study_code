/*************************************************************************
	> File Name: 2.file_access.c
	> Author: 
	> Mail: 
	> Created Time: Sun 31 Mar 2024 10:46:50 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void r_access() {
    //以只读方式打开data.txt
    FILE *fp = fopen("./data.txt", "r");
    if (fp == NULL) {
        printf("failed to open file\n");
        exit(1);
    }
    char s[100];
    //读取文件中的内容
    fscanf(fp, "%[^\n]", s);
    printf("s = %s\n", s);
    fclose(fp);
    return ;
}


int main() {
    r_access();


    return 0;
}
