/*************************************************************************
	> File Name: ../../OJ/1159.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 29 Apr 2024 05:19:46 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


int main() {
    int n, cnt = 0;
    cin >> n;
    while (n > 1) {
        cnt += n % 2; 
        cnt += 1;    
        n >>= 1;
    }
    cout << cnt << endl;
    return 0;
}
