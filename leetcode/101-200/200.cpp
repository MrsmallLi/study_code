/*************************************************************************
	> File Name: 200.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 03 Jun 2024 07:02:09 PM CST
 ************************************************************************/

#include "./my_include.h"
using namespace std;

class UnionSet {
public :
    UnionSet(int n) : fa(n + 1) {
        for (int i = 0; i < fa.size(); i++) fa[i] = i;
    }

    int get(int x) {
        return fa[x] = (fa[x] == x ? x : get(fa[x]));
    }
    void merge(int a, int b) {
        if (get(a) == get(b)) return ;
        fa[get(a)] = fa[get(b)];
        return ;
    }
    vector<int> fa;
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        UnionSet un_set(n * m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int ind = i * m + j;
                if (grid[i][j] != '1') continue;
                if (i + 1 < n && grid[i + 1][j] == '1') un_set.merge(ind, ind + m);
                if (j + 1 < m && grid[i][j + 1] == '1') un_set.merge(ind, ind + 1);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != '1') continue;
                int ind = i * m + j;
                if (un_set.get(ind) == ind) ans += 1;
            }
        }
        return ans;
    }
};
