/*************************************************************************
	> File Name: 203.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 16 Feb 2025 12:43:48 AM CST
 ************************************************************************/

#include<iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


vector<vector<int>> st(15);
vector<int> arr;

bool CMP(int a, int b) {
    return a > b;
}


int main() {
    int n, m;
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;
            st[i].push_back(a);
            arr.push_back(a);
        }
    }
    /*
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", st[i][j]);
        }
        cout << endl;
    }
    */
    for (int i = 0; i < n; i++) {
        int max_h = 0;
        for (int j = 0; j < m; j++) {
            max_h = max(st[j][i], max_h);
        }
        cout << max_h << endl;
    }
    double sum = 0;
    sort(arr.begin(), arr.end(), CMP);
    for (int i = 0; i < arr.size(); i++) {
        i && printf(" ");
        printf("%d", arr[i]);
        sum += arr[i];
    }
    cout << endl;
    int avg = round(sum / (arr.size() * 1.0));
    cout << avg << endl;
    int cnt = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] < avg) break;
        cnt += 1;
    }
    cout << cnt << endl;
    return 0;
}
