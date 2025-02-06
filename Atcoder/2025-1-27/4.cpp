/*************************************************************************
	> File Name: 4.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 27 Jan 2025 10:38:29 PM CST
 ************************************************************************/

#include <iostream>
#include <unordered_set>
using namespace std;

#define int long long

int n;
int arr[20] = {0};
int s[20] = {0};
long long temp = 0;
unordered_set<long long> st;

void dfs(int x, int size) {
    for (int i = 0; i <= size; i++) {
        temp ^= s[i];
        s[i] += arr[x];
        temp ^= s[i];
        if (x == n) st.insert(temp);
        else if (i < size) dfs(x + 1, size);
        else dfs(x + 1, size + 1);
        temp ^= s[i];
        s[i] -= arr[x];
        temp ^= s[i];
    }
    return ;
}


int32_t main() {
    cin >> n;
    for (long long i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    dfs(1, 0);
    cout << st.size() << endl;
    return 0;
}
