/*************************************************************************
	> File Name: 4.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 22 Feb 2025 09:09:39 PM CST
 ************************************************************************/

#include<iostream>
#include <stack>
using namespace std;

stack<char> st;

int main() {
    string s;
    cin >> s;
    int flag = 1;
    for (int i = 0; flag && s[i]; i++) {
        switch (s[i]) {
            case '(':
            case '[': 
            case '{':  {
                st.push(s[i]);
            } break;
            case ')':{
                if (!st.empty() && st.top() == '(') st.pop();
                else flag = 0;
            } break;
            case ']':{
                if (!st.empty() && st.top() == '[') st.pop();
                else flag = 0;
            } break;
            case '}':{
                if (!st.empty() && st.top() == '{') st.pop();
                else flag = 0;
            } break;
        }
    }
    if (flag && !st.size()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
