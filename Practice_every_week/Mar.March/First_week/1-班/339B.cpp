/*************************************************************************
	> File Name: 339B.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 27 Feb 2025 06:33:45 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 100000

int arr[MAX_N + 5];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> arr[i];
    }
    //由于每次移动可能会消耗10^5，那么需要消耗10^5次这样的体力
    //所以超出的int的表示范围
    long long ans = 0;
    //cnt表示所在的房子
    int cnt = 1;
    for (int i = 0; i < m; i++) {
        //说明任务点在当前位置的前面，需要循环一圈回到起点，再去任务点
        if (arr[i] < cnt) {
            ans += n - cnt + arr[i];
        } else {
            //任务点就在当前位置后面，直接移动到任务点
            //或者当前点就是任务点
            ans += arr[i] - cnt;
        }
        //移动到当前任务点
        cnt = arr[i];
    }
    cout << ans << endl;
    return 0;
}
