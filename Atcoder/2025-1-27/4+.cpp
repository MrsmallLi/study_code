/*************************************************************************
	> File Name: 4+.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 09 Feb 2025 05:32:33 PM CST
 ************************************************************************/

#include <iostream>
#include <unordered_set>
using namespace std;

int n;
long long arr[15], he[15];
unordered_set<long long> st;
long long ans = 0;

void dfs(int ind, int size) {
    for (int i = 1; i <= size; i++) {
        ans ^= he[i];
        he[i] += arr[ind];
        ans ^= he[i];
        if (ind == n) {
            st.insert(ans);
        } else if (i < size) {
            dfs(ind + 1, size);
        } else {
            dfs(ind + 1, size + 1);
        }
        ans ^= he[i];
        he[i] -= arr[ind];
        ans ^= he[i];
    }
    return ;
}


int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    dfs(1, 1);
    cout << st.size() << endl;
    return 0;
}
