/*************************************************************************
	> File Name: 1A.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 27 Feb 2025 02:15:08 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;



int main() {
    long long n, m, a;
    cin >> n >> m >> a;
    long long len = (n + a - 1) / a;
    long long high = (m + a - 1) / a;
    cout << len * high << endl;
    return 0;
}
