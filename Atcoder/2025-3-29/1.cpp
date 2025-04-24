/*************************************************************************
	> File Name: 1.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 29 Mar 2025 08:01:50 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


int main() {
    int n;
    cin >> n;
    string str1, str2;
    cin >> str1 >> str2;
    int ans = 0;
    for (int i = 0; str1[i]; i++) {
        if (str1[i] == str2[i]) continue;
        ans += 1;
    }
    cout << ans << endl;
    return 0;
}
