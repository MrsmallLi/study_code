/*************************************************************************
	> File Name: 4.envOpt.c
	> Author: 
	> Mail: 
	> Created Time: Thu 23 May 2024 06:23:51 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    printf("path value = [%s]\n", getenv("PATH"));

/*
    extern char **environ;
    
    for (int i = 0; environ[i]; i++) {
        printf("%s\n", environ[i]);
    }
*/
    return 0;
}
