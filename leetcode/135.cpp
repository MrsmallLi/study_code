/*************************************************************************
	> File Name: 135.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 17 Jun 2024 01:30:00 PM CST
 ************************************************************************/

#include "./my_include.h"
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> ind(n);
        vector<int> candy_num(n, 0);
        iota(ind.begin(), ind.end(), 0);
        sort(ind.begin(), ind.end(), [=] (const int a, const int b) -> bool {
            return ratings[a] < ratings[b];
        });
        long long ans = 0;
        for (auto x : ind) {
            int l = x - 1;
            int r = x + 1;
            candy_num[x] = 1;
            if (l >= 0 && candy_num[x] <= candy_num[l]) candy_num[x] = candy_num[l] + 1;
            if (r < n && candy_num[x] <= candy_num[r]) candy_num[x] = candy_num[r] + 1;
            ans += candy_num[x];
        }
        return ans;
    }
};

