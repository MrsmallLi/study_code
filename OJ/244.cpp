/*************************************************************************
	> File Name: 244.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 25 Oct 2024 02:20:33 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX_N 500


class Point {
public : 
    Point() : x(0), y(0){}
    Point(int x, int y) : x(x), y(y) {}
    int x, y;
};

int check_y(Point *arr, int l, int c, int n, int i, int j) {
    vector<int> temp;
    for (int k = j; k <= i; k++) {
        temp.push_back(arr[k].y);
    }
    sort(temp.begin(), temp.end());
    int len = temp.size();
    for (int k = c - 1; k < len; k++) {
        if (temp[k] - temp[k - c + 1] < l) return 1;
    }
    return 0;
}

int check(Point *arr, int l, int c, int n) {
    int j = 0;
    for (int i = 1; i < n; i++) {
        while (arr[i].x - arr[j].x >= l) j += 1;
        if (i - j + 1 < c) continue;
        if (check_y(arr, l, c, n, i, j)) return 1;
    }
    return 0;
}


int find(Point *arr, int c, int n) {
    int head = 0, tail = 10000, mid;
    while (head < tail) {
        mid = (head + tail) / 2;
        if (check(arr, mid, c, n)) tail = mid;
        else head = mid + 1;

    }
    return head;
}

bool cmp(Point &a, Point &b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}


int main() {
    int c, n;
    cin >> c >> n;
    Point arr[MAX_N + 5];
    for (int i = 0; i < n; i++) {
        cin >> arr[i].x >> arr[i].y;
    }
    sort(arr, arr + n, cmp);
    cout << find(arr, c, n) << endl;
    return 0;
}
