/*************************************************************************
	> File Name: 2.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 15 Feb 2025 08:14:01 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;


int main() {
    string str;
    cin >> str;
    int n = str.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] != 'A') continue;
        for (int j = i + 1; j < n; j++) {
            if (str[j] != 'B') continue;
            int k = j + j - i;
            if (k < n && str[k] == 'C') ans += 1;
        }
    }
    cout << ans << endl;
    return 0;
}
