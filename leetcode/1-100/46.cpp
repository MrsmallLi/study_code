/*************************************************************************
	> File Name: 46.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 07 Feb 2025 02:00:59 PM CST
 ************************************************************************/

#include "./my_include.h"
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> mp;
        for (int i = 0; i < n; i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            mp[s].push_back(strs[i]);
        }
        vector<vector<string>> ret;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            ret.push_back(it->second);
        }
        return ret;
    }
};
