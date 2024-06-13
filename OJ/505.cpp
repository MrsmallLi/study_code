/*************************************************************************
	> File Name: 505.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 08 Jun 2024 08:35:49 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(const string &a, const string &b) {
	return a + b > b + a;
}

int main() {
	vector<string> str;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		str.push_back(s);
	}
	sort(str.begin(), str.end(), cmp);
	string ans;
	for (auto s : str) {
		ans += s;
	}
	cout << ans << endl;
	return 0;
}
