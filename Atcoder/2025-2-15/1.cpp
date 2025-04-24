/*************************************************************************
	> File Name: 1.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 15 Feb 2025 08:08:25 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;



int main() {
    string s1, s2;
    cin >> s1 >> s2;
    if (s1 == "sick") {
        if (s2 == "sick") cout << 1 << endl;
        else  cout << 2 << endl;
    } else {
        if (s2 == "fine") cout << 4 << endl;
        else cout << 3 << endl;
    }
    return 0;
}
