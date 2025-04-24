/*************************************************************************
	> File Name: 489C.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 27 Feb 2025 08:18:02 PM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

void max_num(int m, int s) {
    while (m--) {
        if (s >= 9) {
            cout << 9;
            s -= 9;
        } else {
            cout << s;
            s = 0;
        }
    }
    cout << endl;
    return ;
}

void min_num(int m, int s) {
    int arr[m];
    memset(arr, 0, sizeof(arr));
    s -= 1;
    arr[m - 1] = 1;
    for (int i = 0; i < m; i++) {
        if (s >= 9) {
            arr[i] = 9;
            s -= 9;
        } else {
            arr[i] += s;
            s = 0;
        }
    }
    for (int i = m - 1; i >= 0; i--) cout << arr[i];
    cout << " ";
    return ;
}


int main() {
    int m, s;
    cin >> m >> s;
    if ((s == 0 && m != 1) || 9 * m < s) {
        cout << "-1" << " " << "-1" << endl;
        return 0;
    }
    min_num(m, s);
    max_num(m, s);
    return 0;
}
