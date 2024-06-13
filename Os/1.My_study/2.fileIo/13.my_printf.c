/*************************************************************************
	> File Name: 13.my_printf.c
	> Author: 
	> Mail: 
	> Created Time: Sun 26 May 2024 04:19:57 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#define BUFFER_SIZE 1024

void my_scanf(const char *format, ...) {
    char buffer[BUFFER_SIZE] = {0};
    va_list args;
    va_start(args, format);
    int i = 0;
    ssize_t n = read(STDIN_FILENO, buffer, BUFFER_SIZE);
    vsscanf(buffer, format, args);
    va_end(args);
    return ;
}

void my_printf(const char *format, ...) {
    char buffer[BUFFER_SIZE] = {0};
    va_list args;
    va_start(args, format);
    ssize_t n = vsnprintf(buffer, BUFFER_SIZE, format, args);
    va_end(args);
    write(STDOUT_FILENO, buffer, n);
    return ;
}

int main() {
    int a, b;
    my_scanf("%d%d", &a, &b);
    my_printf("a = %d, b = %d\n", a, b);
    return 0;
}
