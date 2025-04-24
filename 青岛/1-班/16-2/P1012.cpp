/*************************************************************************
	> File Name: P1012.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 16 Feb 2025 07:31:52 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> arr;

bool CMP(string a, string b) {
    return a + b > b + a;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;  
        cin >> str;
        arr.push_back(str);
    }
    sort(arr.begin(), arr.end(), CMP);
    string ans;
    for (int i = 0; i < n; i++) {
        ans = ans + arr[i] ;
    }
    cout << ans << endl;
    return 0;
}
