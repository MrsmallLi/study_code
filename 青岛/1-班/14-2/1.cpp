/*************************************************************************
	> File Name: 1.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 14 Feb 2025 11:32:56 AM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(1000, 0);
        unordered_map<int, int> mp; 
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (mp.count(target - nums[i]) == 1) {
                ans.push_back(i);
                ans.push_back(mp[target - nums[i]]);
                return ans;
            }
            mp[nums[i]] = 1;
        }
        return ans;
    }
};
