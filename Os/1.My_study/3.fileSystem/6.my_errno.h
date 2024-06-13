/*************************************************************************
	> File Name: 6.my_errno.h
	> Author: 
	> Mail: 
	> Created Time: Mon 27 May 2024 04:12:03 PM CST
 ************************************************************************/

#ifndef _6.MY_ERRNO_H
#define _6.MY_ERRNO_H

#define MY_SUCCESS 0
#define MY_NO_ACCESS 1
#define MY_HEART_LOCKED 2

extern int errnum;

const char *my_strerror(int errnum);

void my_perror(const char *prefix);
#endif
