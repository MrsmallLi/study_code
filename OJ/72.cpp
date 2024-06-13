/*************************************************************************
	> File Name: 72.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 03 Jun 2024 07:29:26 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class UnionSet {
public :
    UnionSet(int n) : win(n + 1), val(n + 1) {
        for (int i = 0; i <= n; i++) {
            win[i] = i;
            val[i] = 0;
        }
    }

    int get(int x) {
        if (win[x] == x) return x;
        int root = get(win[x]);
        val[x] = (val[x] + val[win[x]] + 3) % 3;
        return win[x] = root;
    }

    void merge(int a, int b, int x) {
        int aa = get(a), bb = get(b);
        if (aa == bb) return ;
        win[aa] = bb;
        val[aa] = (x + val[b] - val[a] + 3) % 3;
        return ;
    }
    vector<int> win, val;
};

int main() {
    int n, m;
    cin >> n >> m;
    UnionSet um(n);
    for (int i = 0; i < m; i++) {
        int a, b, c; 
        cin >> a >> b >> c;
        if (a == 1) {
            um.merge(b, c, 2);
        } else {
            if (um.get(b) != um.get(c)) cout << "Unknown" << endl;
            else {
                switch ((um.val[b] - um.val[c] + 3) % 3) {
                    case 0 : cout << "Tie" << endl; break;
                    case 1 : cout << "Loss" << endl; break;
                    case 2 : cout << "Win" << endl; break;
                    default : break;
                }
            }
        }
    }
    return 0;
}
