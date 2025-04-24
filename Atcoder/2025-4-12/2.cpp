/*************************************************************************
	> File Name: 2.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 12 Apr 2025 08:09:06 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


int main() {
    int n;
    cin >> n;
    int flag = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        if (str == "login") {
            flag = 1;
        } else if (str == "logout"){
            flag = 0; 
        } else if (str == "private") {
            if (!flag) cnt += 1;
        }        
    }
    cout << cnt << endl;
    return 0;
}
