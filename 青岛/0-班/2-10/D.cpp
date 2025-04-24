/*************************************************************************
	> File Name: D.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 10 Feb 2025 02:35:21 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> ans;


int main() {
    string s, t;
    cin >> s >> t;
    for (int i = 0; s[i]; i++) {
        int ind = -1;
        for (int j = 0; s[j]; j++) {
            if (s[j] == t[j]) continue;
            ind = j;
            if (s[j] > t[j]) break;
        }
        if (ind == -1) continue;
        s[ind] = t[ind];
        ans.push_back(s);
    }
    int n = ans.size();
    cout << n << endl;
    for (int i = 0; i < n; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
