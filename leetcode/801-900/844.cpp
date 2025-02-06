/*************************************************************************
	> File Name: 844.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 11 Apr 2024 02:49:06 PM CST
 ************************************************************************/

#include <./my_include.h>
using namespace std;

class Solution {
public:
    string get_new_str(string s) {
        string str;
        for (int i = 0; s[i]; i++) {
            if (s[i] != '#') str.push_back(s[i]);
            else if (!s.empty())str.pop_back();
        }
        return str;
    }

    bool backspaceCompare(string s, string t) {
        return get_new_str(s) == get_new_str(t);
    }
};
