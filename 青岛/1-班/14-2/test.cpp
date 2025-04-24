/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 14 Feb 2025 10:07:28 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;


int main() {
    int val = 0x7fffffff;
    char arr[50] = {0};
    for (int i = 0; i <= 31; i++) {
        arr[i] = (val & (1 << i)) + '0';
    }
    for (int i = 31; i >= 0; i--) {
        printf("%c", arr[i]);
    }
    cout << endl;
}
