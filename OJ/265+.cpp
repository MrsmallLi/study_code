/*************************************************************************
	> File Name: 265+.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 21 Oct 2024 02:44:37 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <stack>
using namespace std;
#define MAX_N 10000

string str;
int ind[MAX_N + 5] = {0};
stack<int> s;


int main() {
    cin >> str;
    for (int i = 0; str[i]; i++) {
        ind[i] = -1;
        switch (str[i]) {
            case '(':
            case '[':
            case '{': {
                s.push(i); break;
            }
            case ')':{
                if (!s.empty() && str[s.top()] == '(') {
                    ind[s.top()] = i;
                    s.pop();
                    break;
                } else {
                    s.push(i);
                    break;
                }
            }
            case ']':{
                if (!s.empty() && str[s.top()] == '[') {
                    ind[s.top()] = i;
                    s.pop();
                    break;
                } else {
                    s.push(i);
                    break;
                } 
            }
            case '}':{
                if (!s.empty() && str[s.top()] == '{') {
                    ind[s.top()] = i;
                    s.pop();
                    break;
                } else {
                    s.push(i);
                    break;
                } 
            }
        }
    }
    int len = 0, i = 0, ans = 0;
    while (str[i]) {
        if (ind[i] != -1) {
            len += ind[i] - i + 1;
            i = ind[i] + 1;
        } else {
            i += 1;
            len = 0;
        }
        ans = max(ans, len);
    }
    cout << ans << endl;
    return 0;
}
