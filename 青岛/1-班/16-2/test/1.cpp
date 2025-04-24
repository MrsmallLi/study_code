/*************************************************************************
	> File Name: 1.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 15 Feb 2025 11:30:44 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

int arr[15];

vector<int> num;

bool CMP(int a, int b) {
     return a > b;
}

int main() {
    srand(time(0));
    int n;
    cin >> n;
    cout << "arr : ";
    for (int i = 0; i < n; i++) {
        i && printf(" ");
        arr[i] = rand() % 100;
        cout << arr[i];
    }
    cout << endl;
    cout << "num : ";
    for (int i = 0; i < n; i++) {
        i && printf(" ");
        int a = rand() % 100;
        num.push_back(a);
        cout << num[i];
    }
    cout << endl;
    cout << "arr : ";
    sort(arr, arr + n, CMP);
    sort(num.begin(), num.end());
    for (int i = 0; i < n; i++) {
        i && printf(" ");
        cout << arr[i];
    }
    cout << endl;
    cout << "num : ";
    for (int i = 0; i < n; i++) {
        i && printf(" ");
        cout << num[i];
    }
    cout << endl;
    return 0;
}
