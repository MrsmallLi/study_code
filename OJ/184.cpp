/*************************************************************************
	> File Name: 184.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 24 Oct 2024 11:27:39 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int fun(int n) {
    if (n == 1) return 1;
    return (fun(n - 1) + 1) * 2; 
}



int main() {
    int n;
    cin >> n;
    cout << fun(n) << endl;

    return 0;
}
