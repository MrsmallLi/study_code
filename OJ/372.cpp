/*************************************************************************
	> File Name: 372.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 16 Apr 2024 11:10:06 AM CST
 ************************************************************************/

#include<iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> arr1, arr2;
stack<int> q1, q2;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)  {
        int a;
        cin >> a;
        arr1.push_back(a);
    }
    for (int i = 0; i < n; i++)  {
        int a;
        cin >> a;
        arr2.push_back(a);
    }
    int i = 0;
    while (q1.size() == q2.size()) {
        while (!q1.empty() && arr1[q1.top()] >= arr1[i]) q1.pop();
        while (!q2.empty() && arr2[q2.top()] >= arr2[i]) q2.pop();
        q1.push(i);
        q2.push(i++);
    }
    cout << i - 1 << endl;
    return 0;
}
