/*************************************************************************
	> File Name: 1159+.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 29 Apr 2024 05:23:19 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;
#define MAX_N 100000

typedef pair<int, int> PII;
int arr[MAX_N + 5] = {0};

int main() {
    int n, cnt = 0;
    queue<PII> q;
    cin >> n;
    q.push(PII(1, 0));
    arr[1] = 1;
    while (!q.empty()) {
        PII num = q.front();
        int a = num.first + 1;
        int b = num.first * 2;
        int c = num.second + 1;
        if (a == n || b == n) {
            cout << c << endl;
            break;
        }
        if (a < n && !arr[a]) q.push(PII(a, c)), arr[a] = 1;
        if (b < n && !arr[b]) q.push(PII(b, c)), arr[b] = 1;
        q.pop();
    }
    return 0;
}
