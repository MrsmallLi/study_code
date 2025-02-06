/*************************************************************************
	> File Name: 238.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 29 Mar 2024 11:14:56 AM CST
 ************************************************************************/

#include "./my_include.h"
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> l(n, 0);
        vector<int> r(n, 0);
        vector<int> ans(n, 0);
        l[0] = r[n - 1] = 1;
        for (int i = 1; i < n; i++) {
            l[i] = l[i - 1] * nums[i - 1];
        }
        for (int i = n - 2; i >= 0; i--) {
            r[i] = r[i + 1] * nums[i + 1];
        }
        for (int i = 0; i < n; i++) {
            ans[i] = r[i] * l[i];
        }
        return ans;
    }
};


void output(vector<int> &num) {
    for (int i = 0; i < num.size(); i++) {
        printf("num[%d] = %d\n", i, num[i]);
    }
}
//
class solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        ans[0] = 1;
        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }
        int tmp = 1;
        for (int i = n - 2; i >= 0; i--) {
            tmp = tmp * nums[i + 1];
            ans[i] = tmp * ans[i];
        }
        return ans;
    }
};


int main() {
    int n;
    cin >> n;
    vector<int> num;
    for (int i = 0; i < n; i++) {
        int s;
        cin >> s;
        num.push_back(s);
    }
    solution s;
    vector<int> ans = s.productExceptSelf(num);
    output(ans);
    return 0;
}
