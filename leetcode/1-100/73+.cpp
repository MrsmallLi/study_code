/*************************************************************************
	> File Name: 73+.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 11 Feb 2025 02:20:48 PM CST
 ************************************************************************/

#include "./my_include.h"
#include <cstring>
using namespace std;

#define arr matrix
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = arr.size(), m = arr[0].size();
        int x = 0, y = 0;
        for (int i = 0; i < m; i++) {
            if (arr[0][i]) continue;
            x = 1;
            break;
        }
        for (int i = 0; i < n; i++) {
            if (arr[i][0]) continue;
            y = 1;
            break;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (arr[i][j]) continue;
                arr[i][0] = 0;
                arr[0][j] = 0;
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (arr[i][0] && arr[0][j]) continue;
                arr[i][j] = 0;
            }
        }
        if (x == 1) {
            for (int i = 0; i < m; i++) arr[0][i] = 0;
        }
        if (y == 1) {
            for (int i = 0; i < n; i++) arr[i][0] = 0;
        }
        return ;
    }
};
