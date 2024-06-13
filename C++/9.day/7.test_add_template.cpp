/*************************************************************************
	> File Name: 6.test.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 12 Jun 2024 02:22:27 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;


//template是用来引入模板参数的关键字
//typename先理解为定义一个任意类型的变量
template<typename T, typename U>
//在原来返回值的位置写一个auto关键字
//auto是用来推到后置返回值的类型
//因为-> 在参数列表后面，根据代码的执行顺序，那么a和b就可以进行使用
//所以可以用decltype进行判断a + b的返回类型
//然后传给auto进行推断，最后确定返回值类型
auto add(T a, U b) -> decltype(a + b){
    return a + b;
}

//由于是特化，那么我们就确定了参数
//就不需要传入模板参数了，但是也得需要template关键字引入
template<> 
int add(int a, int b) {
    return a + b + 2;  
}

//模板偏特化版本
//当传入的参数是指针类型时的版本
template<typename T, typename U>
auto add(T *a, U *b) -> decltype(*a + *b) {
    cout << "this is piantehua" << endl;
    return *a + *b;
}

int main() {
    //int也有可以当作类来使用
    //所以任意类型都有构造函数
    int num = int(1);
    cout << add(1, 2) << endl; //那么这里的结果应该是 1 + 2 + 2 = 5
    cout << add(2.1, 3.3) << endl;
    string a = "hello", b = "world";
    cout << add(a, b) << endl;
    cout << add(1, 1.2) << endl;
    cout << add(1.2, 1) << endl;

    int c = 10, d = 20;
    cout << add(&c, &d) << endl;
    return 0;
}
