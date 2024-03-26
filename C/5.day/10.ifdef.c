/*************************************************************************
	> File Name: 10.ifdef.c
	> Author: 
	> Mail: 
	> Created Time: Mon 25 Mar 2024 03:15:00 PM CST
 ************************************************************************/

#include<stdio.h>


#ifdef DEBUG
int a = 1;
#else 
int a = 2;
#endif

int main() {
    printf("a = %d\n", a);

    return 0;
}
