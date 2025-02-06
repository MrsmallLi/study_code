/*************************************************************************
	> File Name: 100372.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 21 Jul 2024 05:46:37 PM CST
 ************************************************************************/

#include "./my_include.h"
using namespace std;

class Solution {
public:
    void TenToTwo(int n, char *a) {
        int i = 0;
        for (int i = 0; i < 32; i++) {
            a[i] = '0';
        }
        while (n) {
            a[i++] = (n % 2) + '0';
            n >>= 1;
        }
        return ;
    }
    void output(char *a) {
        for (int i = 31; i >= 0; i--) cout << a[i];
        cout << endl;
        return ;
    }

    int minChanges(int n, int k) {
        if (k > n) return -1;
        if (k == n) return 0;
        char a[35] = {0};
        char b[35] = {0};
        TenToTwo(n, a);
        TenToTwo(k, b);
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            if (a[i] == b[i]) continue;
            if (a[i] == '0' && b[i] == '1') return -1;
            ans++;
        }
        return ans;
    }
};


int main() {
    Solution s; 
    cout << s.minChanges(13, 4) << endl;
    return 0;
}

