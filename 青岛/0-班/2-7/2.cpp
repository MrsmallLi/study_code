/*************************************************************************
	> File Name: 2.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 07 Feb 2025 07:06:18 PM CST
 ************************************************************************/

#include <iostream>
#include <deque>
using namespace std;

class A {
public :
    A(long long x, long long h) : x(x), h(h) {}
    long long x, h;
};

int main() {
    deque<A> dq;    
    long long q;
    cin >> q;
    long long m = 0, len = 0;
    while (q--) {
        long long a;
        cin >> a;
        switch(a) {
            case (1) : {
                long long b;
                cin >> b;
                A s(b, len);
                len += b;
                dq.push_back(s);
            } break;
            case (2) : {
                if (dq.empty()) break;
                m += dq.front().x;
                dq.pop_front();
            } break;
            case (3) : {
                int k;
                cin >> k;
                if ((k - 1) >= dq.size()) break;
                cout << dq[k - 1].h - m << endl;
            } break;
        }
    }


    return 0;
}
