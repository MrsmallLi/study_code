/*************************************************************************
	> File Name: 42+.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 04 Jun 2024 08:47:31 PM CST
 ************************************************************************/

#include "./my_include.h"
using namespace std;


class Solution {
public:
   int trap(vector<int>& height) {
       int ans = 0;
       int n = height.size();
       stack<int> s;
       for (int i = 0; i < n; i++) {
           while (!s.empty() && height[i] > height[s.top()]) {
               int min_h = height[s.top()];
               s.pop();
               if (s.empty()) break;
               int w = i - s.top() - 1;
               int h = min(height[s.top()], height[i]) - min_h;
               ans += w * h;
           }
           s.push(i);
       }
       return ans;
    }
};
