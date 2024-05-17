/*************************************************************************
	> File Name: 2.insert_sort.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 13 May 2024 02:23:47 PM CST
 ************************************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
#define MAX_N 10

class Arr {
public :
    Arr() : arr(new int[MAX_N + 5]), n(MAX_N) {
        for (int i = 0; i < n; i++) arr[i] = rand() % 100;
    }

    void shell_sort() {
        int step;
        for (step = n / 2; step > 0; step >>= 1) {
            for (int i = step; i < n; i++) {
                for (int j = i; j >= step && arr[j] < arr[j - step]; j -= step) {
                    swap(arr[j], arr[j - step]);
                }
            }
        }
        return ;
    }
    void output() {
        for (int i = 0; i < n; i++) {
            i && cout << " ";
            cout << arr[i];
        }
        cout << endl;
    }

    int &operator[](int x) {
        return arr[x];
    }

    ~Arr() {
        delete arr;
    }

private :
    int *arr;
    int n;
};


int main() {
    srand(time(0));
    Arr a;
    a.output();
    a.shell_sort();
    a.output();
    return 0;
}

