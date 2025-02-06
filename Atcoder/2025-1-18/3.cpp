/*************************************************************************
	> File Name: 3.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 18 Jan 2025 08:38:55 PM CST
 ************************************************************************/

#include <iostream>
#include <deque>
using namespace std;


class A{
public :
    A(long long x, long long b) : x(x), b(b) {}
    long long x, b;

};


int main() {
    int n;
    cin >> n;
    deque<A> de;
    long long len = 0;
    long long m = 0;
    while (n--) {
        long long a, b;
        cin >> a;
        switch (a) {
            case 1: {
                cin >> b;
                A dada(len, b);
                len += b;
                de.push_back(dada);
            } break;
            case 2: {
                if (de.empty()) break;
                m += de.front().b;
                de.pop_front();
            } break;
            case 3: {
                cin >> b;
                if ((b - 1) >= de.size()) break;
                cout << de[b - 1].x - m << endl;
            } break;
        }
    }



    return 0;
}
