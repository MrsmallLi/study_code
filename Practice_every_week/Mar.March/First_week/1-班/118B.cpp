/*************************************************************************
	> File Name: 118B.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 27 Feb 2025 07:35:56 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


void func(int n) {
    //这层层循环表示有多少层
    for (int i = 0; i < 2 * n + 1; i++) {
        //m表示对比x轴的偏移量
        int m = abs(n - i);
        for (int j = 0; j < 2 * m; j++) cout << " ";
        //num表当前这层示y轴上的数字
        int num = n - m;
        //temp表示当前这层需要输出多少个数字
        int temp = 2 * (n - m) + 1;
        for (int k = 0; k < temp; k++) {
            k && cout << " ";
            //abs(num - k)对比y轴上的偏移量
            //s就是在y轴上减去对比y轴的偏移得到该位置的数字
            int s = num - abs(num - k);
            cout << s;
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    func(n);
    return 0;
}
