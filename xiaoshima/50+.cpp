/*************************************************************************
	> File Name: 50+.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 20 Oct 2024 12:32:54 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;


int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int max = a;
    if (max < b) max = b;
    if (max < c) max = c;
    cout << max << endl;


    return 0;
}
