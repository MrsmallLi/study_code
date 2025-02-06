/*************************************************************************
	> File Name: 1_3.c
	> Author: 
	> Mail: 
	> Created Time: Fri 24 Jan 2025 06:37:49 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct A {
    int key, ind;
} A;

typedef struct HashMap{
    int size, *flag;
    A *arr;
} HashMap;

HashMap *initHashMap(int n) {
    HashMap *mp = (HashMap *)calloc(sizeof(HashMap), 1);
    mp->arr = (A *)calloc(sizeof(A), (n + 5));
    mp->flag = (int *)calloc(sizeof(int), (n / 31 + 1));
    mp->size = n; 
    return mp;
}

int HashFun(int key) {
    return key & 0x7fffffff;
}

int check(HashMap *mp, int ind) {
    int x = ind / 31, y = ind % 31;
    return mp->flag[x] & (1 << y);
}

int set(HashMap *mp, int ind, A a) {
    int x = ind / 31, y = ind % 31;
    mp->flag[x] |= (1 << y);
    mp->arr[ind] = a;
    return 1;
}

void insert(HashMap *mp, int key, int val) {
    A d;
    d.key = key;
    d.ind = val;
    int ind = HashFun(key) % mp->size;
    int time = 1;
    while (check(mp, ind)) {
        ind += time * time;
        time++;
        ind %= mp->size;
    }
    set(mp, ind, d);
    return ;
}

int find(HashMap *mp, int key) {
    int ind = HashFun(key) % mp->size;
    int time = 1;
    while (check(mp, ind) && mp->arr[ind].key != key) {
        ind += time * time; 
        time++;
        ind %= mp->size;
    }
    if (check(mp, ind)) return mp->arr[ind].ind;
    return -1;
}

void clear(HashMap *mp) {
    if (!mp) return ;
    free(mp->flag);
    free(mp->arr);
    free(mp);
    return ;
}




int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    HashMap *mp = initHashMap(numsSize);
    int *ret = (int *)calloc(sizeof(int), 2);
    *returnSize = 0;
    for (int i = 0; i < numsSize; i++) {
        int find_ind = find(mp, target - nums[i]);
        if (find_ind >= 0) {
            ret[0] = i;
            ret[1] = find_ind;
            *returnSize = 2;
            return ret;
        }
        insert(mp, nums[i], i);
    }
    return ret;
}
