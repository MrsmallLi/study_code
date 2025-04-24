/*************************************************************************
	> File Name: 71A.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 27 Feb 2025 03:03:39 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

#define MAX_N 100

int main() {
    int n;
    string str[MAX_N + 5];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> str[i];
    for (int i = 0; i < n; i++) {
        string out;  
        if (str[i].size() <= 10) {
            cout << str[i] << endl;
            continue;
        }
        int len = str[i].size() - 2;
        out = str[i][0] + to_string(len) + str[i][str[i].size() - 1];
        cout << out << endl;
    }
    return 0;
}
