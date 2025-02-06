/*************************************************************************
	> File Name: 2.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 11 Jan 2025 08:15:51 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int num1[105];
int num2[105];

int main() {
    int n, d;
    cin >> n >> d;
    for (int i = 0; i < n; i++) {
        cin >> num1[i] >> num2[i];
    }
    for (int j = 1; j <= d; j++) {
        int temp = -1;
        for (int i = 0; i < n; i++) {
            temp = max(temp, num1[i] * (num2[i] + j));
        }
        cout << temp << endl;
    }
    return 0;
}
