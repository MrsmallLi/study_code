/*************************************************************************
	> File Name: 45.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 28 Mar 2024 02:11:29 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


class Solution {
public:
    int jump(vector<int>& nums) {
        int cnt = 0, n = nums.size();
        int end = 0;
        int max_jump = 0;
        for (int i = 0; i < n - 1; i++) {
            max_jump = max(max_jump, i + nums[i]);
            if (i == end) cnt++, end = max_jump;
        }
        return cnt;
    }
};
