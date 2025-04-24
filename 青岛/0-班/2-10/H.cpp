/*************************************************************************
	> File Name: H.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 10 Feb 2025 04:58:50 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 700

typedef class Data {
public :
    int x, y;
} A;

A arr[MAX_N + 5];


int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].x >> arr[i].y;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int num = 0;
        for (int j = i + 1; j < n; j++) {
            int x1 = arr[i].x - arr[j].x;
            int y1 = arr[i].y - arr[j].y;
            num = 2;
            for (int k = j + 1; k < n; k++) {
                int x2 = arr[i].x - arr[k].x;
                int y2 = arr[i].y - arr[k].y;
                if (x2 * y1 != x1 * y2) continue;
                num += 1;
            }
            ans = max(ans, num);
        }
    }
    cout << ans << endl;
    return 0;
}
