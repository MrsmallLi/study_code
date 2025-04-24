/*************************************************************************
	> File Name: 216.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 16 Feb 2025 01:09:29 AM CST
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
        str = str.substr(3, str.size() - 3);
        arr.push_back(str);
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) cout << arr[i] << endl;
    return 0;
}
