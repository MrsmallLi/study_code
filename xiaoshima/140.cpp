/*************************************************************************
	> File Name: 140.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 10 Oct 2024 03:19:14 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;



int main() {
    int n;
    cin >> n;
    double a1 = 0, a2 = 0, a3 = 0, a4 = 0;
    for (int i = 0, k; i < n; i++) {
        cin >> k;
        if (k <= 18) a1++;
        else if (k <= 35) a2++;
        else if (k <= 60) a3++;
        else a4++;
    }
    printf("%.2lf%%\n", a1 / n * 100);
    printf("%.2lf%%\n", a2 / n * 100);
    printf("%.2lf%%\n", a3 / n * 100);
    printf("%.2lf%%\n", a4 / n * 100);
    return 0;
}
