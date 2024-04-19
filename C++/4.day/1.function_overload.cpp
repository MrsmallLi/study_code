/*************************************************************************
	> File Name: 1.function_overload.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 18 Apr 2024 03:02:22 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

//函数名相同，在是每个函数的参数不相同
void output(int x) {
    printf("output int : %d\n", x);
    return ;
}

void output(long long x) {
    printf("output long long : %llX\n", x);
    return ;
}

void output(const char *s) {
    if (!s) {
        printf("output string : nullptr\n");
        return ;
    }
    printf("output string : %s\n", s);
    return ;
}

void output(int x, int y) {
    printf("output double int : %d, %d\n", x, y);
    return ;
}
//如果调用这个函数时，没有传入参数3，也就是c
//那么c的默认值就为123，并且程序不会编译不通过
void output(int a, char b, int c = 123) {
    printf("output a = %d, b = %c, c = %d\n", a, b, c);
    return ;
}

//如果这里没有第三个参数，那么就会造成编译报错
//因为没有办法通过返回值类型进行区分重载类型
//也就是没有办法区分和上面的double int进行区分
const char *output(int a, int b, char c) {
    printf("output a = %d, b = %d, c = %c\n", a, b, c);
    return "yes";
}


int main() {
    output(3);//这里匹配的是int类型的output
    //在数字后面加上LL 表示这个数字是longlong类型
    output(3LL);//这里匹配的是longlong类型的output
    output("hello world");//匹配参数为char *的output
    output(3, 4);//匹配参数为两个int类型的output
    output(3LL, 4);//近似匹配了两个int类型的output
    //下面这个output(NULL),他会匹配到int类型
    //NULL可以表示成0值
    //然后它也可以表示成一个地址，然后它又是0值的地址，地址有64位也就是8字节，那他也会匹配long long类型
    //然后还表示一个空地址，还会匹配到char *类型
    //output(NULL);
    //而在C++中 nullptr只表示空地址，这样他就会精确匹配对应的函数
    output(nullptr);
    output(12, 'p');
    cout << output(3, 4, 'c') << endl;
    return 0;
}
