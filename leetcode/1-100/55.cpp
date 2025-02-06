/*************************************************************************
	> File Name: 55.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 28 Mar 2024 12:16:32 PM CST
 ************************************************************************/

#include "./my_include.h"
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_temp = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            //说明当前在前方可以移动到当前位置
            if (i <= max_temp) max_temp = max(max_temp, i + nums[i]);
            //已经移动不到当前位置，就无法往后移动了
            else return false;
        }
        return true;
    }
}
