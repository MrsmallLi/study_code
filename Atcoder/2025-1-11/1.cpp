/*************************************************************************
	> File Name: 1.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 11 Jan 2025 08:01:11 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;


int main() {
    char s[1005];
    cin >> s;
    for (int i = 0; i < 4; i++) {
        if (!i) {
            if (s[0] >= 'A' && s[0] <= 'Z') continue;
            s[0] -= 32;
            continue;
        }
        switch (i) {
            case 1: {
                s[i] = 'U';
            } break;
            case 2: {
                s[i] = 'P';
            } break;
            case 3: {
                s[i] = 'C';
            } break;
        }
    }
    for (int i = 0; i < 4; i++) cout << s[i];
    cout << endl;
    return 0;
}
