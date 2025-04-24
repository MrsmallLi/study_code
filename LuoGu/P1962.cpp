/*************************************************************************
	> File Name: P2064.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 08 Feb 2025 10:20:41 AM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;


typedef long long ll;
#define int long long

ll mod = 1e9 + 7;



class Matrix : public vector<vector<int>> {
public :
    Matrix(){}
    Matrix(int n, int m) : n(n), m(m){
        for (int i = 0; i < n; i++) {
            push_back(vector<int>(m, 0));
        }
    }
    Matrix operator*(Matrix &b) {
        Matrix c(b.size(), b[0].size());
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                for (int k = 1; k < at(0).size(); k++) {
                    c[i][j] = c[i][j] + at(i).at(k) * b[k][j];
                    c[i][j] %= mod;
                }
            }
        }
        return c;
    }
    int n, m;
};

ll n;
Matrix ans(3, 3), temp(3, 3);

void init() {
    ans[1][1] = ans[1][2] = 1;
    temp[1][1] = temp[1][2] = temp[2][1] = 1;
    return ;
}

void quick_pow(int n) {
    while (n) {
        if (n & 1) ans = ans * temp;
        temp = temp * temp;
        n >>= 1;
    }
    return ;
}




int32_t main() {
    cin >> n;
    init();
    if (n > 2) quick_pow(n - 2);
    cout << ans[1][1] % mod << endl;
    return 0;
}
