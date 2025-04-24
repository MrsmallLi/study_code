/*************************************************************************
	> File Name: 3.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 07 Feb 2025 07:27:43 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

typedef long long ll;

ll t[200], l[200];

int main() {
    int n, d;
    cin >> n >> d;
    for (int i = 0; i < n; i++) cin >> t[i] >> l[i];
    for (int i = 1; i <= d; i++) {
        ll max_num = 0;    
        for (int j = 0; j < n; j++) {
            max_num = max(max_num, t[j] * (l[j] + i));
        }
        cout << max_num << endl;
    }

    return 0;
}
