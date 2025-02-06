/*************************************************************************
	> File Name: 202.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 08 Apr 2024 06:10:39 PM CST
 ************************************************************************/

#include <./my_include.h>
using namespace std;
class s {
public:
    int func(int n) {
        int num = 0;
        while (n) {
            num += pow(n % 10, 2);
            n /= 10;
        }
        return num;
    }
    bool isHappy(int n) {
        int f = n, s = n;
        while (f != 1) {
            f = func(func(f));
            s = func(s);
            if (s == 1) return true;
            if (f == s) return false;
        }
        return true;
    }
};
