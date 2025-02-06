/*************************************************************************
	> File Name: 231+.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 15 Jan 2025 10:39:47 PM CST
 ************************************************************************/


//递推实现
#include <iostream>
#include <climits>
using namespace std;

int f1[1000], f2[1000];

int main() {
    int n;
    cin >> n;
    f1[1] = 1;
    for (int i = 2; i <= n; i++) {
        f1[i] = 2 * f1[i - 1] + 1;
    }
    f2[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (j == 1) f2[i] = 2 * f2[j] + f1[i - j];
            f2[i] = min(f2[i], 2 * f2[j] + f1[i - j]);
        }
    }
    cout << f2[n] << endl;
    return 0;
}
