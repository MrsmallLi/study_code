/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 08 Feb 2025 09:24:32 PM CST
 ************************************************************************/

#include<iostream>
#include<unordered_map>
using namespace std;

#define MAX_N 100

int n;

unordered_map<int, int> mp[MAX_N + 5];
int k[MAX_N + 5];

void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> k[i];
        for(int j = 1; j <= k[i]; j++)
        {
            int x;
            cin >> x;
            mp[i][x] += 1;
        }
    }
    double ans = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            double cnt = 0;
            for(auto x : mp[i])
            {
                if(mp[j].find(x.first) == mp[j].end()) continue;
                cnt += (1.0 * x.second / k[i]) * (1.0 * mp[j][x.first] / k[j]);
            }
            ans = max(ans, cnt);
        }
    }
    printf("%.20lf\n", ans);
    return ;
}


int main()
{
    solve();
    return 0;
}
