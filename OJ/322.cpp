/*************************************************************************
	> File Name: 322.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 03 Jun 2024 11:13:14 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class UnionSet {
public :
    UnionSet(int n) : fa(n + 1) {
        for (int i = 0; i <= n; i++) {
            fa[i] = i;
        }
    }
    
    int get(int x) {
        return fa[x] = (fa[x] == x ? x : get(fa[x]));
    }

    void merge(int a, int b) {
        int aa = get(a), bb = get(b);
        if (aa == bb) return ;
        fa[aa] = fa[bb];
        return ;
    }
    vector<int> fa;
};

class Data {
public :
    Data() : a(0), b(0), c(0) {}
    //Data(int a, int b, int c) : a(a), b(b), c(c) {}
    int a, b, c;
};

void func() {
    int n;
    cin >> n;
    vector<int> num;
    vector<Data> data;
    unordered_map<int, int> mp;
    int cnt = 0;
    for (int i = 0; i < n; i++)  {
        Data x;
        cin >> x.a >> x.b >> x.c;
        data.push_back(x);
        if (mp.find(x.a) == mp.end()) mp[x.a] = cnt++;
        if (mp.find(x.b) == mp.end()) mp[x.b] = cnt++;
    }
    UnionSet u(2 * n);
    for (int i = 0; i < n; i++) {
        if (!data[i].c) continue;
        u.merge(mp[data[i].a], mp[data[i].b]);
    }
   
    int flag = 1;
    for (int i = 0; i < n && flag; i++) {
        if (data[i].c) continue;
        if (u.get(mp[data[i].a]) != u.get(mp[data[i].b])) continue;
        flag = 0;
    }
    cout << (flag ? "YES" : "NO") << endl;
    return ;
}

int main() {
    int n;
    cin >> n;
    while (n) {
        func();
        n--;
    }

    return 0;
}
