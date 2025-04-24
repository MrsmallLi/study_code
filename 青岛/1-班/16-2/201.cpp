/*************************************************************************
	> File Name: 201.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 16 Feb 2025 10:27:53 AM CST
 ************************************************************************/

#include <iostream>
#include <set>
using namespace std;

set<int> st;


int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        st.insert(a);
    }
    int flag = 0;
    cout << st.size() << endl;
    for (auto x : st) {
        flag && printf(" ");
        printf("%d", x);
        flag = 1;
    }
    cout << endl;
    return 0;
}
