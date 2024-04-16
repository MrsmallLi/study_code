/*************************************************************************
	> File Name: 8.quick_sort.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 16 Apr 2024 03:25:22 PM CST
 ************************************************************************/

#include<iostream>
#include <ctime>
using namespace std;


void quick_sort(int *first, int *end) {
    if (first - end == 1) return ;
    int num = *first;
    int *a = first, *b = end - 1;
    while (a < b) {
        while (a < b && *b >= num) b--;
        if (a < b) *a = *b, a++;
        while (a < b && *a <= num) a++;
        if (a < b) *b = *a, b--;
    }
    *a = num;
    quick_sort(first, a);
    quick_sort(a + 1, end);
    return ;
}

int __median(int a, int b, int c) {
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    return b;
}

void nth_element(int *first, int *n, int *end) {
    if (end - first == 1)  return ;
    int *x = first, *y = end;
    int z = __median(*first, *end, *(first + (end - first) / 2));
    do {
        while (*x < z) ++x;
        while (z < *y) --y;
        if (x <= y) {
            swap(*x, *y);
        }
    } while (x <= y);
    
    return ;
}

void output(int *arr) {
    for (int i = 0; i < 10; i++) {
        i && cout << " ";
        cout << arr[i];
    }
    cout << endl;
    return ;
}

int main() {
    srand(time(0));
    int arr[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 100;
    }
    output(arr);
    quick_sort(arr, arr + 10);
    output(arr);
    return 0;
}
