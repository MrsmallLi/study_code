/*************************************************************************
	> File Name: A.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 01 Mar 2025 08:01:38 PM CST
 ************************************************************************/

#include <iostream>
#include <climits>
using namespace std;


int main() {
    int n;
    cin >> n;
    int pre = INT_MIN;
    int flag = 1;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a > pre) {
            pre = a;
            continue;
        }
        flag = 0;
    }
    if (flag) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }



    return 0;
}
