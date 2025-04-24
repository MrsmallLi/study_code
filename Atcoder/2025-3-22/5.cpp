/*************************************************************************
	> File Name: 5.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 22 Mar 2025 09:20:11 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int flag[105][105];
int n;




int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        flag[u][v] = 1;
        flag[v][u] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (flag[i][v]) continue;

        }
        dfs(i, );
    }
    return 0;
}
