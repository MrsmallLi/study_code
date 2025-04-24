/*************************************************************************
	> File Name: 4.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 29 Mar 2025 08:24:19 PM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 200000

int num[2 * MAX_N + 10];
int ind[2 * MAX_N + 10];
int temp[2 * MAX_N + 10];


int main() {
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++) {
        int n;
        scanf("%d", &n);
        int ans = 0;
        memset(ind, 0, (n + 5) * sizeof(int));
        for (int i = 1; i <= 2 * n; i++) {
            scanf("%d", num + i);
            if (ind[num[i]]) {
                temp[ind[num[i]]] = i;
                temp[i] = ind[num[i]];
            } else {
                ind[num[i]] = i;
            }
        }
        for (int i = 1; i < 2 * n; i++) {
            if (abs(temp[i] - i) == 1 || 
                abs(temp[i + 1] - i - 1) == 1 || 
                abs(temp[i] - temp[i + 1]) != 1
               )  continue;
            ans += 1;
        }
        cout << ans / 2 << endl;
    }
    return 0;
}
