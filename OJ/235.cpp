/*************************************************************************
	> File Name: 235.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 21 Oct 2024 02:58:23 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int num[15];
int n;
int ind = 0;

void output() {
    for (int i = 0; i < ind; i++) {
        i && cout << " ";
        cout << num[i];
    }
    cout << endl;
    return ;
}


void func(int x) {
    for (int i = x; i <= n; i++) {
        num[ind++] = i;
        output();
        func(i + 1);
        ind--;
    }
    return ;
}


int main() {
    cin >> n;
    func(1);



    return 0;
}
