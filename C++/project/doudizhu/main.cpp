/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 04 May 2024 04:14:10 PM CST
 ************************************************************************/

#include <iostream>
#include <tree.h>
#include <stack>
#include <pai.h>
using namespace std;

int a[MAX_N + 5] = {0};
int b[MAX_N + 5] = {0};

void read(FILE *fin, int *arr) {
    int x;
    while (fscanf(fin, "%d", &x) != EOF) {
        if (x == 0) break;
        arr[x] += 1;
    }
    return ;
}

void read_data() {
    FILE *fin = fopen("input.txt", "r");
    read(fin, a);
    read(fin, b);
    fclose(fin);
    return ;
}


void output_solution(Node *root, int *a, int *b) {
    stack<Node *> s;
    s.push(root);
    while (!s.empty()) {
        printf("%s : ", s.size() % 2 ? "-->" : "   ");PAI::output_arr(a);
        printf("%s : ", s.size() % 2 ? "   " : "-->");PAI::output_arr(b);
        Node *node = s.top();
        int no;
        do {
            printf("[%3d] : back\n", -1);
            for (int i = 0; i < node->child.size(); i++) {
                printf("[%3d] : [%s]", i, node->child[i]->win ? "" : "win");
                node->child[i]->p->output() << endl;
            }
            cout << "input : " << endl;
            cin >> no;
            if (no >= -1 || no < node->child.size()) break;
        } while(1);
        if (no == -1) {
            s.pop();
            node->p->back(s.size() % 2 ? a : b);
        }
        else {
            node->child[no]->p->take(s.size() % 2 ? a : b);
            s.push(node->child[no]);
        }
    }
    return ;
}

int main() {
    read_data();
    Node *root = new Node();
    getTree(root, a, b);
    output_solution(root, a, b);
    return 0;
}
