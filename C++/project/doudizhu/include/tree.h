/*************************************************************************
	> File Name: tree.h
	> Author: 
	> Mail: 
	> Created Time: Sat 04 May 2024 03:52:28 PM CST
 ************************************************************************/

#ifndef _TREE_H
#define _TREE_H
#include <vector>
#include <pai.h>
class Node {
public :
    Node();
    Node(PAI *, int);
    int win;
    PAI *p; 
    vector<Node *> child;
};

void getTree(Node *root, int *, int *);

#endif
