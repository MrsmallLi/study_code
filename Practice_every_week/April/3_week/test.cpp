/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 20 Apr 2025 10:46:55 PM CST
 ************************************************************************/

/*
 * 题解：将前后两段上升序列提取出来，假设左边的开始大于右边;
 * 1：左边有奇数个，先手必胜;
 * 2：左边偶数个, 右边奇数先手必胜,反之后手必胜;
*/


#include<iostream>
#include<vector>
using namespace std;


void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> premax;
    vector<int> nxtmax;
    if(n == 1)
    {
        cout << "Alice" << endl;
        return ;
    }
    for(int i = 1; i <= n; i++) cin >> a[i];
    premax.push_back(a[1]);
    for(int i = 2; i <= n; i++)
    {
        if(a[i] > a[i - 1]) premax.push_back(a[i]);
        else break;
    }
    nxtmax.push_back(a[n]);
    for(int i = n - 1; i >= 1; i--)
    {
        if(a[i] > a[i + 1]) nxtmax.push_back(a[i]);
        else break;
    }

        return ;
    }
    cout << "Bob" << endl;
    return ;
}

int main()
{
    int t;
    t = 1;
    //cin >> t;
    while(t--) solve();
    return 0;
}
