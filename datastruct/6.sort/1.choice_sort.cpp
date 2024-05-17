/*************************************************************************
	> File Name: 1.choice_sort.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 13 May 2024 02:00:40 PM CST
 ************************************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

#define MAX_N 10
int arr[MAX_N + 5];

void output(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        i && cout << " ";
        cout << arr[i];
    }
    cout << endl;
    return ;
}

void select_sort(int *arr, int n) {
    for (int i = n - 1; i >= 1; i--) {
        int ind = i;
        for (int j = i - 1; j >= 0; j--) {
            if (arr[ind] < arr[j]) ind = j;
        }
        output(arr, n);
        swap(arr[ind], arr[i]);
    }


    return ;
}


int main() {
    srand(time(0));
    for (int i = 0; i < MAX_N; i++) arr[i] = rand() % 100;
    output(arr, MAX_N);
    select_sort(arr, MAX_N);
    output(arr, MAX_N);
    return 0;
}
