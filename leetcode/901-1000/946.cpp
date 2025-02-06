/*************************************************************************
	> File Name: 946.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 12 Apr 2024 11:21:49 AM CST
 ************************************************************************/

#include <./my_include.h>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        int m = popped.size();
        vector<int> num;
        int i = 0, j = 0;
        while (i < n && j < m) {
            num.push_back(pushed[i++]);
            if (num.back() == popped[j]) num.pop_back(), j++;
        }
        for (; j < m; j++) {
            if (num.back() == popped[j]) num.pop_back();
        }
        if (!num.empty()) return false;
        return true;
    }
};
