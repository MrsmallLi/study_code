/*************************************************************************
	> File Name: A.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 09 Feb 2025 08:34:30 PM CST
 ************************************************************************/

#include <iostream>
#include <climits>
using namespace std;

#define MAX_N 20

int num[MAX_N + 5] = {0};
long long n, all, temp = 0, ans = INT_MAX;

void find(int ind) {
    for (int i = ind; i <= n; i++) {
        temp += num[i];
        ans = min(ans, max(all - temp, temp));
        find(i + 1);
        temp -= num[i];
    }
    return ;
}



int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        all += num[i];
    };
    find(1);
    cout << ans << endl;
    return 0;
}
