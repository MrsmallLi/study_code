/*************************************************************************
	> File Name: E.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 08 Mar 2025 09:35:59 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define MAX_N 200000

class A{
public :
    A(int x, int y) : x(x), y(y) {}
    int x, y;
};

vector<A> arr;
map<A, int> mp;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        A a(x, y);
        arr.push_back(a);
        mp[a] = 1;
    }



    return 0;
}
