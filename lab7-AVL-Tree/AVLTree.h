#ifndef __AVLTREE_H
#define __AVLTREE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Node.h"

using namespace std;

class AVLTree {
    private:
        Node *root;
    
    public:
        AVLTree();
        ~AVLTree();
        void insert(const string &);
        int balanceFactor(Node *) const;
        void printBalanceFactors() const;
        void visualizeTree(const string &);

    private:        //additional function declarations
        void destroy(Node *);
        void insert(Node *, Node *);
        void printBalanceFactors(Node *) const;
        int height(Node *) const;
        void height(int, int &, Node *) const;
        void rotate(Node *);
        void rotateLeft(Node *);
        void rotateRight(Node *);
        void setChild(Node *, string, Node *);
        void replaceChild(Node *, Node *, Node *);
        void visualizeTree(ofstream &, Node *);
};

#endif