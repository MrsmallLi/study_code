/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 29 Mar 2025 10:09:42 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
const int N=4e5+9;
int a[N],b[N];
#define mk make_pair
struct node
{
	int x,y,z;
};
vector<node> v;

bool cmp(node u,node v)
{
	return u.x<v.x;
}

void solve()
{
	int n;
	cin>>n;
	memset(b,0,sizeof b);
	set<int> s;
	map<pair<int,int>,int> mp,m;
	v.clear();
	for(int i=1;i<=2*n;i++)
	{
		cin>>a[i];
	}
	for(int i=2;i<=2*n;i++)
	{
		m[mk(a[i-1],a[i])]+=1;

	}
	int ans=0;
	for(int i=2;i<=2*n;i++)
	{
		if(i-1>=1&&mp[mk(a[i-1],a[i])]&&m[mk(a[i-1],a[i])]==2) v.push_back({a[i-1],i-1,i});
		if(i-1>=1&&!mp[mk(a[i-1],a[i])]&&m[mk(a[i-1],a[i])]==2)
		{

			if(a[i-1]==a[i])
			{
				continue;
			}
			else
			{
				ans++;
				mp[mk(a[i-1],a[i])]=1;
				v.push_back({a[i-1],i-1,i});
				b[i]=1;
			}
		}
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<v.size();i+=2)
	{
		int r=v[i].y,p=v[i].z;
		int h=v[i+1].z,o=v[i+1].y;
		//cout<<r<<' '<<o<<' '<<h<<' '<<p<<"popi"<<'\n';
		//cout<<a[r]<<' '<<a[p]<<' '<<a[o]<<' '<<a[h]<<'\n';
		if(a[r]==a[o]&&a[h]==a[p]) continue;
		else ans--;
	}
	cout<<ans<<'\n';
	return;
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}

