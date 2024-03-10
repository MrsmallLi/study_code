/*************************************************************************
	> File Name: 1.types.c
	> Author: 
	> Mail: 
	> Created Time: Fri 08 Mar 2024 04:24:19 PM CST
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>


int main() {
    int a = 123, b = 97, c, d;
    c = 100062;
    d = 9651;
    printf("%d %d %d %d\n", a, b, c, d);
    a = 2147483647 + 1;
    printf("%d\n", a);
    printf("INT32_MIN = %d\n", INT32_MIN);
    printf("INT32_MAX = %d\n", INT32_MAX);
    long long e;
    //因为编译器是通过整形进行相加，所以需要在超过整形的范围时需要在数字后面加上LL，让编译器知道现在是长整形计算
    e = 2147483647LL + 1;
    printf("%lld\n", e);
    float f = e + 0.1;
    double ff = e + 0.1;
    printf("float : %f\n", f);
    printf("double : %lf\n", ff);
    return 0;
}

