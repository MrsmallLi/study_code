/*************************************************************************
	> File Name: 504.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 08 Jun 2024 08:50:55 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	string str;
	int n;
	cin >> str >> n;
	for (int i = 0; i < n; i++) {
		int j = 0;
		while (str[j + 1] && str[j] <= str[j + 1]) j++;
		str.erase(j, 1);
	}	
	int flag = 1;
	for (int i = 0; str[i]; i++) {
		if (str[i] == '0' && flag) continue;
		cout << str[i];
		flag = 0;
	}
	cout << endl;
	return 0;
}


