/*************************************************************************
	> File Name: 9.math.c
	> Author: 
	> Mail: 
	> Created Time: Sun 10 Mar 2024 09:34:03 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    //double 用%lf展位符，int 用%d占位符
    printf("pow(2, 3) = %lf\n", pow(2.0, 3.0));
    printf("sqrt(2) = %lf\n", sqrt(2));
    printf("ceil(4.1) = %lf\n", ceil(4.1));
    printf("floor(4.9) =  %lf\n", floor(4.9));
    printf("abs(-9) = %d\n", abs(-9));
    printf("fabs(-4.56) = %lf\n", fabs(-4.56));
    printf("acos(-1) = %lf\n", acos(-1));
    return 0;
}

