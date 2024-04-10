/*************************************************************************
	> File Name: 7.sort.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 09 Apr 2024 01:32:18 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;

void output(vector<int> arr) {
    for (int i = 0; i < 10; i++) {
        i && cout << " ";
        cout << arr[i];
    }
    cout << endl;
    return ;
}

bool comp(int a, int b) {
    return a > b;
}

int main() {
    srand(time(0));
    vector<int> arr;
    for (int i = 0; i < 10; i++) {
        arr.push_back(rand() % 100);
    }
    output(arr);
    sort(arr.begin(), arr.end());
    output(arr);
    sort(arr.begin(), arr.end(), comp);
    output(arr);
    return 0;
}
