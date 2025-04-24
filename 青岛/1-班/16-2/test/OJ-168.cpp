/*************************************************************************
	> File Name: OJ-168.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 15 Feb 2025 11:54:08 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;


vector<string> arr;

bool CMP(string &a, string &b) {
    for (int i = 0; a[i] && b[i]; i++) {
        if (a[i] == b[i]) continue;
        return a[i] < b[i];
    }
    return a.size() > b.size();
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int i = 1; str[i]; i++) {
            if (str[i] < 'A' || str[i] > 'Z') continue;
            str[i] += 32;
        }
        if (str[0] >= 'a' && str[0] <= 'z') str[0] -= 32;
        arr.push_back(str);
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) cout << arr[i] << endl;
    return 0;
}
