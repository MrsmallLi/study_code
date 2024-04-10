/*************************************************************************
	> File Name: 2.cin_cout.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 09 Apr 2024 09:27:46 AM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    sort();
    cin >> n;
    cout << n << endl;
    //如果没有using namespace std语句
    //就需要写成下面的形式
    std::cin >> n;
    std::cout << n << std::endl;
    return 0;
}

