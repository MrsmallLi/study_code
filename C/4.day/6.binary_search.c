/*************************************************************************
	> File Name: 6.binary_search.c
	> Author: 
	> Mail: 
	> Created Time: Thu 21 Mar 2024 05:25:59 PM CST
 ************************************************************************/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//顺序查找
void find_1(int arr[], int x) {
    int cnt1 = 0;
    int flag1 = 0;
    for (int i = 0; i < 10; i++) {
        cnt1 += 1;
        if (arr[i] != x) continue;
        flag1 = 1;
        break;
    }
    if (flag1) {
        printf("Ok, find numbe, cnt = %d\n", cnt1);
    } else {
        printf("Not find cnt = %d\n", cnt1);
    }
}

//二分查找
void binary_search(int arr[], int n, int x) {
    int flag = 0;
    int cnt1 = 0;
    int head = 0, tail = n - 1;//定义头尾指针;
    while (head <= tail) {//当尾指针小于头指针时说明，没有找到结束循环
        cnt1++;
        int mid = (head + tail) >> 1;//mid在头尾指针的中间
        //数组是单调递增
        //中间的位置都大于x说明在后半区域没有x,所以去掉
        if (arr[mid] > x) tail = mid - 1;//因为mid位置也不等于x,可以把mid位置去掉,也就是-1
        //中间的位置都小于x说明在前半区域没有x,所以去掉
        else if (arr[mid] < x) head = mid + 1;
        else {
            //说明找到了
            flag = 1;
            break;
        }
    }
    if (flag) {
        printf("Ok, find numbe, cnt = %d\n", cnt1);
    } else {
        printf("Not find cnt = %d\n", cnt1);
    }
    return ; 
}

int main() {
    //产生一个随机种子
    srand(time(0));
    int arr[10] = {0};
    for (int i = 1; i < 10; i++) {
        arr[i] = arr[i - 1] + (rand() % 10);
    }
    for (int i = 0; i < 10; i++) {
        i && printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");
    int x;
    scanf("%d", &x);
    find_1(arr, x);
    binary_search(arr, 10, x);
    return 0;
}
