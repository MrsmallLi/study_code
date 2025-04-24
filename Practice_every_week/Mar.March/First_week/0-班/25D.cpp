/*************************************************************************
	> File Name: 25D.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 01 Mar 2025 07:22:13 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class A {
public :
    int a, b; 
};
vector<A> more;
vector<int> arr;

class My_Union {
public :
    My_Union(int n) : fa(n + 1) {
        for (int i = 1; i <= n; i++) fa[i] = i;
    }

    int find(int x) {
        return fa[x] = (fa[x] == x ? x : find(fa[x]));
    }

    int merge(int a, int b) {
        int aa = find(a), bb = find(b);
        if (aa == bb) return 0;
        fa[aa] = bb;
        return 1;
    }
    vector<int> fa;
};

void input(int n, My_Union &u) {
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (u.merge(a, b)) continue;
        A temp;
        temp.a = a;
        temp.b = b;
        more.push_back(temp);
    }
    return ;
}

void solve(int n) {
    My_Union u(n);
    input(n, u);
    long long t = 0;
    for (int i = 1; i <= n; i++) {
        if (u.find(i) != i) continue;
        t++;
        arr.push_back(i);
    }
    cout << t - 1 << endl;
    for (int i = 0, k = 0; i < more.size(); i++, k++) {
        int old_a = more[i].a, old_b = more[i].b;
        printf("%d %d ", old_a, old_b);
        printf("%d %d\n", arr[k], arr[k + 1]);
    }
    return ;
}



int main() {
    int n;
    cin >> n;
    solve(n);
    return 0;
}
