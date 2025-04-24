/*************************************************************************
	> File Name: 128.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 23 Feb 2025 08:24:35 PM CST
 ************************************************************************/

#include "./my_include.h"
using namespace std;
class UnionSet {
public :
    UnionSet(int n) : fa(n + 1, 0), size(n + 1, 0){
        for (int i = 0; i <= n; i++) {
            fa[i] = i;
            size[i] = 1;
        }
    }
    int find(int x) {
        return (fa[x] = (fa[x] == x ? x : find(fa[x])));
    }
    void merge(int a, int b) {
        int aa = find(a), bb = find(b);
        if (aa == bb) return ;
        fa[aa] = bb;
        size[bb] += size[aa];
    }
    vector<int> fa, size;
};


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        UnionSet u(n);
        int ind = 0;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            if (mp.count(x)) {
                continue;
            }
            mp[x] = ind ++;
            if (mp.count(x + 1)) {
                u.merge(ind - 1, mp[x + 1]);
            } 
            if (mp.count(x - 1)) {
                u.merge(ind - 1, mp[x - 1]);
            }
        }
        int ans = 0;
        for (int i = 0; i < ind; i++) {
            ans = max(ans, u.size[i]);
        }
        return ans;
    }
};
