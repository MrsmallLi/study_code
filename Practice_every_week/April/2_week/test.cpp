/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 18 Apr 2025 04:42:04 PM CST
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int num[12],len;
ll l,r,dp[11][11][11][2][2][2][2];
ll f(int p,int a,int b,bool c,bool d,bool _4,bool _8){
    if(_4&&_8) return 0;
    if(p<=0) return c;
    if (~dp[p][a][b][c][d][_4][_8]) return dp[p][a][b][c][d][_4][_8];
    ll res=0;int lim=!d?num[p]:9;
  	for(int i=0;i<=lim;i++)
        res+=f(p-1,i,a,c||(i==b&&i==a),d||(i<lim),_4||(i==4),_8||(i==8));
    return dp[p][a][b][c][d][_4][_8]=res;
}
ll calc(ll x){
    if(x<1e10) return 0;
    memset(dp,-1,sizeof(dp));
    for(len=0;x;x/=10) num[++len]=x%10;
	ll res=0;
	for(int i=1;i<=num[len];i++)
    res+=f(10,i,0,0,i<num[len],i==4,i==8);
	return res;
}
int main(){
    cin>>l>>r;
    ll r_ans = calc(r);
    ll l_ans = calc(l - 1);
    cout << "r = " << r_ans << endl;
    cout << "l = " << l_ans << endl;
    cout << r_ans - l_ans << endl;
    return 0;
}
