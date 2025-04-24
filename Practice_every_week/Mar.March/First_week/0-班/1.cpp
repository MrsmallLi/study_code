/*************************************************************************
	> File Name: 1.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 02 Mar 2025 08:25:23 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX_N 5000

int n, m;
vector<pair<int, pair<int, int> > > e; // 权值，{U, V};
int fa[MAX_N + 5];

void init()
{
    for(int i = 1; i <= n; i++) fa[i] = i;
    return ;
}

int find(int x)
{
    return fa[x] = (fa[x] == x ? x : find(fa[x]));
}

void add(int a, int b)
{
    fa[find(a)] = find(b);
    return ;
}

bool cmp(const pair<int, pair<int, int> > &a, const pair<int, pair<int, int> > &b)
{
    return a.first < b.first;
}

void solve()
{
    cin >> n >> m;
    init();
    for(int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e.push_back(make_pair(w, make_pair(u, v)));
    }
    sort(e.begin(), e.end(), cmp);
    int ans = 0;
    for(auto x : e)
    {
        int u = x.second.first;
        int v = x.second.second;
        int w = x.first;
        if(find(u) != find(v))
        {
            add(u, v);
            ans += w;
        }  
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++) 
    {
        if(fa[i] == i) cnt += 1;
    }
    if(cnt == 1)
    {
        cout << ans << endl;
    }
    else cout << "orz" << endl;
    return ;
}

int main()
{
    solve();
    return 0;
}
