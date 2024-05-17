/*************************************************************************
	> File Name: 3.bubble_sort.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 13 May 2024 02:47:35 PM CST
 ************************************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


#define MAX_N 10

class Arr {
public : 
    Arr() : arr(new int[MAX_N]), n(MAX_N) {
        for (int i = 0; i < n; i++) arr[i] = rand() % 100;
    }
    void output() {
        for (int i = 0; i < n; i++) {
            i && cout << " ";
            cout << arr[i];
        }
        cout << endl;
        return ;
    }
    void bubble_sort() {
        int time = 1;
        for (int i = 1; i < n && time; i++) {
            time = 0;
            for (int j = 0; j < n - i; j++) {
                if (arr[j] <= arr[j + 1]) continue;
                swap(arr[j], arr[j + 1]);
                time = 1;
            }
        }
        return ;
    }
    void bubble_sort_two() {
        int time = 1;
        for (int i = n - 1, I = 1; i >= I && time; i--) {
            time = 0;
            for (int j = 0; j < i; j++) {
                if (arr[j] <= arr[j + 1]) continue;
                swap(arr[j], arr[j + 1]);
                time = 1;
            }
        }
        return ;
    }
private :
    int *arr;
    int n;
};


int main() {
    srand(time(0));
    Arr a;
    a.output();
    a.bubble_sort_two();
    a.output();
    return 0;
}
