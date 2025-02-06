/*************************************************************************
	> File Name: 202+.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 16 Jan 2025 05:47:47 PM CST
 ************************************************************************/

#include <iostream>
#include <map>
using namespace std;
/*
class Solution {
public:
    long long fun(int n) {
        long long temp = 0;
        while (n) {
            int s = n % 10;
            n /= 10;
            temp += s * s;
        }
        return temp;
    }
    bool isHappy(int n) {
        map<int, int> mp;    
        while (mp.find(n) == mp.end()) {
            if (n == 1) return true;
            mp[n] += 1;
            n = fun(n);
        }
        return false;
    }
};
**/

class Solution {
public:
    long long fun(int n) {
        long long temp = 0;
        while (n) {
            int s = n % 10;
            n /= 10;
            temp += s * s;
        }
        return temp;
    }
    bool isHappy(int n) {
        int f = n, s = n;
        while (f != s) {
            f = fun(fun(f));
            s = fun(s);
            if (f == 1) return true;
        }
        return false;
    }
};;
