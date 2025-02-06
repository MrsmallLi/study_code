/*************************************************************************
	> File Name: 219.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 26 Jan 2025 07:59:43 PM CST
 ************************************************************************/

#include "./my_include.h"
using namespace std;


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp; 
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (mp.find(nums[i]) != mp.end() && mp[nums[i]] - i <= k)  return true;
            mp[nums[i]] = i;
        }
        return false;
    }
};
