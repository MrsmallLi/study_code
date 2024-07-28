/*************************************************************************
	> File Name: 2.nonblock.c
	> Author: 
	> Mail: 
	> Created Time: Fri 14 Jun 2024 02:37:41 PM CST
 ************************************************************************/

#include <stdio.h>
#include "../common/commod.h"



int main() {
    int age = 18;
    make_nonblock(0);
    scanf("%d", &age);
    printf("L is %d years old\n", age);
    return 0;
}
