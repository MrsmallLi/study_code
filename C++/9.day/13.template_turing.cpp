/*************************************************************************
	> File Name: 13.template_turing.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 13 Jun 2024 01:17:06 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

template<int i, int x>
class getNextK {
public :
    constexpr static int r = (i * i > x ? 0 : (x % i == 0 ? 1 : 2));
};

template<int i, int x, int k> 
class Test {
public :
    constexpr static int  r = Test<i + 1, x, getNextK<i, x>::r>::r;
};


template<int i, int x>
class Test<i, x, 0> {
public :
    constexpr static int r = 1;
};

template<int i, int x>
class Test<i, x, 1> {
public :
    constexpr static int r = 0;
};

template<int x>
class  is_prime{
public :
    constexpr static int r = Test<2, x, 2>::r;
};


int main() {
    cout << is_prime<5>::r << endl;
    cout << is_prime<1000>::r << endl;

    return 0;
}
