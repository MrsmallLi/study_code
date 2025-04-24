/*************************************************************************
	> File Name: C.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 08 Feb 2025 08:12:40 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;


class Node {
public :
    int q, p;
};
class CMP {
public :
    bool operator()(const Node &a, const Node &b) {
        return a.q < b.q;
    }
};
int arr[300005];
Node num[300005];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num[i].p;
    }
    for (int i = 1; i <= n; i++) {
        cin >> num[i].q;
        arr[i] = num[i].q;
    }
    sort(num + 1, num + n + 1, CMP());
    for (int i = 1; i <= n; i++) {
        if (i != 1) cout << " ";
        cout << arr[num[i].p];
    }
    cout << endl;
    return 0;
}
