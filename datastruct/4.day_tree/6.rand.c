/*************************************************************************
	> File Name: 6.rand.c
	> Author: 
	> Mail: 
	> Created Time: Fri 19 Apr 2024 04:48:12 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    printf("26\n");
    for (int i = 0; i < 26; i++) {
        printf("%c %d\n", 'a' + i, rand() % 10000);
    }

    return 0;
}
