/*************************************************************************
	> File Name: 1+.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 24 Jan 2025 05:59:33 PM CST
 ************************************************************************/

#include "./my_include.h"
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            if (mp.find(target - nums[i]) != mp.end() && mp[nums[i]] != i) {
                return {i, mp[target - nums[i]]};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};
