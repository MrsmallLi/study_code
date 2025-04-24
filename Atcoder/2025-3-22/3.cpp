/*************************************************************************
	> File Name: 3.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 22 Mar 2025 08:10:26 PM CST
 ************************************************************************/

#include<iostream>
#include <map>
#include <vector>
using namespace std;
#define int long long

class A {
public :
    A(int x, int ind) : x(x), ind(ind) {}
    int x, ind;
};

map<int, int> mp;
vector<A> arr;

int32_t main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        if (mp.count(a) == 0) {
            A b(a, i);
            arr.push_back(b);
        }
        mp[a] += 1;
    }
    int len = arr.size();
    long long max_num = -1;
    int ans = -1;
    for (int i = 0; i < len; i++) {
        if (mp[arr[i].x] > 1) continue;
        if (arr[i].x > max_num) {
            max_num = arr[i].x;
            ans = arr[i].ind;
        }
    }
    cout << ans << endl;
    return 0;
}
