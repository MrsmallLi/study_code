/*************************************************************************
	> File Name: 1.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 27 Jan 2025 09:36:28 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int arr[10] = {0};

int main() {
    int max_num = -1, temp = 0;
    for (int i = 0, a; i < 5; i++) {
        cin >> a;
        if (a > max_num) {
            max_num = a;
        } else {
            if (temp) {
                temp += 1;
                break;
            }
            temp = 1;
        }
    }
    if (temp == 1) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
