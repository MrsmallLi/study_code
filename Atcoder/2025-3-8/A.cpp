/*************************************************************************
	> File Name: A.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 08 Mar 2025 07:56:27 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


int main() {
    int n;
    int pre = -1, cnt = 1;
    int flag = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (num == pre) {
            cnt = cnt + 1;
            if (cnt >= 3) flag = 1;

            pre = num;
        } else {
            cnt = 1;
            pre = num;
        }
    }
    if (flag) { 
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
