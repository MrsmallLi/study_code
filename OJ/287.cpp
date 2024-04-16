/*************************************************************************
	> File Name: 287.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 16 Apr 2024 03:50:58 PM CST
 ************************************************************************/

#include<iostream>
#include <set>
using namespace std;

typedef pair<int, int> PII;
class Heap : public set<PII> {
public : 
    Heap() : t(0) {}
    int top() { return begin()->first; }
    void push(int x) {
        insert(PII(x, t++));
        return ;
    }
    void pop() {
        erase(begin());
        return ;
    }
private :
    int t;
}; 

int main() {
    int n;
    cin >> n;
    int ans = 0;
    Heap h;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        h.push(x);
    }
    while (h.size() != 1){
        int temp = 0; 
        temp += h.top();
        h.pop();
        temp += h.top();
        h.pop();
        h.push(temp);
        ans += temp;
    }
    cout << ans << endl;
    return 0;
}
