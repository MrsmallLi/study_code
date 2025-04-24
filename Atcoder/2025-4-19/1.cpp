/*************************************************************************
	> File Name: 1.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 19 Apr 2025 08:09:42 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;



int main() {
    string str;
    cin >> str;
    string ans;
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') continue;
        ans.push_back(str[i]);
    }
    cout << ans << endl;




    return 0;
}
