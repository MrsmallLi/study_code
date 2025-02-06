/*************************************************************************
	> File Name: 4.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 11 Jan 2025 08:58:27 PM CST
 ************************************************************************/

#include <iostream>
#include <climits>
#include <queue>
#include <vector>
using namespace std;


int num[1000005] = {0};

class A{
public :    
    A(int x, int step) : x(x), step(step) {}
    int x, step;
};


int main() {
    int n;
    priority_queue<A, vector<A>, greater<int>> pq;
    cin >> n;
    for (int i = 1; i <= n; i++)  {
        cin >> num[i];
    }
    int temp = 1;
    A a(num[1], 1);
    pq.push(a);
    for (int i = 2; i <= n; i++) {
        if (!pq.empty() && pq.top() - 1 < 0) {
            while (!pq.empty() && pq.top() - temp < 0) pq.pop();
        }
        if (!pq.empty()) {
            int s = pq.top();
            pq.pop();
            pq.push(s - 1);
        }
        num[i] += pq.size();
        pq.push(num[i]);
        temp += 1;
    }
    for (int i = 1; i <= n; i++) {
        if (num[i] - n + i < 0) num[i] = 0;
        else num[i] -= n - i;
        if (i != 1) cout << " ";
        cout << num[i];
    }
    cout << endl;
    return 0;
}
