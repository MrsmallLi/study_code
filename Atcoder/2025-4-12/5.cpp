/*************************************************************************
	> File Name: 5.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 12 Apr 2025 09:22:42 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 200000

vector<int> son[MAX_N + 5];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        son[u].push_back(v);
        son[v].push_back(u);
    }




    return 0;
}
