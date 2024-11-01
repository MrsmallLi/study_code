/*************************************************************************
	> File Name: 18.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 25 Oct 2024 03:45:48 PM CST
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

double func(double a, double b, double c, double d, double x) {
    double ret = a * pow(x, 3) + b * pow(x, 2) + c * x + d;
    return ret;
}

int main() {
    double a, b, c, d, x;
    cin >> a >> b >> c >> d >> x;
    printf("%.7lf\n", a * pow(x, 3) + b * pow(x, 2) + c * x + d);
    //printf("%.7lf\n", func(a, b, c, d, x));



}
