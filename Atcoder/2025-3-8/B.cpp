/*************************************************************************
	> File Name: B.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 08 Mar 2025 08:12:11 PM CST
 ************************************************************************/

#include<iostream>
#include <vector>
#include <deque>
using namespace std;

deque<int> arr;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c; 
        if (c == 1) {
            int a;
            cin >> a;
            arr.push_front(a);
        } else {
            if (arr.size() == 0)  cout << 0 << endl;
            else {
                cout << arr.front() << endl;
                arr.pop_front();
            }
        }
    }

    return 0;
}
