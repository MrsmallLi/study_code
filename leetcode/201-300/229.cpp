/*************************************************************************
	> File Name: 229.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 11 Feb 2025 04:02:37 PM CST
 ************************************************************************/

#include "./my_include.h"
using namespace std;


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<int> ans;
        for (int i = 0; i < n; i++) mp[nums[i]] += 1;
        for (auto x : mp) {
            int key = x.first;
            int val = x.second;
            if (val > n / 3) ans.push_back(key);
        }
        return ans; 
    }
};
