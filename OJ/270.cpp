/*************************************************************************
	> File Name: 270.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 04 Jun 2024 06:34:25 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <deque>
using namespace std;



int main() {
    int n, m;
    cin >> n >> m;
    vector<int> s(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        if (i - 1 < 0) continue;
        s[i] += s[i - 1];
    }
    deque<int> q; 
    int ans = s[0];
    for (int i = 0; i < n; i++) {
        while (!q.empty() && s[q.back()] > s[i]) q.pop_back();
        q.push_back(i);
        if (i - m > q.front()) q.pop_front();
        ans = max(ans, s[i] - s[q.front()]);
    }
    cout << ans << endl;
    return 0;
}
