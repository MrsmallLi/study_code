/*************************************************************************
	> File Name: 3.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 01 Feb 2025 09:24:44 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int n, q;
int arr[1000005];
int num[1000005];
int val[1000005];


int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) arr[i] = 1, num[i] = i;
    int a, cnt = 0;
    while (q--) {
        cin >> a;
        switch(a) {
            case 1: {
                int p, h;  
                cin >> p >> h;
                int ind = num[p];
                if (val[ind] && arr[ind] == 2) {
                    cnt -= 1;
                    val[ind] = 0;
                }
                arr[ind] -= 1;
                if (arr[h] + 1 > 1 && !val[h]) {
                    cnt += 1;
                    val[h] = 1;
                }
                arr[h] += 1;
                num[p] = h;
            } break; 
            case 2: {
                cout << cnt << endl;
            } break;
        }
    }







    return 0;
}
