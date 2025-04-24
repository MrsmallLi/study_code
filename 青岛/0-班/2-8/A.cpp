/*************************************************************************
	> File Name: A.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 08 Feb 2025 03:37:22 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


int main() {
    string str;
    cin >> str;
    if (str.size() & 1) {
        cout << "No" << endl;
    } else {
        int mp[256] = {0};
        int n = str.size();
        int flag = 1;
        for (int i = 1; str[i];) {
            if (str[i] == str[i - 1] && !mp[str[i]]) {
                mp[str[i]] += 2;
                i += 2;
                continue;
            }
            flag = 0;
            break;
        }
        printf("%s\n", flag ? "Yes" : "No");
    }
    return 0;
}
