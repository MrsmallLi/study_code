/*************************************************************************
	> File Name: 7.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 07 Feb 2025 07:43:42 PM CST
 ************************************************************************/

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

long long n;
long long arr[200];
long long s[200];
unordered_set<long long> st;
long long temp = 0;

void dfs(long long size, long long x) {
    for (long long i = 0; i <= size; i++) {
        temp ^= s[i];
        s[i] += arr[x];
        temp ^= s[i];
        if (x == n) st.insert(temp);
        else if (i < size)  dfs(size, x + 1);
        else dfs(size + 1, x + 1);
        temp ^= s[i];
        s[i] -= arr[x];
        temp ^= s[i];
    }
    return ;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)  cin >> arr[i];
    dfs(0, 1);
    cout << st.size() << endl;
    return 0;
}
