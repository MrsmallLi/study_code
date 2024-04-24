/*************************************************************************
	> File Name: 3.line_priority_queue.c
	> Author: 
	> Mail: 
	> Created Time: Mon 22 Apr 2024 04:58:11 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(a, b) {\
    __typeof(a) __a = (a);\
    (a) = (b);\
    (b) = __a;\
}

int *getNewData(int n) {
    int *arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) arr[i] = rand() % 1000;
    return arr;
}

void down_updata(int *, int, int);

//堆排序
void heap_sort(int *data, int n) {
    for (int i = n; i >= 1; i--) {
        swap(data[1], data[i]);
        down_updata(data, 1, i - 1);
    }
    return ;
}

void down_updata(int *data, int i, int n) {
    while ((i << 1) <= n) {
        int ind = i, l = i << 1, r = (i << 1) + 1;
        if (data[l] > data[ind]) ind = l;
        if (r <= n && data[r] > data[ind]) ind = r;
        if (i == ind) break;
        swap(data[i], data[ind]);
        i = ind;
    }
    return ;
}

void line_bulid_pq(int *data, int n) {
    for (int i = n / 2; i >= 1; i--) {
        down_updata(data, i, n);
    }
}
//线性键堆法
void line_pq(int *arr, int n) {
    int *data = arr - 1;
    line_bulid_pq(data, n);
    heap_sort(data, n);
}

int check(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) return 0;
    }
    return 1;
}

void output(int *arr, int n) {
    if (!check(arr, n)) {
        printf("is fail\n");
        return ;
    }
    for (int i = 0; i < n; i++) {
        i && printf(" ");
        printf("%d", arr[i]);
    }
    putchar(10);
    return ;
}

int main() {
    srand(time(0));
    #define MAX_N 100
    int *arr = getNewData(MAX_N);
    line_pq(arr, MAX_N);
    output(arr, MAX_N);
    return 0;
}
