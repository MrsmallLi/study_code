/*************************************************************************
	> File Name: 6.quick_sort.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 13 May 2024 02:23:47 PM CST
 ************************************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>

using namespace std;
#define MAX_N 10

class Arr {
public :
    Arr() : arr(new int[MAX_N + 5]), n(MAX_N) {
        for (int i = 0; i < n; i++) arr[i] = rand() % 100;
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

    int get_n() {
        return n;
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
    a.merge_sort(0, a.get_n());
    a.output();
    return 0;
}

