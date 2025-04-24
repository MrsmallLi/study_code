/*************************************************************************
	> File Name: B.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 10 Feb 2025 11:27:36 AM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

#define MAX_N 200000
#define int long long 

class node {
public :
    int num, ind;
};

node arr1[MAX_N + 5];
node arr2[MAX_N + 5];
node arr3[MAX_N + 5];
int ans[MAX_N + 5];

bool CMP(const node &a, const node &b) {
    return a.num > b.num;
}
void find(node *arr, int n) {
    int pre = 1;
    for (int i = 1; i <= n; i++)  {
        if (arr[i].num == arr[i - 1].num) {
            ans[arr[i].ind] = min(ans[arr[i].ind], pre);
        } else {
            ans[arr[i].ind] = min(ans[arr[i].ind], i);
            pre = i;
        }
    }
    return ;
}

int32_t main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr1[i].num >> arr2[i].num >> arr3[i].num;
        arr1[i].ind = arr2[i].ind = arr3[i].ind = i;
        ans[i] = INT_MAX;
        //printf("j = %d, y = %d, t = %d\n", arr1[i].num, arr2[i].num, arr3[i].num);
    }
    sort(arr1 + 1, arr1 + n + 1, CMP);
    sort(arr2 + 1, arr2 + n + 1, CMP);
    sort(arr3 + 1, arr3 + n + 1, CMP);
    find(arr1, n);
    find(arr2, n);
    find(arr3, n);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
