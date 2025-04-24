/*************************************************************************
	> File Name: 4.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 22 Mar 2025 08:20:01 PM CST
 ************************************************************************/

#include <iostream>
#include <map>
using namespace std;


map<pair<int, int>, int> mp;


int main() {
    int n, r, c;
    cin >> n >> r >> c;
    string str;
    cin >> str;
    int x = 0, y = 0;
    mp[{0, 0}] = 1;
    for (int i = 0; str[i]; i++) {
        switch (str[i]) {
            case 'N': {
                x -= 1;
            } break;
            case 'W': {
                y -= 1;
            } break;
            case 'S': {
                x += 1;
            } break;
            case 'E': {
                y += 1;
            } break;
        }
        mp[{x, y}] = 1;
        cout << mp[{x - r, y - c}] << endl;
    }
    cout << endl;
    return 0;
}
