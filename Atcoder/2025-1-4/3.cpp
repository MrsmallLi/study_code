/*************************************************************************
	> File Name: 3.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 04 Jan 2025 08:14:23 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long long next_snake_num(long long x) {
    vector<int> num;
    for (long long i = x; i; i /= 10) num.push_back(i % 10);
    int len = num.size();
    for (int i = len - 2, flag = 1; i >= 0; i--) {
        if (flag && num[i] < num[len - 1]) continue;
        num[i] = num[len - 1] - 1;
        flag = 0;
    }
    num[0] += 1;
    for (int i = 0; i < len - 1; i++) {
        if (num[i] < num[len - 1]) continue;
        num[i] = 0;
        num[i + 1] += 1;
    }
    if (num[len - 1] == 10) {
        num[len - 1] = 0;
        num.push_back(1);
    }
    len = num.size();
    long long temp = 0;
    for (int i = len - 1; i >= 0; i--) {
        temp = temp * 10 + num[i];
    }
    return temp;
}

long long POW(long long x, long long y) {
    long long a = 1;
    while (y--) a *= x;
    return a;
}


long long is_num(long long x) {
    vector<int> num;
    for (long long i = x; i; i /= 10) num.push_back(i % 10);
    int len = num.size();
    long long cnt = 0;
    //比当前蛇数位数低的蛇数个数
    for (int i = 2; i < len; i++) {
        for (int j = 1; j <= 9; j++) {
            cnt += POW(j, i - 1);
        }
    }
    //求当前位数相同，并且比当前蛇数最高位小的蛇数
    int temp = num[len - 1];
    for (int i = 1; i < temp; i++) {
        cnt += POW(i, len - 1);
    }
    //计算当蛇数对应的，当前最高位数是num[len - 1]的第几个蛇数
    for (int i = len - 2; i >= 0; i--) {
        cnt += num[i] * POW(num[len - 1], i);
    }
    return cnt;
}

int main() {
    long long l, r;
    cin >> l >> r;
    l = next_snake_num(l - 1);
    r = next_snake_num(r);
    cout << is_num(r) - is_num(l) << endl;
    return 0;
}
