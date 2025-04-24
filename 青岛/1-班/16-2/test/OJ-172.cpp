/*************************************************************************
	> File Name: OJ-172.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 16 Feb 2025 12:17:03 AM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;


vector<string> arr;

int main() {
    int n = 10;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        arr.push_back(str);
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
    return 0;
}
