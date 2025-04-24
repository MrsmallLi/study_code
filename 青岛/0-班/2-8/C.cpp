/*************************************************************************
	> File Name: C.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 08 Feb 2025 04:02:58 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class A : public vector<int> {
public :
    A(string s) {
        for (int i = s.size() - 1; i >= 0; i--) {
            push_back(s[i] - '0');
        }
    }
    A operator+(A &a) {
        int n = max(a.size(), size());
        for (int i = 0; i < n; i++) {
            if (size() == i) push_back(0);
            if (a.size() == i) a.push_back(0);
            at(i) += a[i];
        }
        process_digit();
        return (*this);
    }
    void process_digit() {
        for (int i = 0; i < size(); i++) {
            if (at(i) < 10) {
                continue;
            }
            at(i) -= 10;
            if (i + 1 == size()) push_back(0);
            at(i + 1) += 1;
        }
        while (size() > 1 && !at(size() - 1)) pop_back();
    }
};

ostream &operator<<(ostream &out, const A &a) {
    for (int i = a.size() - 1; i >= 0; i--) {
        cout << a[i];
    }
    return out;
}

int main() {
    string a, b;
    cin >> a >> b;
    A arr1(a), arr2(b);
    cout << arr1 + arr2 << endl;
    return 0;
}
