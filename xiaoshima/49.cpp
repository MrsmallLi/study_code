/*************************************************************************
	> File Name: 50.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 20 Oct 2024 12:16:58 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;


int main() {
    int y, m, d;
    cin >> y >> m >> d;
    int arr[13] = {0};
    for (int i = 1; i <= 12; i++) {
        switch (i){
            case 1: 
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12: {
                arr[i] = 31;
                break;
            }
            case 4:
            case 6:
            case 9:
            case 11: {
                arr[i] = 30;
                break;
            }

            case 2 : {
                if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) {
                    arr[i] = 29;
                } else {
                    arr[i] = 28;
                }
            }

        }
        /**
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
            arr[i] = 31;
        } else if (i == 2) {
            if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) {
                arr[i] = 29;
            } else {
                arr[i] = 28;
            }
        } else {
            arr[i] = 30;
        }
        **/
        
    }
    int n = 1;
    int ans = 0;
    while (n <= m) {
        if (n == m) {
            ans += d; 
            break;
        } else {
            ans += arr[n];
            n++;
        }
    }
    cout << ans << endl;
    return 0;
}
