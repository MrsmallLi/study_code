/*************************************************************************
	> File Name: 1.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 01 Feb 2025 08:24:08 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;


int main() {
    string s;
    cin >> s;
    unordered_map<string, string> mp;
    mp["N"] = "S";
    mp["E"] = "W";
    mp["S"] = "N";
    mp["W"] = "E";
    mp["NE"] = "SW";
    mp["SE"] = "NW";
    mp["SW"] = "NE";
    mp["NW"] = "SE";
    cout << mp[s] << endl;
    return 0;
}
