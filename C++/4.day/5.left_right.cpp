/*************************************************************************
	> File Name: 5.left_right.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 19 Apr 2024 10:16:32 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define LEFT_OR_RIGHT(expr) {\
    printf("expr : %s\n", #expr);\
    left_or_right(expr);\
    printf("\n");\
}

void left_or_right(int &&, int);

void left_or_right(int &x, int flag = 1) {
    printf("left value : %d\n", x);
    if (flag) left_or_right(x, 0);
    return ;
}

void left_or_right(int &&x, int flag = 1) {
    printf("right value : %d\n", x);
    //if (flag) left_or_right(move(x), 0);
    if (flag) left_or_right(forward<int &&>(x), 0);
    return ;
}


namespace test1 {
int main() {
    int a = 123;
    //a可以通过单一变量a访问
    //那么他就是左值
    LEFT_OR_RIGHT(a);
    //a + 1是中间产生临时的一个值
    //那么他无法通过单一变量进行访问到
    //那他就是一个右值
    //因为在过了下面这行代码后，我们没有办法进行通过单一变量进行访问到它
    LEFT_OR_RIGHT(a + 1);
    //任何字面量的值都是右值
    LEFT_OR_RIGHT(123);
    //这里a++你带入进去的是a的值
    //然后带入后，a进行了a += 1
    //那么在这行代码之后你无法通过单一变量去访问到之前的a值
    //那么它就是右值
    LEFT_OR_RIGHT(a++);
    //++a带入的是 a += 1的值
    //在这行代码之后,它可以通过单一变量a去访问到这个值
    //那他就是左值
    LEFT_OR_RIGHT(++a);
    //a += 2同理它可以通过变量a去访问到这个值
    LEFT_OR_RIGHT(a += 2);
    return 0;
}
}

int main() {
    //test1::main();
    left_or_right(123);
    return 0;
}
