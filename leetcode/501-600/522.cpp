/*************************************************************************
	> File Name: 522.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 17 Jun 2024 12:39:27 PM CST
 ************************************************************************/

#include "./my_include.h"
#include <functional>
using namespace std;

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        function<bool(const string, const string)> func = [](const string &a, const string &b) -> bool{
            int a_ind = 0, b_ind = 0; 
            while (a[a_ind] && b[b_ind]) {
                if (a[a_ind] == b[b_ind]) {
                    b_ind++;
                }
                a_ind++;
            }
            return b_ind == b.size();
        };
        int n = strs.size();
        int ans = -1;
        for (int i = 0; i < n; i++) {
            if (static_cast<int>(strs[i].size()) < ans) continue;
            int flag = 1;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (func(strs[j], strs[i])) {
                    flag = 0;
                    break;
                }
            }
            if (flag) ans = strs[i].size();
        }
        return ans;
    }
};
