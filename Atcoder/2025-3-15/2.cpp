/*************************************************************************
	> File Name: 2.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 15 Mar 2025 08:06:38 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;


int main() {
    string str;
    cin >> str;
    int cnt = 0;
    for (int i = 0; str[i]; i++) {
        int x = i + 1; 
        if (x & 1) {
            if (str[i] == 'i') continue;
            str.insert((str.begin() + i), 'i');
            cnt += 1;
        } else {
            if (str[i] == 'o') continue;
            str.insert((str.begin() + i), 'o');
            cnt += 1;
        }
    }
    if (str.size() & 1) {
        str.insert(str.begin() + str.size(), 'i');
        cnt += 1;
    }
    //cout << str << endl;
    cout << cnt << endl;
    return 0;
}
