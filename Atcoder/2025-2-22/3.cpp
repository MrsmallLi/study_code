/*************************************************************************
	> File Name: 3.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 22 Feb 2025 08:42:55 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <set>
using namespace std;

set<int> st;

void set_string(string &a, int ind) {
    a[ind] = 'A';
    a[ind + 1] = 'C';
    return ;
}


int main() {
    string a;
    cin >> a;
    int len = a.length();
    for (int i = 0; i < len; i++) {
        if (a[i] != 'W') continue;
        if (a[i + 1] != 'A') continue;
        st.insert(i);
    }
    while (st.size()) {
        int ind = *st.begin();
        st.erase(st.begin());
        set_string(a, ind);
        if (ind - 1 < 0 || a[ind - 1] != 'W') continue;
        st.insert(ind - 1);
    }
    cout << a << endl;
    return 0;
}
