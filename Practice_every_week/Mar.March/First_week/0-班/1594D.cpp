/*************************************************************************
	> File Name: 1594D.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 01 Mar 2025 04:27:04 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class My_Union {
public :
    My_Union(int n) : fa(n + 1, 0), val(n + 1, 0), cnt(n + 1, vector<int>(2, 0)) {
        for (int i = 1; i <= n; i++) {
            fa[i] = i;
            cnt[i][0] = 1; //和i同类,当前它自己
            cnt[i][1] = 0; //和i异类的数量
            val[i] = 0;
        }
    }

    int find(int x) {
        if (fa[x] == x) return x;
        int root = find(fa[x]);
        val[x] ^= val[fa[x]];
        return fa[x] = root;
    }
    
    int merge(int i, int j, int x) {
        //printf("%d %d %d\n", i, j,x);
        int a = find(i), b = find(j);
        if (a == b) return 0;
        fa[a] = b;
        val[a] = x ^ val[i] ^ val[j];
        //如果a和b异类，那么b同类就加上a的异类数量
        //如果ab同类,b就加上a的同类数量
        cnt[b][0] += cnt[a][val[a]];
        //逻辑相反，如果ab同类，b的异类就加上a的异类数量
        //如果ab异类,那么b的异类和a就是同类，b的异类就加上a同类的数量
        cnt[b][1] += cnt[a][1 ^ val[a]];
        return 1;
    }
    //val表示当前节点和父节点是否同类
    //0表示同类，1表示异类
    vector<int> fa, val;
    vector<vector<int>> cnt;
};

void solve() {
    int n, m;
    cin >> n >> m;
    My_Union u(n);
    int flag = 1;
    while (m) {
        m--;
        int i, j;
        string str;
        cin >> i >> j >> str;
        if (u.merge(i, j, (str[0] == 'i'))) continue;
        //如果i,j在一个集合中
        //那么判断i,j之间的关系是否和现在给出的关系是否一样
        //如果不一样，那么就将flag置为0说明发生冲突
        if (u.val[i] ^ u.val[j] == (str[0] == 'i')) continue;
        flag = 0;
    }
    if (!flag) {
        cout << "-1" << endl;
        return ;
    }
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        if (u.find(i) == i) {
            sum += max(u.cnt[i][0], u.cnt[i][1]);
        }
    }
    cout << sum << endl;
    return ;
}



int main() {
    int t;
    cin >> t;
    while (t--) solve();


    return 0;
}
