/*************************************************************************
	> File Name: 5.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 28 Jan 2025 02:37:54 AM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int n, x;
class Node {
public :   
    int a, c;
};

vector<vector<Node>> arr(3);
int dp[5][5005];


void my_swap(int *dp1, int *dp2, int *dp3) {
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j <= i; j++) {
            dp3[i] = max(dp3[i], min(dp1[j], dp2[i - j]));
        }
    }
    return ;
}

int main() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        int v, a, c;        
        cin >> v >> a >> c;
        arr[v - 1].push_back({a, c});
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            for (int k = x; k >= arr[i][j].c; k--) {
                dp[i][k] = max(dp[i][k], dp[i][k - arr[i][j].c] + arr[i][j].a);
            }
        }
    }
    my_swap(dp[0], dp[1], dp[3]);
    my_swap(dp[3], dp[2], dp[4]);
    cout << dp[4][x] << endl;
    return 0;
}
