/*************************************************************************
	> File Name: 595.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 10 Apr 2024 05:22:21 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;


int main() {
    stack<string> s;
    string ans;
    int n;
    cin >> n;
    vector<string> arr(n), arr2;
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> ans;
    int flag = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == "return") arr2.pop_back();
        else {
            arr2.push_back(arr[i]);
            if (arr[i] == ans) {
                flag = 1;
                break;
            }
        }
    }
    if (!flag) cout << "NOT REFERENCED" << endl;   
    else {
        for (int i = 0; i < arr2.size(); i++) {
            i && cout << "->";
            cout << arr2[i];
        }
    }
    cout << endl;
    return 0;
}
