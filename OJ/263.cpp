/*************************************************************************
	> File Name: 263.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 12 Apr 2024 09:49:57 AM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;
int n;
int arr[25];
int cnt[25] = {0};

void output() {
    for (int i = 0; i < n; i++) {
        cout << arr[i];
    }
    cout << endl;
    return ;
}

void push(vector<int> &nums, vector<int> &train, int num) {
    for (int i = 1; i <= num; i++) {
        if (train[i]) continue;
        nums.push_back(i);
        train[i] = 1;
    }
    return ;
}

bool is_true_tain() {
    vector<int> train(25, 0);
    vector<int> num;
    for (int i = 0; i < n; i++) {
        if (num.empty() || (!num.empty() && num.back() < arr[i])) {
            push(num, train, arr[i]);
        }
        if (num.back() == arr[i]) {
            num.pop_back(); 
        } else {
            return false;   
        }
    }
    return true; 
}

void func(int i, int *k) {
    if (*k == 20) return ;
    if (i == n) {
        if (is_true_tain()) {
            output();
            *k += 1;
        }
        return ;
    }
    for (int j = 1; j <= n; j++) {
        if(cnt[j]) continue;
        arr[i] = j;
        cnt[j] = 1;
        func(i + 1, k);
        cnt[j] = 0;
    }
    return ;
}

int main() {
    cin >> n;
    int k = 0;
    func(0, &k);
    return 0;
}
