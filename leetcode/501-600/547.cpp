/*************************************************************************
	> File Name: 547.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 03 Jun 2024 07:16:43 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class UnionSet {
public :
    UnionSet(int n) : fa(n + 1) {
        for (int i = 0; i < n + 1; i++) fa[i] = i;
    }
    int get(int x) {
        return fa[x] = (fa[x] == x ? x : get(fa[x]));
    }
    void merge(int a, int b) {
        int aa = get(a), bb = get(b);
        if (aa == bb) return ;
        fa[aa] = fa[bb];
        return ;
    }
    vector<int> fa;

};


class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), m = isConnected[0].size();
        UnionSet uset(n * m);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!isConnected[i][j]) continue;
                uset.merge(i, j);
            }
        }
        for (int i = 0; i < n; i++) {
            if (uset.get(i) == i) ans += 1;
        }
        return ans;
    }
};
