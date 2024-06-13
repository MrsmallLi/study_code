/*************************************************************************
	> File Name: P1219.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 05 Jun 2024 05:32:31 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

#define MASK(n) ((1 << (n + 1)) - 2)
int total_ans = 3;
int arr[25] = {0};

unordered_map<int, int> ind;

void printf_one_result(int n){
    for (int i = 1; i <= n; i++) {
        i > 1 && cout << " ";
        cout << arr[i];
    }
    total_ans -= 1;
    cout << endl;
    return ;
}

int dfs(int i, int t1, int t2, int t3, int n) {
    if (i > n) {
        if (total_ans) printf_one_result(n);
        return 1;
    }
    int ans = 0;
    for (int k = t1; k; k -= (-k & k)) {
        int j = ind[-k & k];
        if ((t2 & (1 << (i + j - 1))) && (t3 & (1 << (i - j + n)))) {
            arr[i] = j;
            ans += dfs(i + 1, 
                       t1 ^ (1 << j), 
                       t2 ^ (1 << (i + j - 1)), 
                       t3 ^ (1 << (i - j + n)), 
                       n
                      );
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < 2 * n; i++) ind[1 << i] = i;
    int ans = dfs(1, MASK(n), MASK(2 * n - 1), MASK(2 * n - 1), n);
    cout << ans << endl;
    return 0;
}
