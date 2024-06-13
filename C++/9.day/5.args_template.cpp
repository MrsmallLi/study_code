/*************************************************************************
	> File Name: 5.args_template.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 11 Jun 2024 06:27:27 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

template<typename T>
void print(const T &a) {
    cout << a << endl;
    return ;
}

template<typename T, typename ...ARGS>
void print(const T &a, ARGS ...args) {
    cout << a << " ";
    print(args...);
    return ;
}


template<int n, typename T, typename ...ARGS>
class ARG {
public :
    typedef typename ARG<n - 1, ARGS...>::getT getT;
    typedef ARG<n - 1, ARGS...> N;
};


//模板变参列表递归边界版
//使用的是模板特化
template<typename T, typename ...ARGS>
class ARG<0, T, ARGS...> {
public :
    typedef T getT;
};

template<typename T>
class ARG<0, T> {
public :
    typedef T getT;
    typedef T finalT;
};


//声明一个模板类，原始版本，不进行定义
//为了对于下面模板类的特化不出现编译错误
template<typename T, typename ...ARGS> class Test;

//特化版本
//使Test类使用起来更像函数
template<typename T, typename ...ARGS>
class Test<T(ARGS...)>{
public :
    T operator()(typename ARG<0, ARGS...>::getT a, typename ARG<1, ARGS...>::N::finalT b) {
        return a + b;
    }
};


int main() {
    print(123, 23.5, "hello world", '0');
    Test<int(double, float)> d;
    cout << d(2.3, 4.5) << endl;
    return 0;
}
