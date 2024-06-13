/*************************************************************************
	> File Name: 327.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 04 Jun 2024 05:59:47 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Unionset {
public :
    Unionset(int n) : fa(n + 1), val(n + 1) {
        for (int i = 0; i <= n; i++) {
            fa[i] = i;
            val[i] = 0;
        }
    }

    int get(int x) {
        if (fa[x] == x) return x;
        int root = get(fa[x]);
        val[x] = (val[x] + val[fa[x]]) % 2;
        return fa[x] = root;
    }

    void merge(int a, int b, int t) {
        int aa = get(a), bb = get(b);
        if (aa == bb) return ;
        val[aa] = (t - val[a] + val[b] + 2) % 2;
        fa[aa] = bb;
        return ;
    }
    vector<int> fa, val;
};

class Data {
public :
    long long a, b, c;
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<Data> data;
    Unionset u(n);
    for (int i = 0; i < m; i++) {
        Data x; 
        cin >> x.a >> x.b >> x.c;
        data.push_back(x);
    }
    sort(data.begin(), data.end(), [&](const Data &a, const Data &b) {
        return a.c > b.c;
    });
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int a = data[i].a, b = data[i].b, c = data[i].c;
        if (u.get(a) == u.get(b)) {
            if ((u.val[a] - u.val[b] + 2) % 2 != 0) continue;
            ans = c;
            break;
        } else {
            u.merge(a, b, 1);
        }
    }
    cout << ans << endl;
    return 0;
}
