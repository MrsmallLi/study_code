/*************************************************************************
	> File Name: 4C.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 27 Feb 2025 03:44:37 PM CST
 ************************************************************************/

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

#define MAX_N 100000

//unordered_map对比map，不会讲键用来排序
//因为这里用不到排序所以使用unordered_map
//讲键字符串映射为值出现多少次
unordered_map<string, int> mp;
string arr[MAX_N + 5];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        //count方法表示当前这个键在map中出现的次数
        //由于键是唯一的，所以只有0和1
        //0就表示暂时没有这个键
        if (mp.count(arr[i]) == 0) {
            //map中初始化的键值为0
            //所以现在arr[i]这个昵称出现一次，对他进行加1
            mp[arr[i]] += 1;
            //第一出现输出OK 
            cout << "OK" << endl;
            //继续
            continue;
        }
        //到了这里说明该昵称已经用过了
        //那么输出这个字符串和他之前出现的次数
        cout << arr[i] << mp[arr[i]] << endl;
        //出现次数+1
        mp[arr[i]] += 1;
    }
    return 0;
}
