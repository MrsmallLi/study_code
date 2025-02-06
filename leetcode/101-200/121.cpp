/*************************************************************************
	> File Name: 121.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 27 Mar 2024 12:20:37 PM CST
 ************************************************************************/

#include "./my_include.h"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0];
        int max_money = 0;
        int n = prices.size();
        for (int i = 1; i < n; i++) {
            if (prices[i] - min > max_money) max_money = prices[i] - min;
            min = min > prices[i] ? prices[i] : min;
        }
        return max_money;
    }
};
