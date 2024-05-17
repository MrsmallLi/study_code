/*************************************************************************
	> File Name: 3.binary_search.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 16 May 2024 03:49:42 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

#define swap(a, b) {\
    __typeof(a) _a = a;\
    a = b;\
    b = _a;\
}

int binary_search(int *arr, int n, int x) {
    //找到起点和终点
    int head = 0, tail = n - 1, mid; 
    //重复操作
    while (tail >= head) {
        //确定中点位置
        mid = (head + tail) / 2;
        //数组为单调递增
        //如果查找元素大于中点，说明元素在中点右半区域,所以舍弃左半区域和中点
        if (arr[mid] < x) head = mid + 1;
        //如果查找元素小于中点，说明元素在中点左半区域,所以舍弃左半区域和中点
        else if (arr[mid] > x) tail = mid - 1;
        //找到元素，返回元素索引
        else return mid;
    }
    //说明没有找到返回-1
    return -1;
}

void output(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        i && printf(" ");
        printf("%d", arr[i]);
    }
    putchar(10);
    return ;
}

int mid_num(int a, int b, int c) {
    if (a > b) swap(a, b);
    if (a > c) swap(a, c);
    if (b > c) swap(b, c);
    return b;
}

//将数组使用快速排序，使数组成为递增序列
void my_sort(int *arr, int l, int r) {
    while (r > l) {
        if (r - l <= 2) {
            if (r - l <= 1) return ;
            if (arr[l] > arr[l + 1]) swap(arr[l], arr[l + 1]);
        }
        int x = l, y = r - 1;
        int z = mid_num(arr[x], arr[y], arr[(x + y)>>1]);
        do {
            while (arr[x] < z) ++x;
            while (arr[y] > z) --y;
            if (x <= y) {
                swap(arr[x], arr[y]);
                ++x, --y;
            }
        } while(x <= y);
        my_sort(arr, l, x);
        l = x;
    }
}

int main() {
    srand(time(0));
    #define MAX_N 10
    int arr[MAX_N + 5];
    for (int i = 0; i < MAX_N; i++) arr[i] = rand() % 100;
    my_sort(arr, 0, MAX_N);
    output(arr, MAX_N);
    int x;
    while (~scanf("%d", &x)) {
        if (x == -1) break;
        printf("%d is at arr %d\n", x, binary_search(arr, MAX_N, x));
    }
    return 0;
}
