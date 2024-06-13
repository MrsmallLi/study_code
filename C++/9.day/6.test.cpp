/*************************************************************************
	> File Name: 6.test.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 12 Jun 2024 02:22:27 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

string add(string a, string b) {
    return a + b;
}

int main() {
    cout << add(1, 2) << endl;
    cout << add(2.1, 3.3) << endl;
    string a = "hello", b = "world";
    cout << add(a, b) << endl;

    return 0;
}
