/*************************************************************************
	> File Name: 4+.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 15 Feb 2025 10:07:01 PM CST
 ************************************************************************/

#include<iostream>
#include <vector>
using namespace std;

vector<int> ind;

int main() {
    int n;
    cin >> n;
    string str;
    cin >> str;
    for (int i = 0; i < n; i++) {
        if (str[i] != '1') continue;
        ind.push_back(i);
    }
    int temp = ind[ind.size() / 2];
    int len = ind.size();
    int x = n / 2; 
    long long ans = 0;
    for (int i = 0; i < len; i++)  {
        ans += abs(ind[i] - (temp - x + i));
    }
    cout << ans << endl;
    return 0;
}
