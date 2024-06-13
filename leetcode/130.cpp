/*************************************************************************
	> File Name: 130.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 03 Jun 2024 06:41:40 PM CST
 ************************************************************************/

#include "./my_include.h"
using namespace std;

class UnionSet {
public :
    UnionSet(int n) : fa(n) {
        for (int i = 0; i < n; i++) {
            fa[i] = i;
        }
    }
    int get(int n) {
        return fa[n] = (fa[n] == n ? n : get(fa[n]));
    }
    
    void merge(int a, int b) {
        if (get(a) == get(b)) return ;
        fa[get(a)] = get(b);
        return ;
    }
    vector<int> fa;
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        UnionSet u(n * m + 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int ind = i * m + j + 1;
                if (board[i][j] != 'O') continue;
                if (i == 0 || i == n - 1) u.merge(ind, 0);
                if (j == 0 || j == m - 1) u.merge(ind, 0);
                if (i + 1 < n && board[i + 1][j] == 'O') u.merge(ind, ind + m);
                if (j + 1 < m && board[i][j + 1] == 'O') u.merge(ind, ind + 1);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int ind = i * m + j + 1;
                if (u.get(ind) == u.get(0)) continue;
                board[i][j] = 'X';
            }
        }
        return ;
    }
};
