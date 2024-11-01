/*************************************************************************
	> File Name: 114.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 20 Oct 2024 12:37:11 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;


int main() {
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 7 == 0) {
            cnt++;
            continue;
        }
        int n = i;
        while (n > 0) {
            if (n % 10 == 7) {
                cnt++;
                break;
            } 
            n /= 10;
        }
    }
    cout << cnt << endl;

    return 0;
}
