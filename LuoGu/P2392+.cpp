/*************************************************************************
	> File Name: P2392+.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 07 Jun 2024 06:13:50 PM CST
 ************************************************************************/

#include <iostream>
#include <unordered_map>
using namespace std;

#define MAX_N 20
#define MAX_NUM 99999999

int s[10] = {0};
int sum[10] = {0};
int t[10][MAX_N +5] = {0};
unordered_map<int, int> ind;


int solve(int x) {
    int T = (1 << s[x]) - 1;
    int ans = MAX_NUM;
    for (int i = 0; i < T; i++) {
        int j = i, l = 0, r = 0;
        while (j) {
            l += t[x][ind[j & -j]];
            j -= (j & -j);
        }
        r = sum[x] - l;
        ans = min(ans, max(l, r));
    }

    return ans;
}


int main() {
    for (int i = 0; i < 4; i++) cin >> s[i];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j <s[i]; j++) {
            cin >> t[i][j];
            sum[i] += t[i][j];
        }
    }
    for (int i = 1, k = 0; k <= MAX_N; i *= 2, k++) ind[i] = k;
    int ans = 0;
    for (int i = 0; i < 4; i++) {
        ans += solve(i);
    }
    cout << ans << endl;
    return 0;
}
