/*************************************************************************
	> File Name: 922.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 22 Feb 2025 03:30:46 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;


int num[15] = {0};

int main() {
    for (int i = 0; i <= 9; i++) {
        int a;
        cin >> a;
        num[i] += a;
    }
    string str;
    for (int i = 9; i >= 0; i--) {
        string now_str;
        while (num[i]) {
            now_str = now_str + to_string(i);
            num[i] -= 1;
        }
        str += now_str;
    }
    cout << str << endl;

    return 0;
}
