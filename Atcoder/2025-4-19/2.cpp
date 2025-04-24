/*************************************************************************
	> File Name: 2.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 19 Apr 2025 08:12:21 PM CST
 ************************************************************************/

#include <deque>
#include <iostream>
using namespace std;


int main() {
    deque<int> dq;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a;
        if (a == 1) {
            cin >> b;
            dq.push_back(b);
        } else {
            cout << dq.front() << endl;
            dq.pop_front();
        }
    }

    return 0;
}
