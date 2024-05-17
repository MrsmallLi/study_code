/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 04 May 2024 10:49:49 AM CST
 ************************************************************************/

#include <iostream>
#include <pai.h>
using namespace std;

void usage(int max_no = 7) {
    if (max_no >= 1)printf("1 : DAN\n");
    if (max_no >= 2)printf("2 : DUIZI\n");
    if (max_no >= 3)printf("3 : SHUNZI\n");
    if (max_no >= 4)printf("4 : SANDAI\n");
    if (max_no >= 5)printf("5 : ZHADAN\n");
    if (max_no >= 6)printf("6 : WANGZHA\n");
    if (max_no >= 7)printf("7 : PASS\n");
    printf("input : ");
    return ;
}

PAI *read_pai(int max_no = 7) {
    PAI *ret;
    int no, x, len;
    while (1) {
        usage(max_no);
        cin >> no;
        if (no <= max_no) {
            switch (no) {
                case 1: {
                    cin >> x;
                    ret = new DAN(x);
                } break;
                case 2: {
                    cin >> x;
                    ret = new DUIZI(x);
                } break;
                case 3: {
                    cin >> x >> len;
                    ret = new SHUNZI(x, len);
                } break;
                case 4: {
                    cin >> x;
                    PAI *dai = read_pai(2);
                    ret = new SANDAI(x, dai);
                } break;
                case 5: {
                    cin >> x;
                    ret = new ZHADAN(x);
                } break;
                case 6: {
                    ret = new WANGZHA();
                } break;
                case 7: {
                    ret = new PASS();
                } break;
            }
            break;
        }
    }
    return ret;
}

#define MAX_N 18
int main() {
    int arr[MAX_N + 5] = {0};
    int x;

    while (cin >> x) {
        if (x == 0) break;
        arr[x] += 1;
    }

    PAI *pai = read_pai(); 
    vector<PAI *> temp = PAI::getLegalPai(arr, pai);
    //vector<PAI *> temp = PAI::getPai(arr);
    
    for (auto x : temp) {
        x->output() << endl;
    }
    return 0;
}
