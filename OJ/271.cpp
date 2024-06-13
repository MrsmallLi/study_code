/*************************************************************************
	> File Name: 271.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 04 Jun 2024 06:16:00 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <deque>
using namespace std;


int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n + 1);
    deque<int> q;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int flag = 0; 
    for (int i = 0; i < n; i++) {
        while (!q.empty() && arr[q.back()] > arr[i]) q.pop_back();
        q.push_back(i);
        if (i - q.front() == k) q.pop_front();
        if (i + 1 < k) continue;
        flag && cout << " ";
        cout << arr[q.front()];
        flag = 1;
    }
    flag = 0;
    q.clear();
    cout << endl;
    for (int i = 0; i < n; i++) {
        while (!q.empty() && arr[q.back()] < arr[i]) q.pop_back();
        q.push_back(i);
        if (i - q.front() == k) q.pop_front();
        if (i + 1 < k) continue;
        flag && cout << " ";
        cout << arr[q.front()];
        flag = 1;
    }
    cout << endl;
    return 0;
}
