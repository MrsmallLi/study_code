/*************************************************************************
	> File Name: 16.bit.c
	> Author: 
	> Mail: 
	> Created Time: Mon 25 Mar 2024 10:25:04 PM CST
 ************************************************************************/

#include<stdio.h>

#define P(a, format) {\
    printf("%s = " format "\n", #a, a);\
}

struct A {
    unsigned int a:1;//这里的代码说明a变量只用二进制的一位
    unsigned int b:2;//同理
    unsigned int c:3;
    //一共用了6位二进制
};


int main() {
    //由于struct A最大对齐值的4
    //所以struct A占4字节
    P(sizeof(struct A), "%lu");//4
    struct A p;
    p.a = 15;
    p.b = 15;
    p.c = 15;
    //如果超出了占位的取值范围，那么只取后面几位，也就是低位
    P(p.a, "%d");//因为只占用一位，所以对应二进制是1,输出结果结果为1
    P(p.b, "%d");//因为只占用两位，所以对应二进制是11,输出结果结果为3
    P(p.c, "%d");//因为只占用三位，所以对应二进制是111,输出结果结果为7
    return 0;
}
