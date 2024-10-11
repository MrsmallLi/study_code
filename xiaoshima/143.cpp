/*************************************************************************
	> File Name: 143.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 10 Oct 2024 03:57:16 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int arr[100005];

int main() {
    int n, m;
    cin >> n >> m;
    int cnt = 0;
    int ind = 1;
    while (cnt < n) {
        int num = m % (n - cnt) + n - cnt; 
        int j = ind - 1;
        while (num) {
            j++;
            if (j > n) j = 1;
            if (!arr[j]) num--;
        }
        cout << j << endl;
        arr[j] = 1;
        cnt++;
        if (cnt < n - 1) {
            while (arr[j]) {
                j++;
                if (j > n) j = 1;
            }
        }
        ind = j;
    }
    return 0;
}
