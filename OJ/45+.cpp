/*************************************************************************
	> File Name: 45+.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 13 Apr 2025 02:46:57 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 1000
int dp[MAX_N + 5][MAX_N + 5];


int main() {
    string str1, str2;
    cin >> str1 >> str2;
    for (int i = 0; str1[i]; i++) {
        for (int j = 0; str2[j]; j++) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + (str1[i] == str2[j]));
        }
    }
    cout << dp[str1.length() - 1][str2.length() - 1] << endl;
    return 0;
}
