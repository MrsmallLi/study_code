/*************************************************************************
	> File Name: 4.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 01 Feb 2025 09:50:15 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, w;

class A {
public :
    A(int x, int y) : x(x), y(y) {}
    int x, y;
};

class CMP {
public :
    bool operator()(const A &a, const A &b) {
        if (a.x == b.x) {
            return a.y > b.y;
        }
        return a.x < b.x;
    }
};


int main() {
    cin >> n >> w;
    vector<A> num;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        A a(x, y);
        num.push_back(a);
    }
    sort(num.begin(), num.end(), CMP());
    return 0;
}
