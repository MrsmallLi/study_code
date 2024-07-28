/*************************************************************************
	> File Name: 13.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 17 Jun 2024 02:01:41 PM CST
 ************************************************************************/

#include "./my_include.h"
using namespace std;



class Solution {
public:
    int func(char c) {
        if (!c)return 0;
        int ret = 0;
        switch(c) {
            case 'V': ret = 5; break;
            case 'L': ret = 50; break;
            case 'D': ret = 500; break;
            case 'M': ret = 1000; break;
        }
        return ret;
    }
    
    void func_1(string s, int *k, long long *num) {
        int i = *k;
        switch (s[i]) {
            case 'I': {
                *num += 1; 
                *k = i + 1;
                func_1(s, k, num);
            } break;
            case 'X': {
                *num += 10; 
                *k = i + 1;
                func_1(s, k, num);
            } break;
            case 'C': {
                *num += 100; 
                *k = i + 1;
                func_1(s, k, num);
            } break;
            default: break;
        }
        return ;
    }

    int romanToInt(string s) {
        long long ans = 0;
        for (int i = 0; s[i]; i++) {
            long long num = 0;
            switch (s[i]) {
                case 'I': {
                    num += 1; 
                    func_1(s, &i, &num);
                    int next = func(s[i + 1]);
                    if (next) num = next - num, i++;
                } break;
                case 'X': {
                    num += 10; 
                    func_1(s, &i, &num);
                    int next = func(s[i + 1]);
                    if (next) num = next - num, i++;
                } break;
                case 'C': {
                    num += 100; 
                    func_1(s, &i, &num);
                    int next = func(s[i + 1]);
                    if (next) num = next - num, i++;
                } break;
                default: num += func(s[i]);
            }
        }
        return 0;
    }
};





