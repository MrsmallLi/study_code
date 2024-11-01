/*************************************************************************
	> File Name: P1135.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 25 Oct 2024 02:40:44 PM CST
 ************************************************************************/

#include <iostream>
#include <climits>
using namespace std;

#define MAX_N 200

int arr[MAX_N + 5];
int step[MAX_N + 5];

void dfs(int step_now, int now, int end, int n) {
    if (step[now] <= step_now) return ;
    step[now] = step_now;
    //上
    if (now + arr[now] <= n) dfs(step_now + 1, now + arr[now], end, n);
    //下
    if (now - arr[now] >= 1) dfs(step_now + 1, now - arr[now], end, n);
    return ;
}


int main() {
    int n, a, b;
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        step[i] = INT_MAX;
    }
    dfs(0, a, b, n);
    cout << (step[b] == INT_MAX ? -1 : step[b]) << endl;
    return 0;
}
