/*************************************************************************
	> File Name: P4305.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 14 Feb 2025 09:33:30 AM CST
 ************************************************************************/


#include <cstdlib>
#include <cstdio>
#include <map>
using namespace std;

#define MAX_N 50000

/**

typedef struct Hash {
    int *arr;
    int size;
    int *flag;
} Hash;

Hash *init(int n) {
    Hash *h = (Hash *)malloc(sizeof(Hash) * 1);
    //开辟空间，进行初始化空间为0
    h->arr = (int *)calloc(3 * n, sizeof(int));
    h->flag = (int *)calloc((3 * n) / 31 + 1, sizeof(int));
    h->size = 3 * n;
    return h;
}

//不一定是这样设计的
int Hash_Fun(Hash *h, int key) {
    return (key & 0x7fffffff) % h->size;
}

//判断当前ind位置是否存储元素
int check(Hash *h, int ind) {
    int x = ind / 31, y = ind % 31; 
    return h->flag[x] & (1 << y);
}

void set(Hash *h, int ind) {
    int x = ind / 31, y = ind % 31;
    h->flag[x] |= (1 << y);
    return ;
}

void insert(Hash *h, int key) {
    int ind = Hash_Fun(h, key);
    int temp = 1;
    while (check(h, ind)) {
        ind += temp * temp;
        ind = ind % h->size;
        temp += 1;
    }
    set(h, ind);
    h->arr[ind] = key;
    return ;
}

int find(Hash *h, int key) {
    int ind = Hash_Fun(h, key);
    int temp = 1;
    while (check(h, ind) && h->arr[ind] != key) {
        ind += temp * temp;        
        ind = ind % h->size;
        temp += 1;
    }
    if (check(h, ind) && h->arr[ind] == key) return 1;
    return 0;
}

**/

int main() {
    int t;
    scanf("%d", &t);
    while (t) {
        t -= 1;
        int n;
        scanf("%d", &n);
        int arr[MAX_N + 5] = {0};
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        //int num[MAX_N + 5] = {0};
        //Hash *h = init(3 * n);
        map<int, int> mp;
        int flag = 0;
        for (int i = 0; i < n; i++) {
            //if (find(h, arr[i]) == 1) continue;
            //第一种方法
            if (mp[arr[i]] == 1) continue;
            //第二种方法
            //if (mp.find(arr[i]) != mp.end()) continue;
            //第三种方法
            //if (mp.count(arr[i]) == 1) continue;
            if (flag == 1) printf(" ");
            printf("%d", arr[i]);
            flag = 1;
            //num[arr[i]] = 1;
            //insert(h, arr[i]);
            //第一种添加方法
            mp[arr[i]] = 1;
            //添加方法
            //mp.insert({arr[i], 1});
        }
        printf("\n");
    }
    return 0;
}
