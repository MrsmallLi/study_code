/*************************************************************************
	> File Name: 1.htol.c
	> Author: 
	> Mail: 
	> Created Time: Wed 24 Jul 2024 05:46:51 PM CST
 ************************************************************************/

#include <stdio.h>
#include <arpa/inet.h>


int main() {
    int a = 0x12345678;
    printf("%#x\n", a);
    int b = htonl(a);
    printf("%#x\n", b);
    ioctl();
    fcntl;
    return 0;
}
