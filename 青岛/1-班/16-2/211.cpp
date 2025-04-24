/*************************************************************************
	> File Name: 211.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 16 Feb 2025 10:53:23 AM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> arr;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        int len = str.length();
        for (int k = 0, j = len - 1; k <= j; k++, j--) {
            swap(str[k], str[j]);
        }
        arr.push_back(str);
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
    return 0;
}
