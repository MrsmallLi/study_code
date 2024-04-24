/*************************************************************************
	> File Name: 2.heap_sort.c
	> Author: 
	> Mail: 
	> Created Time: Mon 22 Apr 2024 04:36:41 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define cmp >
#define ROOT 1
#define FATHER(i) ((i) / 2)
#define RIGHT(i) ((i) * 2 + 1)
#define LEFT(i) ((i) * 2)
#define swap(a, b) {\
    __typeof(a) __a = a;\
    (a) = (b);\
    (b) = __a;\
}

#define TEST(func, arr, n) {\
    printf("TEST : %s\n", #func);\
    int *temp = (int *)malloc(sizeof(int) * n);\
    memcpy(temp, arr, sizeof(int) * n);\
    long long b = clock();\
    func(temp, n);\
    long long e = clock();\
    if (check(temp, n)) {\
        printf("is OK\n");\
    } else {\
        printf("Fail\n");\
    }\
    printf("%lld ms\n", 1000 * (e - b) / CLOCKS_PER_SEC);\
    free(temp);\
}

int *getRandData(int n) {
    int *arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) arr[i] = rand() % 1000;
    return arr;
}

void up_updata(int *data, int i) {
    while (i > 1 && data[i] cmp data[FATHER(i)]) {
        swap(data[i], data[FATHER(i)]);
        i = FATHER(i);
    }
    return ;
}

void normal_heap_build(int *data, int n) {
    //从上往下向上调整
    for (int i = 2; i <= n; i++) {
        up_updata(data, i);
    }
    return ;
}

void down_updata(int *, int , int);

void heap_sort(int *data, int n) {
    for (int i = n; i >= 1; i--) {
        swap(data[1], data[i]);
        down_updata(data, 1, i - 1);
    }
    return ;
}


//普通建堆
void normal_heap(int *arr, int n) {
    int *data = arr - 1;
    normal_heap_build(arr, n);
    heap_sort(data, n);
}

void down_updata(int *data, int i, int n) {
    while (LEFT(i) <= n)  {
        int ind = i, l = LEFT(i), r = RIGHT(i);
        if (data[l] cmp data[ind]) ind = l;
        if (r <= n && data[r] cmp data[ind]) ind = r;
        if (i == ind) break;
        swap(data[i], data[ind]);
        i = ind;
    }
    return ;
}

void linear_heap_build(int *data, int n) {
    //从下往上进行向下调整
    for (int i = n / 2; i >= 1; i--) {
        down_updata(data, i, n);
    }
    return ;
}

void liner_heap(int *arr, int n) {
    int *data = arr - 1;
    linear_heap_build(data, n);
    heap_sort(data, n);
}

int check(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) return 0;
    }
    return 1;
}

int main() {
    srand(time(0));
    #define MAX_N 100000000
    int *arr = getRandData(MAX_N);
    TEST(normal_heap, arr, MAX_N);
    TEST(liner_heap, arr, MAX_N);
    return 0;
}
