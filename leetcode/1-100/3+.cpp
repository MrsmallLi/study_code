/*************************************************************************
	> File Name: 3+.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 26 Jan 2025 08:15:34 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int mp[256] = {0};
        int len = 0;
        int l = 0;
        for (int i = 0; s[i]; i++) {
            while (mp[s[i]])  mp[s[l++]] -= 1;
            len = i - l + 1;
            mp[s[i]] = 1;
            ans = max(ans, len);
        }
        return 0;
    }
};
