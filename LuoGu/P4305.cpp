/*************************************************************************
	> File Name: P4305.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 11 Feb 2025 06:58:59 PM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 50000

int arr[MAX_N + 5];

#define Data int

/*typedef Data{
    int val 
} Data; */


typedef struct {
    Data *data;
    int *flag;
    int size;
} Hash;

Hash *init(int n) {
    Hash *h = (Hash *)calloc(sizeof(Hash), 1);
    h->data = (Data *)malloc(sizeof(Data) * n);
    h->flag = (int *)calloc(sizeof(int), n / 31 + 1);
    h->size = n;
    return h;
}

int BDKhash(Hash *h, int val) {
     return (val & 0x7fffffff) % h->size;
}

int cheak(Hash *h, int ind) {
    int x = ind / 31, y = ind % 31;
    return h->flag[x] & (1 << y);
}

void set(Hash *h, int ind, Data d) {
    int x = ind / 31, y = ind % 31;
    h->flag[x] |= (1 << y);
    h->data[ind] = d;
    return ;
}

void insert(Hash *h, int val) {
    Data d = {val};
    int ind = BDKhash(h, val);
    int times = 1;
    while (cheak(h, ind)) {
        ind += times * times;
        times++;
        ind %= h->size;
    }
    set(h, ind, d);
    return ;
}

int find(Hash *h, int val) {
    int ind = BDKhash(h, val);
    int times = 1;
    while (cheak(h, ind) && h->data[ind] != val) {
        ind += times * times;
        times++;
        ind %= h->size;
    }
    if (cheak(h, ind) && h->data[ind] == val) return 1;
    return 0;
}

void free_hash(Hash *h) {
    if (!h) return ;
    free(h->data);
    free(h->flag);
    free(h);
    return ;
}

int main() {
    int t;
    cin >> t;
    char a[35] = {0};
    //int val = 0x7fffffff;
    int val = 8;
    for (int i = 32; i > 0; i--) {
        a[i] = (val & 1) + '0';
        val >>= 1;
    }
    for (int i = 1; i <= 32; i++) printf("%c", a[i]);
    printf("\n");
    while (t) {
        t -= 1; 
        int n;
        cin >> n;
        Hash *mp = init(3 * n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        int flag = 0;
        for (int i = 0; i < n; i++) {
            if (find(mp, arr[i])) continue;
            if (flag) cout << " ";
            insert(mp, arr[i]);
            cout << arr[i];
            flag = 1;
        }
        cout << endl;
        free_hash(mp);
    }
    return 0;
}
