/*************************************************************************
	> File Name: 5.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 22 Mar 2025 08:30:24 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 5000000
string str;

int main() {
    cin >> str;
    int len = str.size();
    int ind = len - 1;
    for (int i = 0; i < len - 1; i++)  {
        int k = i, flag = 0;
        for (int j = len - 1; j > k; j--, k++) {
            if (str[k] == str[j]) continue;
            flag = 1;
            break;
        }
        if (!flag) {
            ind = i;
            break;
        }
    }
    //printf("ind = %d\n", ind);
    cout << str;
    for (int i = ind - 1; i >= 0; i--) {
        cout << str[i];
    }
    cout << endl;
    return 0;
}
