/*************************************************************************
	> File Name: 2.P5661.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 09 Feb 2025 10:36:43 AM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

class A {
public :
    A(int p, int t) : p(p), t(t) {}
    int p, t;
};

queue<A> dq;


int main() {
    int n;
    cin >> n;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int temp, p, t;
        cin >> temp >> p >> t;
        if (!temp) {
            ans += p; 
            dq.push(A(p, t));
            continue;
        } else {
            while (!dq.empty() && t - dq.front().t > 45) dq.pop();
            int m = dq.size(), flag = 0;
            for (int i = 0; i < m; i++) {
                A now = dq.front();
                dq.pop();
                if (flag || now.p < p) {
                    dq.push(now)
                    continue;
                } else {
                    flag = 1;   
                    break;
                }
            }
            if (!flag) ans += p;
        }
    }
    cout << ans << endl;
    return 0;
}
