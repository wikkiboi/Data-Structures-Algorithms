#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>

using namespace std;

class Node {

    friend class AVLTree;

    private:
        Node();
        Node(string);
        int count;
        string data;
        Node *left;
        Node *right;
        Node *parent;
};

#endif