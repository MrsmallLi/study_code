/*************************************************************************
	> File Name: 7.371C.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 12 Mar 2025 06:47:43 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define int long long

int arr[5];
string str;
int b, s, c, rc;
int spend[5];

bool check(int x) {
    int sb = x * spend[0] - b;
    int ss = x * spend[1] - s;
    int sc = x * spend[2] - c;
    int temp = (sb >= 0 ? sb : 0) * arr[0] + (ss >= 0 ? ss : 0) * arr[1] + (sc >= 0 ? sc : 0) * arr[2];
    return (rc - temp >= 0);
}

int find() {
    int l = 0, r = rc + 100, mid;
    while (l < r) {
        mid = (l + r + 1) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

int32_t main() {
    cin >> str;
    for (int i = 0; str[i]; i++) {
        switch(str[i]) {
            case 'B': {
                spend[0] += 1;
            } break;
            case 'S': {
                spend[1] += 1;
            } break;
            case 'C': {
                spend[2] += 1;
            } break;
        }
    }
    cin >> b >> s >> c;
    for (int i = 0; i < 3; i++) cin >> arr[i];
    cin >> rc;
    cout << find() << endl;
    return 0;
}
