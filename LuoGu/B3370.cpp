/*************************************************************************
	> File Name: B3370.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 26 Jan 2025 07:29:43 PM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Hash {
    char **arr;
    int size, cnt;
} Hash;

Hash *init(int n) {
    Hash *h = (Hash *)calloc(sizeof(Hash), 1);
    h->arr = (char **)calloc(sizeof(Hash), 20000);
    for (int i = 0; i < (n + 5); i++) {
        h->arr[i] = NULL;
    }
    h->size = 20000;
    h->cnt = 0;
    return h;
}

int Contrast_char(char *a, char *b) {
    return strcmp(a, b);
}

int HashFun(Hash *mp, char *s, int k) {
    long long ind = 0;
    for (int i = 0; s[i]; i++) {
        ind = (ind + i * s[i] * k) % mp->size;
    }
    if (mp->arr[ind]) {
        if (!Contrast_char(mp->arr[ind], s)) return -1;
        ind = HashFun(mp, s, k + 1);
    }
    return ind;
}

void insert(Hash *mp, char *s) {
    if (!mp) return ;
    int key = HashFun(mp, s, 1);
    if (key < 0) return ;
    mp->cnt += 1;
    mp->arr[key] = s;
    return ;
}

void free_Hash(Hash *mp) {
    if (!mp) return ;
    for (int i = 0; i < mp->size; i++) free(mp->arr[i]);
    free(mp);
    return ;
}


int main() {
    int n;
    scanf("%d", &n);
    Hash *mp = init(n);
    for (int i = 0; i < n; i++) {
        char *s = (char *)calloc(sizeof(char), 2000);
        scanf("%s", s);
        insert(mp, s);
    }
    printf("%d\n", mp->cnt);
    return 0;
}
