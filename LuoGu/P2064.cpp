/*************************************************************************
	> File Name: P2064.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 08 Feb 2025 10:20:41 AM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Fbnumber : public vector<int> {
public :
    Fbnumber(int n) : n(n) {
        push_back(1);
        push_back(1);
        for (int i = 2; i <= n; i++) {
            int num = at(i - 1) + at(i - 2);
            push_back(num);
        }
    }
    
    int n;
};




int main() {
    int n;
    cin >> n;
    Fbnumber num(30);
    while (n--) {
        int a;
        cin >> a;
        cout << num[a - 1] << endl;
    }


    return 0;
}
