/*************************************************************************
	> File Name: 265.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 12 Apr 2024 11:41:08 AM CST
 ************************************************************************/

#include <iostream>
#include <stack>
using namespace std;
#define MAX_N 10000
char str[MAX_N + 5];
int arr[MAX_N + 5];
stack<int> s;

int main() {
    cin >> (str + 1);
    for (int i = 1; str[i]; i++) {
        switch (str[i]) {
            case '(': 
            case '[':
            case '{': {
                s.push(i);
            } break;
            case ')': {
                if (!s.empty() && str[s.top()] == '(') {
                    arr[s.top()] = i;
                    s.pop();
                } else {
                    s.push(i);
                }
            } break;
            case ']': {
                if (!s.empty() && str[s.top()] == '[') {
                    arr[s.top()] = i;
                    s.pop();
                } else {
                    s.push(i);
                }
            } break;
            case '}': {
                if (!s.empty() && str[s.top()] == '{') {
                    arr[s.top()] = i;
                    s.pop();
                } else {
                    s.push(i);
                }
            } break;
        }
    }
    int ans = 0, temp = 0;
    for (int i = 1; str[i];) {
        if (arr[i]) {
            temp += arr[i] - i + 1;
            i = arr[i] + 1;
        } else {
            i++;
            temp = 0;
        }
        ans = max(temp, ans);
    }
    cout << ans << endl;
    return 0;
}
