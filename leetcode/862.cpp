/*************************************************************************
	> File Name: 862.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 04 Jun 2024 09:04:07 PM CST
 ************************************************************************/

#include "./my_include.h"
using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sum(n);
        sum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            sum[i] = sum[i - 1] + nums[i];
        }
        deque<int> q;
        int ans = n + 1;
        for (int i = 0; i < n; i++) {
            while (!q.empty() && sum[i] - sum[q.front()] >= k) {
                ans = min(ans, i - q.front());
                q.pop_front();
            }
            while (!q.empty() && sum[i] < sum[q.back()]) q.pop_back();
            q.push_back(i);
        }
        return ans;
    }
};
