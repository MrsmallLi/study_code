/*************************************************************************
	> File Name: 1-372C.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 09 Feb 2025 09:01:54 AM CST
 ************************************************************************/

#include <iostream>
#include <unordered_set>
using namespace std;
int l, q;
string str;

unordered_set<int> st;

bool check(int i) {
    return i >= 0 && i + 2 < l && str[i] == 'A' && str[i + 1] == 'B' && str[i + 2] == 'C';
}

void find() {
    int a;
    char c;
    cout << endl;
    while (q--) {
        cin >> a >> c;
        a -= 1;
        for (int i = a - 2; i <= a + 2; i++) {
            if (!check(i)) continue;
            st.erase(i);
        }
        str[a] = c;
        for (int i = a - 2; i <= a + 2; i++) {
            if (!check(i)) continue;
            st.insert(i);
        }
        cout << st.size() << endl;
    }
}

int main() {
    cin >> l >> q;
    cin >> str;
    for (int i = 0; i < l; i++) {
        if (!check(i)) continue;
        st.insert(i);
    }
    find();
    return 0;
}
