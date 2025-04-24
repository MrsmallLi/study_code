/*************************************************************************
	> File Name: 36.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 07 Feb 2025 10:07:20 AM CST
 ************************************************************************/

#include "./my_include.h"
using namespace std;



class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int x[9][15] = {0}, y[9][15] = {0}, box[3][3][15] = {0};
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int num = board[i][j] - '0';
                if (x[i][num] || y[j][num] || box[i / 3][j / 3][num]) return false;
                x[i][num] = 1;
                y[j][num] = 1;
                box[i / 3][j / 3][num] = 1;
            }
        }
        return true;
    }
};
