/*************************************************************************
	> File Name: 1.upper.c
	> Author: 
	> Mail: 
	> Created Time: Thu 23 May 2024 07:18:38 PM CST
 ************************************************************************/

#include <stdio.h>
#include <ctype.h>

int main() {

    int ch;
    while (~(ch = getchar())) {
        putchar(toupper(ch));
    } 


    return 0;
}
