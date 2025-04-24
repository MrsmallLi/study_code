/*************************************************************************
	> File Name: 363B.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 28 Feb 2025 03:14:31 PM CST
 ************************************************************************/

#include <iostream>
#include <climits>
using namespace std;

#define MAX_N 150000

int arr[MAX_N + 5];

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    int head = 1, tail = 1;
    //记录每次窗口中的栅栏高度和
    long long sum = 0;
    //用来记录滑动窗口中最小的连续的栅栏高度和
    long long ans = INT64_MAX;
    //用来记录最小的连续的栅栏的开始位置
    long long ans_ind = 0;
    for (int i = 1; i <= n; i++) {
        //将尾部元素进行入窗口
        //并将尾指针往后偏移
        sum += arr[tail++];
        //tail - head < k说明窗口中的元素还未有k个
        if (tail - head < k) continue;
        //当前记录之前的连续k个的栅栏高度和比当前窗口中的高度和大
        //那么就需要更新
        if (ans > sum) {
            ans = sum; 
            ans_ind = head;
        }
        //减去窗口第一个元素，窗口队头需要出队
        sum -= arr[head++];
    }
    cout << ans_ind << endl;
    return 0;
}
