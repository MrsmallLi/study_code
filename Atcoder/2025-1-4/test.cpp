/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 05 Jan 2025 10:40:56 PM CST
 ************************************************************************/


 #include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int BRIDGE_LENGTH = 20; // 桥的长度
const int MAX_RICE = 10;      // 最大携带大米数量

int solve_min_cost(int total_rice) {
    // 定义 DP 数组：dp[i][j] 表示位置 i，携带 j 粒大米时的最小消耗
    vector<vector<int>> dp(BRIDGE_LENGTH + 1, vector<int>(MAX_RICE + 1, INT_MAX));

    // 初始化起点状态
    for (int i = 0; i <= 10; i++) dp[0][i] = i;

    // 动态规划
    for (int i = 0; i < BRIDGE_LENGTH; ++i) {
        for (int j = 0; j <= MAX_RICE; ++j) {
            if (dp[i][j] == INT_MAX) continue; // 如果当前状态不可达，跳过

            // 向前移动
            if (j > 0) {
                dp[i + 1][j - 1] = min(dp[i + 1][j - 1], dp[i][j] + 1);
            }

            // 返回移动
            if (i > 0) {
                dp[i - 1][j] = min(dp[i - 1][j], dp[i][j]);
            }

            // 存储大米
            dp[i][0] = min(dp[i][0], dp[i][j]);

            // 取用大米
            for (int k = 1; k <= MAX_RICE; ++k) {
                if (total_rice - dp[i][0] >= k) { // 必须保证有足够的大米存储
                    dp[i][k] = min(dp[i][k], dp[i][0] + k);
                }
            }
        }
    }

    // 找到终点位置的最小消耗
    int min_cost = INT_MAX;
    for (int j = 0; j <= MAX_RICE; ++j) {
        min_cost = min(min_cost, dp[BRIDGE_LENGTH][j]);
    }

    return min_cost;
}

int main() {
    int total_rice;
    cout << "Enter the total number of rice grains: ";
    cin >> total_rice;

    int min_cost = solve_min_cost(total_rice);
    cout << "Minimum rice consumption to reach the end: " << min_cost << endl;

    return 0;
}
