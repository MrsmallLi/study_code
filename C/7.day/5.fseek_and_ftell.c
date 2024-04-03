/*************************************************************************
	> File Name: 5.fseek_and_ftell.c
	> Author: 
	> Mail: 
	> Created Time: Tue 02 Apr 2024 06:49:46 PM CST
 ************************************************************************/

#include<stdio.h>



int main() {
    FILE *fp = fopen("data5.txt", "w");
    //输出当前文件指针的位置，通过ftell进行获取
    printf("ftell(fp) = %ld\n", ftell(fp));
    fprintf(fp, "1234567890");
    printf("after fprintf 1234567890 ftell(fp) = %ld\n", ftell(fp));
    //设置文件指针距离文件开头正向偏移2个字节的位置
    fseek(fp, 2, SEEK_SET);
    printf("after fseek(2) ftell(fp) = %ld\n", ftell(fp));
    fprintf(fp, "abc");
    printf("after fprintf abc ftell(fp) = %ld\n", ftell(fp));
    return 0;
}
