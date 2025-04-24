/*************************************************************************
	> File Name: 73.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 11 Feb 2025 02:06:22 PM CST
 ************************************************************************/

#include "./my_include.h"
#include <cstring>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int x[n + 1], y[m + 1];
        memset(x, 0, sizeof(x));
        memset(y, 0, sizeof(y));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] != 0) continue;
                x[i] = 1;
                y[j] = 1;
            }
        }
        for (int i = 0; i < n; i++) {
            if (x[i] == 0) continue;
            for (int j = 0; j < m; j++) {
                matrix[i][j] = 0;
            }
        }
        for (int i = 0; i < m; i++) {
            if (y[i] == 0) continue;
            for (int j = 0; j < n; j++) {
                matrix[j][i] = 0;
            }
        }
        return ;
    }
};
