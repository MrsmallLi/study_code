/*************************************************************************
	> File Name: 7.my_errno.c
	> Author: 
	> Mail: 
	> Created Time: Mon 27 May 2024 04:20:36 PM CST
 ************************************************************************/

#include <stdio.h>
#include "6.my_errno.h"

const char *my_strerror(int errnum) {
    switch (errnum) {
        case MY_SUCCESS : return "Heart Open successfully";
        case MY_NO_ACCESS : return "No access to her heart";
        case MY_HEART_LOCKED : return "Her Heart is locked"; 
        default : return "Unknown felling";
    }
}

