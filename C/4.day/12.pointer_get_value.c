/*************************************************************************
	> File Name: 12.pointer_get_value.c
	> Author: 
	> Mail: 
	> Created Time: Thu 21 Mar 2024 09:04:02 PM CST
 ************************************************************************/

#include<stdio.h>



int main() {
    int n = 0x61626364;
    int *int_p = &n;
    char *p = (char *)&n;
    printf("*int_p = %d\n", *int_p);
    printf("*(p + 0) = %c\n", *(p + 0));
    printf("*(p + 1) = %c\n", *(p + 1));
    printf("*(p + 2) = %c\n", *(p + 2));
    printf("*(p + 3) = %c\n", *(p + 3));
    return 0;
}
