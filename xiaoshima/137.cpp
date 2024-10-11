/*************************************************************************
	> File Name: 137.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 10 Oct 2024 02:52:34 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int ans[20005] = {0};
int arr[20005] = {0};


int main() {
    int n;
    cin >> n;
    int j = 0;
    for (int i = 0, k; i < n; i++) {
        cin >> k;
        if (arr[k]) continue;
        ans[j++] = k;
        arr[k] = 1;
    }
    for (int i = 0; i < j; i++) {
        i && cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
