/*************************************************************************
	> File Name: 122.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 28 Mar 2024 11:50:38 AM CST
 ************************************************************************/

#include "./my_include.h"
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][1] = -prices[0];
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[n - 1][0];
        return 0;
    }
};

//优化空间
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int hava_cose = -prices[0], no_cost = 0;
        for (int i = 1; i < n; i++) {
            no_cost = max(no_cost, hava_cose + prices[i]);
            hava_cose = max(hava_cose, no_cost - prices[i]);
        }
        return no_cost;
        return 0;
    }
};


//贪心解法
//借助 「差分」 这个概念，可以证明 「贪心算法」 的有效性。贪心算法是选择那些所有差分（严格）大于 0 的数，把它们相加即可。


#include<iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), ans = 0;
        if (n < 2) return 0;
        for (int i = 1; i < n; i++) {
            ans += max(0, prices[i] - prices[i - 1]);
        }
        return ans;
    }
}; 
