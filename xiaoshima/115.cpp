/*************************************************************************
	> File Name: 115.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 20 Oct 2024 12:41:08 AM CST
 ************************************************************************/

#include <iostream>
#include <stdio.h>
using namespace std;



char arr[20] = {0}; 

int main() {
    int len = 0;
    for (int i = 0; i < 20; i++) arr[i] = '*';
    scanf("%s", arr);
    while (arr[len++] != '*');
    int flag = 1;
    for (int j = 0, k = len - 3; j <= k; j++, k--) {
        if (arr[j] == arr[k]) continue;
        else {
            cout << "NO" << endl;
            flag = 0;
            break;
        }
    } 
    if (flag) cout << "YES" << endl;
    return 0;
}
