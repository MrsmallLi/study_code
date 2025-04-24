/*************************************************************************
	> File Name: 158B.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 27 Feb 2025 04:01:45 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;


int arr[5];

//贪心策略把每一辆出租车装满
long long func() {
    long long ans = 0;
    //处理4人一组
    ans += arr[4];
    //处理3人一组
    //用一人组和三人组把车装满
    int one_and_three = min(arr[1], arr[3]);
    arr[1] = max(0, arr[1] - one_and_three);
    arr[3] = max(0, arr[3] - one_and_three);
    //没有一人组的三人组，坐一辆车
    ans += one_and_three + arr[3];
    //处理2人组
    //把一人组组成两人组的数量向上取整
    //然后把上面这个一人组出来的2人组，和2人组进行拼车
    int two_and_one = min(arr[2], ((arr[1] + 1) / 2));
    ans += two_and_one;
    arr[2] = max(0, arr[2] - two_and_one);
    arr[1] = max(0, arr[1] - 2 * two_and_one);
    //处理没有1人组和2人组组合的2人组
    //2个2人组可以拼车，进行向上取整
    ans += (arr[2] + 1) / 2;
    //处理1人组
    //向上取整
    ans += (arr[1] + 3) / 4;
    return ans;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        arr[a] += 1;
    }
    cout << func() << endl;
    return 0;
}
