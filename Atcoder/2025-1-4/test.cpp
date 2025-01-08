/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 05 Jan 2025 10:40:56 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;


void NEXT(int &x) {
    vector<int> arr;
    while (x) {
        arr.push_back(x % 10);
        x /= 10;
    }
    int n = arr.size();
    for (int i = n - 2, flag = 0; i >= 0; i--) {
        if (flag) {
            arr[i] = arr[n - 1] - 1;
            continue;
        }
        if (arr[i] < arr[arr.size() - 1]) continue;
        arr[i] = arr[n - 1] - 1;
        flag = 1;
    }
    arr[0] += 1;
    for (int i = 0; i < arr.size() - 1; i++) {
        if (arr[i] < arr[arr.size() - 1]) continue;
        arr[i] = 0;
        arr[i + 1] += 1;
    }
    if (arr[arr.size() - 1] == 10) {
        arr[arr.size() - 1] = 0;
        arr.push_back(1);
    }
    for (int i = arr.size() - 1; i >= 0; i--) {
        x = x * 10 + arr[i];
    }
    return ;
}



int POW(int x, int y) {
    int num = 1;
    while (y--) num *= x;
    return num;
}

int NUM(int x) {
    int cnt = 0;
    vector<int> arr;
    while (x) {
        arr.push_back(x % 10);
        x /= 10;
    }
    int n = arr.size();
    for (int i = 2; i < n; i++) {
        for (int j = 1; j <= 9; j++) {
            cnt += POW(j, i - 1);
        }
        cout << "i = " << i << ", " << cnt << endl;
    }
    for (int i = 1; i < arr[n - 1]; i++) {
        cnt += POW(i, n - 1);
        cout << "i = " << i << ", " << cnt << endl;
    }
    for (int i = n - 2; i >= 0; i--) {
        cnt += arr[i] * POW(arr[n - 1], i);
        cout << "i = " << i << ", " << cnt << endl;
    }
    return cnt;
}


int main() {
    int l; 
    cin >> l;
    cout << NUM(l) << endl;
    return 0;
}
