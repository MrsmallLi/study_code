/*************************************************************************
	> File Name: 14.enum.c
	> Author: 
	> Mail: 
	> Created Time: Mon 25 Mar 2024 09:21:48 PM CST
 ************************************************************************/

#include<stdio.h>
#define P(a, format) {\
    printf("%s = " format "\n", #a, a);\
}

//从上往下进行自增+1
enum Number {
    zero,
    one,
    two = 10,
    three,
    four
};

enum FUNC_DATA {

#ifdef TEST1
    FUNC_test1,
#endif
#ifdef TEST2
    FUNC_test2,
#endif
#ifdef TEST3
    FUNC_test3,
#endif
#ifdef TEST4
    FUNC_test4,
#endif
    //如果上面存在一个函数,那么FUNC_MAX 就会+1
    //说明有存在几个函数
    FUNC_MAX
};

//利用宏定义，定义函数
#define DEFINE_FUNC(name)\
void name() {\
    printf("this function : %s\n", #name);\
}

DEFINE_FUNC(test1);
DEFINE_FUNC(test2);
DEFINE_FUNC(test3);
DEFINE_FUNC(test4);

//函数指针数组
//利用#ifdef来进行对函数指针数组进行存储 
void (*func_arr[FUNC_MAX])() = {
#ifdef TEST1
    test1,
#endif
#ifdef TEST2
    test2,
#endif
#ifdef TEST3
    test3,
#endif
#ifdef TEST4
    test4,
#endif
};

int main() {
    for (int i = 0; i < FUNC_MAX; i++) {
        func_arr[i]();
    }
    enum Number a;
    a = zero;
    P(a, "%d");
    a = one;
    P(a, "%d");
    a = two;
    P(a, "%d");
    a = three;
    P(a, "%d");
    a = four;
    P(a, "%d");
    return 0;
}
