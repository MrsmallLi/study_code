/*************************************************************************
	> File Name: 1438.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 04 Jun 2024 06:45:52 PM CST
 ************************************************************************/

#include "./my_include.h"
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        if (limit < 0) return 0;
        int l = 0;
        int ans = 1;
        deque<int> min_q, max_q;
        min_q.push_back(0);
        max_q.push_back(0);
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            while (!min_q.empty() && nums[min_q.back()] > nums[i]) min_q.pop_back();
            while (!max_q.empty() && nums[max_q.back()] < nums[i]) max_q.pop_back();
            min_q.push_back(i);
            max_q.push_back(i);
            while (nums[max_q.front()] - nums[min_q.front()] > limit) {
                if (min_q.front() == l) min_q.pop_front();
                if (max_q.front() == l) max_q.pop_front();
                l += 1;
            }
            ans = max(ans, i - l + 1);
        }
        return ans;
    }
};

