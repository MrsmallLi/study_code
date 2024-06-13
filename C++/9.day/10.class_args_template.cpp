/*************************************************************************
	> File Name: 10.class_args_template.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 12 Jun 2024 04:11:59 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

//基础模板声明
//因为进行偏特化处理时或者特化处理时需要基础模板
template<int n, typename ...ARGS>
class ARG_imag;

//偏特化模板递归
template<int n, typename T, typename ...Rest>
class ARG_imag<n, T, Rest...>{
public :
    //进行递归，直到找到需要的层数
    typedef typename ARG_imag<n - 1, Rest...>::thisT thisT;
};

//偏特化模板递归出口
//当n等于0时，说明到达需求层数，进行递归结束
template<typename T, typename ...Rest>  
class ARG_imag<0, T, Rest...> {
public :
    typedef T thisT;
};

//进行封装
//用户调用的是ARG
template<int n, typename ...ARGS>
class ARG {
public :
    typedef typename int g;
    typedef typename ARG_imag<n, ARGS...>::thisT getT;
};


int main() {
    //取到第一层中的int
    ARG<0, int, double, float, char>::getT a = 123;
    //取到第二层中的double
    ARG<1, int, double, float, char>::getT b = 12.3;
    //取到第三层中的float
    ARG<2, int, double, float, char>::getT c = 123.3;
    //取到第四层中的char
    ARG<3, int, double, float, char>::getT e = 'c';
    cout << "sizeof(a) = " << sizeof(a) << " a = " << a << endl;
    cout << "sizeof(b) = " << sizeof(b) << " b = " << b << endl;
    cout << "sizeof(c) = " << sizeof(c) << " c = " << c << endl;
    cout << "sizeof(e) = " << sizeof(e) << " e = " << e << endl;
    return 0;
}
