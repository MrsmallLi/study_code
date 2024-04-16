/*************************************************************************
	> File Name: 256.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 16 Apr 2024 04:00:06 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX_N 10000

class BigInt : public vector<int>{
public : 
    BigInt(int x = 0) {
        push_back(x);
        proccess_digit();
        return ;
    }
    BigInt &operator*=(int x) {
        for (int i = 0; i < size(); i++) at(i) *= x;
        proccess_digit();
        return *this;
    }
    bool operator>(const BigInt &a) {
        if (size() != a.size())  return size() > a.size();
        for (int i = size() - 1; i >= 0; i--) {
            if (at(i) != a[i]) return at(i) > a[i];
        }
        return false;
    }
    BigInt operator/(int x) {
        BigInt ret(*this);
        int y = 0;
        for (int i = size() - 1; i >= 0; i--) {
            y = y * 10 + at(i);
            y %= x;
        }
        ret.proccess_digit();
        return ret;
    }
private :
    void proccess_digit() {
        for (int i = 0; i < size(); i++) {
            if (at(i) < 10) continue;
            if (i + 1 == size()) push_back(0);
            at(i + 1) += at(i) / 10;
            at(i) %= 10;
        }
        while (size() > 1 && at(size() - 1) == 0) pop_back();
        return ;
    }
};

ostream &operator<<(ostream &out, const BigInt &a) {
    for (int i = a.size() - 1; i >= 0; i--) {
        out << a[i];
    }
    return out;    
}


int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), ind(n + 1);
    for (int i = 0; i < n + 1; i++) {
        cin >> a[i] >> b[i];
        ind[i] = i;
    }
    sort(ind.begin() + 1, ind.end(), [&](int i, int j) -> bool {
        return a[i] * b[i] < a[j] * b[j];
    });
    BigInt p = a[0], ans = 0, temp;
    for (int i = 1; i <= n; i++) {
        temp = p / b[ind[i]];
        if (temp > ans) ans = temp;
        p *= a[ind[i]];
    }
    cout << ans << endl;
    return 0;
}
