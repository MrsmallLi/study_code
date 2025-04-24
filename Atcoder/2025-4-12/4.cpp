/*************************************************************************
	> File Name: 4.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 12 Apr 2025 08:36:46 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 200000

char ans[MAX_N + 5];

int main() {
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    int cnt = 0, num = 0;
    for (int i = 0; i < n; i++)  {
        switch (str[i]) {
            case '.': {
                ans[i] = '.';
            } break;
            case 'o': {
                ans[i] = 'o';
                if (i + 1 < n && str[i + 1] == '?') {
                    ans[i + 1] = '.';
                }
                cnt += 1;
            } break;
            case '?': {
                if (ans[i]) continue;
                if (i + 1 < n && str[i + 1] == 'o') {
                    ans[i] = '.';
                } else {
                    num += 1;
                    ans[i] = '?';
                }
            } break;
        }
    }
    for (int i = 0; i < n; i++) {
    }
    return 0;
}
