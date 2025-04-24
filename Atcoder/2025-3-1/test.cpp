/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 01 Mar 2025 09:36:08 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    // 初始化，1-based 索引
    vector<int> pigeon_pos(N + 1), actual(N + 1);
    for (int i = 1; i <= N; i++) {
        pigeon_pos[i] = i;
        actual[i] = i;
    }

    vector<int> output;  // 存储类型3操作的输出结果

    for (int i = 0; i < Q; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int a, b;
            cin >> a >> b;
            // 将鸽子 a 移动到鸟巢 b
            pigeon_pos[a] = b;
        } else if (op == 2) {
            int a, b;
            cin >> a >> b;
            // 交换鸟巢 a 与鸟巢 b 中的所有鸽子
            swap(actual[a], actual[b]);
        } else if (op == 3) {
            int a;
            cin >> a;
            // 鸽子 a 报告其当前所在的鸟巢号 actual[pigeon_pos[a]]
            int res = actual[pigeon_pos[a]];
            output.push_back(res);
        }
    }

    // 输出所有类型3操作的结果
    for (int res : output) {
        cout << res << "\n";
    }
    return 0;
}
