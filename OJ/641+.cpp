/*************************************************************************
	> File Name: 641+.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 22 Oct 2024 10:16:30 AM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX_N 2000

class cmp{
public :
    bool operator()(int a, int b) const {
        return a > b;
    }
};



int fa_num[MAX_N + 5] = {0};
vector<vector<int>> num(MAX_N + 5);

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        fa_num[b] += 1;
        num[a].push_back(b);
    }
    //priority_queue<int, vector<int>, greater<int>> p_q;
    priority_queue<int, vector<int>, cmp> p_q;
    for (int i = 1; i <= n; i++) {
        if (fa_num[i]) continue;
        p_q.push(i);
    }
    vector<int> ans;
    while (!p_q.empty()) {
        int front_num = p_q.top();
        p_q.pop();
        ans.push_back(front_num);
        for (int i = 0; i < num[front_num].size(); i++) {
            if (--fa_num[num[front_num][i]] == 0) {
                p_q.push(num[front_num][i]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        i && cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
