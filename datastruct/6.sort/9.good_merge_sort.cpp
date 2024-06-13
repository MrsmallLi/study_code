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

    void merge_sort(int l, int r) {
        if (r - l <= 1) return ;
        int mid = (l + r) >> 1;
        merge_sort(l, mid);
        merge_sort(mid, r);
        int *temp = new int[r - l];
        int p1 = l, p2 = mid, k = 0;
        while (p1 < mid || p2 < r) {
            if (p2 == r || (p1 < mid && arr[p1] <= arr[p2])) temp[k++] = arr[p1++];
            else temp[k++] = arr[p2++];
        }
        memcpy(arr + l, temp, sizeof(int) * (r - l));
        delete temp;
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

