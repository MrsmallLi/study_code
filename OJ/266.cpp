/*************************************************************************
	> File Name: 266.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 12 Apr 2024 02:18:33 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define INF 0x3f3f3f3f

int calc(string &str, int l, int r) {
    int pos = -1, pri = INF - 1, cur_pri, temp_pri = 0; 
    for (int i = l; i < r; i++) {
        cur_pri = INF;
        switch (str[i]) {
            case '(' : temp_pri += 100; break;
            case ')' : temp_pri -= 100; break;
            case '+' : 
            case '-' :  cur_pri += 1 + temp_pri; break;
            case '*' :
            case '/' : cur_pri += 2 + temp_pri; break;
            case '^' : cur_pri += 3 + temp_pri; break;
        }
        if (pri >= cur_pri) {
            pri = cur_pri;
            pos = i;
        }
    }
    if (pos == -1) {
        int num = 0;
        for (int i = l; i < r; i++) {
            if (str[i] < '0' || str[i] > '9') continue;
            num = num * 10 + (str[i] - '0');
        }
    }
}



int main() {
    string str;   
    cin >> str;
    cout << calc(str, 0, str.size()) << endl;
    return 0;
}
