/*************************************************************************
	> File Name: 3.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 04 Jan 2025 08:14:23 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
int getH(long long num) {
    num = abs(num); // 取绝对值
    int digits = log10(num); // 计算数字的位数 - 1
    return num / pow(10, digits); // 通过除以 10^(digits) 获取最高位
}

int getlen(long long num) {
    return log10(num);
}



int get_cnt(int n) {
    for (int i = 10; i <= )
}


int main() {
    long long l, r, cnt;
    cin >> l >> r;
    printf("%lld\n", cnt);
    return 0;
}
