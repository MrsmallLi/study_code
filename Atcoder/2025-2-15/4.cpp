/*************************************************************************
	> File Name: 4.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 15 Feb 2025 08:32:06 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <cmath>
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
    long long ans = 0;
    long long x = ind[ind.size() / 2];
    int temp = ind.size() / 2;
    for (int i = 0; i < ind.size(); i++) {
        ans += abs(ind[i] - (x - temp + i)); 
    }
    cout << ans << endl;
    return 0;
}
