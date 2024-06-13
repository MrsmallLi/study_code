/*************************************************************************
	> File Name: 503.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 08 Jun 2024 09:03:23 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main() {
	int w, n;
	vector<int> arr;
	cin >> w >> n;
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		arr.push_back(x);
	}
	sort(arr.begin(), arr.end());
	int i = 0, j = n - 1;
	int ans = 0;
	while (i < j) {
		if (arr[i] + arr[j] > w) {
			j--;
		} else {
			i++;
			j--;
		}
		ans += 1;
	}
	if (i == j) ans += 1;
	cout << ans << endl;
	return 0;
}
