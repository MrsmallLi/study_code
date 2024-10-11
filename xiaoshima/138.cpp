/*************************************************************************
	> File Name: 138.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 10 Oct 2024 03:02:29 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;



int main() {
    int n;
    cin >> n;
    int max_len = 0, pre_num, len;
    cin >> pre_num;
    max_len = 1;
    len = 1;
    for (int i = 1, num; i < n; i++) {
        cin >> num;
        if (pre_num == num) {
            len += 1;
        } else {
            len = 1;
            pre_num = num;
        }
        max_len = max(max_len, len);
    }
    cout << max_len << endl;
    return 0;
}
