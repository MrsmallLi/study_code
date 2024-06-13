/*************************************************************************
	> File Name: 2.sort.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 26 May 2024 08:01:18 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

#define BEGIN_SAPCE(name) namespace name {
#define END_SPACE }

BEGIN_SAPCE(my) 

template<typename T, typename Func_T>
T __median(T a, T b, T c, Func_T cmp) {
    if (cmp(a, b)) swap(a, b);
    if (cmp(c, b)) swap(c, b);
    return b;
}

template<typename iterator>
//void sort(iterator begin, iterator end, std::function<bool(decltype(*begin), decltype(*begin))> cmp = std::less<decltype(*begin)>()) {
void sort(iterator begin, iterator end, 
          std::function<bool(typename std::iterator_traits<iterator>::value_type, 
          typename std::iterator_traits<iterator>::value_type)> cmp = 
          std::less<typename std::iterator_traits<iterator>::value_type>()
         ) {
    iterator x = begin, y = end - 1;
    if (end - begin < 2) return ;
    typename remove_reference<decltype(*begin)>::type z = __median(*x, *(begin + (end - begin) / 2), *y, cmp);
    do {
        while (cmp(*x, z)) x++;
        while (cmp(z, *y)) y--;
        if (x <= y) {
            swap(*x, *y);
            ++x, --y;
        }

    } while(x <= y);
    ++y;
    sort(begin, y, cmp);
    sort(x, end, cmp);
    return ;
}


END_SPACE


int *getRanData(int n) {
    int *arr = new int[n];
    for (int i = 0; i < n; i++) arr[i] = rand() % 100;
    return arr;
}

template<typename T>
void output(T *arr, T *end) {
    printf("arr : ");
    for (T *p = arr; p < end; p++) {
        p != arr && printf(" ");
        printf("%d", *p);
    }
    putchar(10);
    return ;
}

bool cmp1(int a, int b) { return a > b; }

typedef class CMP {
public :
    bool operator()(int a, int b) { return a < b; }
} cmp2;

int main() {
    srand(time(0));
    #define MAX_N 10
    int *arr1 = getRanData(MAX_N);
    output(arr1, arr1 + MAX_N);
    my::sort(arr1, arr1 + MAX_N);
    output(arr1, arr1 + MAX_N);

    my::sort(arr1, arr1 + MAX_N, cmp1);
    output(arr1, arr1 + MAX_N);

    my::sort(arr1, arr1 + MAX_N, cmp2());
    output(arr1, arr1 + MAX_N);

    my::sort(arr1, arr1 + MAX_N, greater<int>());
    delete arr1;
    return 0;
}
