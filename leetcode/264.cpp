/*************************************************************************
	> File Name: 264.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 04 Jun 2024 07:34:06 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;



int main() {
    int n;
    cin >> n;
    vector<long long> h(n + 2, -1), l(n + 2), r(n + 2);
    for (int i = 1; i <= n; i++)  {
        cin >> h[i];
    }
    stack<int> s;
    s.push(0);
    for (int i = 1; i <= n + 1; i++) {
        while (!s.empty() && h[i] < h[s.top()]) {
            r[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty()) s.pop();
    for (int i = n; i >= 0; i--) {
        while (!s.empty() && h[i] < h[s.top()]) {
            l[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        long long  S = (r[i] - l[i] - 1) * h[i];
        ans = max(ans, S);
    }
    cout << ans << endl;
    return 0;
}
