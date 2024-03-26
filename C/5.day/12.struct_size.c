/*************************************************************************
	> File Name: 12.struct_size.c
	> Author: 
	> Mail: 
	> Created Time: Mon 25 Mar 2024 05:07:10 PM CST
 ************************************************************************/

#include<stdio.h>

#ifdef STRUCT_A

struct A {
    char a;
    int b;
    short c;
}; 
void set_buff(char *buff, void *head, void *begin, void *end, char ch) {
    //循环判断条件, 当起始位置等于结束位置时结束
    while (begin != end) {
        //这里变量的起始位置减去结构体起始的位置可以得到索引下标
        buff[begin - head] = ch;
        begin += 1;
    }
    return ;
}

void output_struct() {
    //开person结构体个大小的字符串
    int n = sizeof(struct A), len = 0;
    char buf[n];
    //初始化字符串内容为.
    for (int i = 0; i < n; i++) buf[i] = '.';
    //打印对应位置索引
    for (int i = 0; i < n; i++) {
        len += printf("%3d", i);
    }
    printf("\n");
    //间隔符
    for (int i = 0; i < len; i++) printf("-");
    printf("\n");
    //定义一个结构体变量
    struct A hug;
    //name有20个字节大小所以从起始位置到结尾有20,并用'n'表示所占位置
    set_buff(buf, &hug.a, &hug.a, 1 + (void *)&hug.a, 'a');
    set_buff(buf, &hug.a, &hug.b, 4 + (void *)&hug.b, 'b');
    set_buff(buf, &hug.a, &hug.c, 2 + (void *)&hug.c, 'c');
    for (int i = 0; i < n; i++) {
        printf("%3c", buf[i]);
    }
    printf("\n");
    return ;
}

#endif

int main() {
    output_struct();
    return 0;
}
