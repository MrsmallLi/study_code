/*************************************************************************
	> File Name: 6.quick_sort.cpp
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

    void quick_sort(int l, int r) {
        if (r - l <= 2) {
            if (r - l <= 1) return ;
            if (arr[l] > arr[l + 1]) swap(arr[l], arr[l + 1]);
            return ;
        }
        int x = l, y = r - 1, z = arr[l];
        while (x < y) {
            while (x < y && arr[y] >= z) y--;
            if (x < y) arr[x++] = arr[y];
            while (x < y && arr[x] <= z) x++;
            if (x < y) arr[y--] = arr[x];
        }
        arr[x] = z;
        quick_sort(l, x - 1);
        quick_sort(x + 1, r);
        return ;
    }
    
    void quick_sort_two(int l, int r) {
            if (r - l <= 2) {
                if (r - l <= 1) return ;
                if (arr[l] > arr[l + 1]) swap(arr[l], arr[l + 1]);
                return ;
            }
            int x = l, y = r - 1, z = arr[l];
            do {
                while (arr[x] < z) ++x;
                while (arr[y] > z) --y;
                if (x <= y) {
                    swap(arr[x], arr[y]);
                    ++x, --y;
                }
            } while (x <= y);
            arr[x] = z;
            quick_sort(l, y);
            quick_sort(x, r);
        return ;
    }
    int three_point_select(int a, int b, int c) {
        if (a > b) swap(a, b);
        if (a > c) swap(a, c);
        if (b > c) swap(b, c);
        return b;
    }
    void quick_sort_three(int l, int r) {
        while (r > l) {
            if (r - l <= 2) {
                if (r - l <= 1) return ;
                if (arr[l] > arr[l + 1]) swap(arr[l], arr[l + 1]);
                return ;
            }
            int x = l, y = r - 1;
            int z = three_point_select(
                arr[l],
                arr[r - 1],
                arr[(l + r)>>1]
            );
            do {
                while (arr[x] < z) ++x;
                while (arr[y] > z) --y;
                if (x <= y) {
                    swap(arr[x], arr[y]);
                    ++x, --y;
                }
            } while (x <= y);
            quick_sort(l, x);
            l = x;
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
    a.quick_sort_three(0, a.get_n());
    a.output();
    return 0;
}

