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

    void unguarded_insert_sort() {
        int ind = 0;
        for (int i = 1; i < n; i++) if (arr[i] < arr[ind]) ind = i;
        while (ind > 0) swap(arr[ind], arr[ind-- - 1]);
        for (int i = 1; i < n; i++) {
            for (int j = i; arr[j] < arr[j - 1]; j--) {
                swap(arr[j], arr[j - 1]);
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
    a.unguarded_insert_sort();
    a.output();
    return 0;
}

