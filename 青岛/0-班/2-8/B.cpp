/*************************************************************************
	> File Name: B.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 08 Feb 2025 03:50:45 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;


int main() {
    int n;
    cin >> n;
    string str;
    cin >> str;
    int one = 0, two = 0, flag = 0, ans = 0;
    for (int i = 0; str[i]; i++) {
        switch (str[i]) {
            case '1' : {
                if (flag) {
                    two  = 0;
                    flag = 0;
                    one = 1;
                } else {
                    one += 1;
                }
            } break;
            case '2' : {
                if (!flag) {
                    one = 0;
                    flag = 0;
                    two = 0;
                    continue;    
                }
                two += 1;
                ans = max(ans, min(one, two) * 2 + flag);
            } break;
            case '/' : {
                if (two || flag) {
                    two = 0, one = 0; 
                }
                flag = 1;
                ans = max(ans, flag); 
            } break;
        }
    }
    cout << ans << endl;

    return 0;
}
