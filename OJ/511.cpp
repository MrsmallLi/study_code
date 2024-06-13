/*************************************************************************
	> File Name: 511.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 08 Jun 2024 09:44:14 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;


int main() {
	long long a, b, k;
	cin >> a >> b >> k;
	if (k == 1 || !k) {
		cout << b - a << endl;
		return 0;
	}
	long long ans = 0;
	while (1) {
		if (a * k <= b) {
			ans += 1 + b % k;
			b /= k;
		} else {
			ans += b - a;
			break;
		}
		
	}	
	cout << ans << endl;
	
	return 0;
}
