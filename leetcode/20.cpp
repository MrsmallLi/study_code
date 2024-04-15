/*************************************************************************
	> File Name: 20.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 10 Apr 2024 02:53:00 PM CST
 ************************************************************************/

#include <./my_include.h>
using namespace std;

class Solution {
    public :
    bool isValid(string s) {
        stack<char> st;
        for (char i : s) {
            if (i == ']') {
                if (st.empty() || st.top() != '[') return false;
                else st.pop();
            } else if (i == ')')  {
                if (st.empty() || st.top() != '(') return false;
                else st.pop();
            } 
            else if (i == '}') {
                if (st.empty() || st.top() != '{') return false;
                else st.pop();
            }
            else st.push(i);
        }
        if (st.empty()) return true;
        return false;
    }
};
