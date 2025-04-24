/*************************************************************************
	> File Name: D.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 08 Feb 2025 08:29:00 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class B {
public :
    unordered_map<int, int> mp;
    int cnt;
};



B arr[105];

double func(int cnt1, int cnt2, int temp1, int temp2) {
    double a1 = cnt1, b1 = temp1;
    double a2 = cnt2, b2 = temp2;
    return (b1 * b2) / (a1 * a2);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0, k; i < n; i++) {
        cin >> k;
        arr[i].cnt = k;
        for (int j = 0, s; j < k; j++) {
            cin >> s;
            arr[i].mp[s] += 1;
        }
    }
    double ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double xxx = 0;
            for (auto x : arr[i].mp) {
                int temp1 = 0, temp2 = 0;
                if (arr[j].mp.find(x.first) == arr[j].mp.end()) continue;
                temp1 = arr[i].mp[x.first];
                temp2 = arr[j].mp[x.first];
                xxx += func(arr[i].cnt, arr[j].cnt, temp1, temp2);
            }
            ans = max(ans, xxx);
        }
    }
    printf("%.20lf\n", ans);
    return 0;
}
