/*************************************************************************
	> File Name: 5.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 22 Feb 2025 09:27:09 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;


#define MAX_N 100

#define int long long

string arr[MAX_N + 5];
//b数组表示i，j之间形成回文串的最小长度
int b[MAX_N + 5][MAX_N + 5];
//表示i和j连通
queue<pair<int, int>> q;
int n;

void init() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    //将b数组的每一个数字初始化为一个很大的数
    memset(b, 63, sizeof(b));
    //最初的回文串
    for (int i = 0; i < n; i++) {
        b[i][i] = 0;
        q.push({i, i});
        for (int j = 0; arr[i][j]; j++) {
            if (i == j || arr[i][j] == '-') continue;
            b[i][j] = 1;
            q.push({i, j});
        }
    }
    return ;
}

void bfs() {
    while (!q.empty()) {
        //l和r表示当前回文串的左右端点
        int l = q.front().first;
        int r = q.front().second;
        q.pop();
        for (int i = 0; i < n; i++) {
            //判断i和l是否连通
            if (arr[i][l] == '-') continue;
            for (int j = 0; j < n; j++) {
                //如果i和l节点能连通，r和j节点能连通,并且他们边上的字母相同
                //说明能接在lr这个回文串上
                if (arr[i][l] != arr[r][j]) continue;
                //因为能接上了，那么取ij最小回文串长度
                //对于lr新增两个字符，所以对比lr的最小回文串长度+2
                if (b[i][j] < b[l][r] + 2) continue;
                //取最小回文串长度
                b[i][j] = b[l][r] + 2;
                //将ij作为回文串的左右端点进行入队
                q.push({i, j});
            }
        }
    }
    return ;
}

void output() {
    int flag;
    memset(&flag, 63, sizeof(flag));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            j && cout << " ";
            if (b[i][j] < flag) {
                cout << b[i][j];
            } else {
                cout << -1;
            }
        }
        cout << endl;
    }
    return ;
}


int32_t main() {
    //思想：
    //将找到一个回文串，然后取判断他左右两端的端点
    //由于这个图是有向的
    //所以左端点判断入度，也就是指向他的节点
    //右端点判断出度，也就是他指向的节点
    //然后分别取判断他们的出度和入度的边上的字符相同
    //如果相同，那么就可以接在当前这个字符串上

    //初始化
    init();
    //广搜
    bfs();
    //输出
    output();
    return 0;
}
