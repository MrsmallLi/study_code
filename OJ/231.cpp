/*************************************************************************
	> File Name: 231.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 15 Jan 2025 10:39:04 PM CST
 ************************************************************************/


#include <iostream>
#include <climits>
using namespace std;

//递归实现
int fun2(int x) {
    if (x == 1) return 1;
    return 2 * fun2(x - 1) + 1;
}

int fun(int x) {
    if (x == 1) return 1;
    int ans = INT_MAX;
    for (int i = 1; i < x; i++) {
        ans = min(ans, 2 * fun(i) + fun2(x - i));
    }
    return ans;
}


int main() {
    int n;
    cin >> n;
    cout << fun(n) << endl;
    return 0;
}
