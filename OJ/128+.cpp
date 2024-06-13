/*************************************************************************
	> File Name: 128+.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 31 May 2024 11:24:28 PM CST
 ************************************************************************/

#include "./my_include.h"
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans, n = nums.size(); 
        unordered_set<int> s;
        for (auto x : nums) s.insert(x);
        for (auto x : s) {
            if (s.find(x - 1) != s.end()) continue;
            int num = x;
            int cnt = 1;
            while (s.find(num + 1) != s.end()) {
                num += 1; 
                cnt += 1;
            }
            ans = max(anx, cnt);
        }
        return cnt;
    }
};
