#include <pai.h>
#include <tree.h>

Node::Node() : p(new PASS()), win(0) {}
Node::Node(PAI *p, int win = 0) : p(p), win(win) {}

static bool checkEmtpy(int *arr) {
    for (int i = 3; i < MAX_N; i++) {
        if (arr[i]) return false;
    }
    return true;
}

void getTree(Node *root, int *a, int *b) {
    if (checkEmtpy(b)) {
        root->win = 0;
        return ;
    }
    vector<PAI *> temp = PAI::getLegalPai(a, root->p);
    int must_win = 0;
    for (int i = 0; i < temp.size(); i++) {
        Node *node = new Node(temp[i], 0);
        temp[i]->take(a);
        getTree(node, b, a);
        temp[i]->back(a);
        root->child.push_back(node);
        if (node->win == 0) {
            root->win = 1;
            break;
        }
    }
    return ;
}
