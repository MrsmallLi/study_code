/*************************************************************************
	> File Name: K.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 10 Feb 2025 08:32:13 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using namespace std;

#define MAX_N 200000

class A {
public :
    int s, w, ind;
};

A arr[MAX_N + 5];

bool CMP(A a, A b) {
    if (a.s == b.s) return a.ind < b.ind;
    return a.s > b.s;
}
bool CMP1(A a, A b) {
    return a.w > b.w;
}

A win[MAX_N + 5];
A lose[MAX_N + 5];
int p1, p2;

void merge(int n) {
    int k = 1, g = 1;
    for (int i = 1; i <= 2 * n; i++) {
        if (g > p2 || (k <= p1 && CMP(win[k], lose[g])))  {
            arr[i] = win[k++];
        } else {
            arr[i] = lose[g++];
        }
    }
    return ;
}

/*

void func(int l, int r) {
    if (r - l <= 1) {
        if (r - l == 1) {
            arr[r].s += (arr[r].w > arr[l].w ? 1 : 0);
            arr[l].s += (arr[l].w > arr[r].w ? 1 : 0);
            if (CMP(arr[r], arr[l])) {
                swap(arr[r], arr[l]);
            }
        }
        return ;
    }
    int mid = (l + r) >> 1;
    func(l, mid);n
    func(mid + 1, r);
    A *temp = (A *)malloc(sizeof(A) * (r - l + 1));
    int p1 = l, p2 = mid + 1;
    for (int i = 0; i < (r - l + 1); i++) {
        if (p2 > r || (p1 <= mid && CMP(arr[p1], arr[p2]))) {
            temp[i] = arr[p1++];
        } else {
            temp[i] = arr[p2++];
        }
    }
    memcpy(arr + l, temp, sizeof(A) * (r - l + 1));
    free(temp);
    return ;
}
*/

int main() {
    int n, r, q;
    cin >> n >> r >> q;
    r = r;
    for (int i = 1; i <= 2 * n; i++) {
        scanf("%d", &arr[i].s);
    }
    for (int i = 1; i <= 2 * n; i++) {
        scanf("%d", &arr[i].w);
        arr[i].ind = i;
    }
    sort(arr + 1, arr + 2 * n + 1, CMP);
   while (r--) {
        p1 = 0, p2 = 0;
        for (int i = 1; i <= 2 * n; i += 2) {
            if (CMP1(arr[i], arr[i + 1])) {
                arr[i].s += 1;
                win[++p1] = arr[i];
                lose[++p2] = arr[i + 1];
            } else {
                arr[i + 1].s += 1;
                lose[++p1] = arr[i];
                win[++p2] = arr[i + 1];
            }
        }
        merge(n);
       /*
        for (int i = 1; i <= 2 * n; i++) {
            printf("i = %d, s = %d, w = %d\n", arr[i].ind, arr[i].s, arr[i].w);
        }
        cout << "========================" << endl;
        */
    }
    cout << arr[q].ind << endl;
    return 0;
}

