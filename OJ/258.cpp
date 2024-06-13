/*************************************************************************
	> File Name: 258.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 08 Jun 2024 09:29:00 PM CST
 ************************************************************************/

#include <iostream>
#include <cinttypes>
#include <climits>
using namespace std;

#define MAX_N 100

int main() {
	int n;
	cin >> n;
	int arr[MAX_N + 5][MAX_N + 5] = {0};
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			arr[i][j] += arr[i - 1][j];
		}
	}	
	int ans = INT_MIN;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			int S = 0;
			for (int k = 0; k <= n; k++) {
				int num = arr[j][k] - arr[i - 1][k];
				if (S >= 0) S += num;
				else S = num;
				ans = max(S, ans);
			}
		}
	}	
	cout << ans << endl;
	return 0;
}
