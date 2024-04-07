#include "AVLTree.h"

using namespace std;

AVLTree::AVLTree() {
    root = 0;
}

AVLTree::~AVLTree() {
    destroy(root);
}

void AVLTree::destroy(Node *curr) {      //deconstructor
    if (curr != nullptr) {
        destroy(curr->left);
        destroy(curr->right);
        delete curr;
    }
}



void AVLTree::insert(const string &insertString) {
    Node *insertNode = new Node(insertString);
    insert(root, insertNode);
}

void AVLTree::insert(Node *curr, Node *insertNode) {    //insert helper function
    if (root == nullptr) {
        root = insertNode;
        root->parent = 0;
        return;
    }

    curr = root;        //traverse through tree starting from the root

    while (curr) {     //traverse through tree via loop until place to insert is found
        if (insertNode->data == curr->data) {      //add count if duplicate
            curr->count += 1;
            curr = 0;
        }
        else if (insertNode->data < curr->data) {   //traverse left subtree
            if (curr->left == 0) {
                curr->left = insertNode;
                insertNode->parent = curr;
                curr = 0;
            }
            else {
                curr = curr->left;
            }
        }
        else {      //traverse right subtree
            if (curr->right == 0) {
                curr->right = insertNode;
                insertNode->parent = curr;
                curr = 0;
            }
            else {
                curr = curr->right;
            }
        }
    }

    insertNode = insertNode->parent;
    while (insertNode != nullptr) {     //rebalances the tree
        rotate(insertNode);
        insertNode = insertNode->parent;
    }

}

void AVLTree::printBalanceFactors(Node *curr) const {
    if (curr != nullptr) {
        printBalanceFactors(curr->left);
        cout << curr->data << "(" << balanceFactor(curr) << "), ";
        printBalanceFactors(curr->right);
    }
}

void AVLTree::printBalanceFactors() const {
    printBalanceFactors(root);
    cout << endl;
}

int AVLTree::balanceFactor(Node *curr) const {      //return the balance factor of a given node
    int balance_factor = height(curr->left) - height(curr->right);
    return balance_factor;
}

int AVLTree::height(Node *curr) const {     //used to calculate balance factor
    if (curr != nullptr) {
        int nodeHeight = 0;
        height(0, nodeHeight, curr);
        return nodeHeight - 1;
    }
    else {
        return -1;
    }
}

void AVLTree::height(int count, int &nodeHeight, Node *curr) const{     //height helper function
    if (curr != nullptr) {  
        ++count;        //increase count everytime function is called with a valid node
        if (count > nodeHeight) {
            nodeHeight = count;     //height value will be the count at the lowest node
        }

        height(count, nodeHeight, curr->left);      //traverse through tree until invalid node
        height(count, nodeHeight, curr->right);
    }
}

void AVLTree::rotate(Node *curr) {      //fixes four possible imbalance cases and update the parent of the given node
    if (balanceFactor(curr) == 2) { 
        if (balanceFactor(curr->left) == -1) {
            rotateLeft(curr->left);
        }
        rotateRight(curr);
    }
    else if (balanceFactor(curr) == -2) {
        if (balanceFactor(curr->right) == 1) {
            rotateRight(curr->right);
        }
        rotateLeft(curr);
    }
}

void AVLTree::rotateLeft(Node *curr) {      //rotate the subtree to left at the given node and returns the new subroot
    Node *temp = curr->right->left;
    if (curr->parent != nullptr) {
        replaceChild(curr->parent, curr, curr->right);
    }
    else {
        root = curr->right;
        root->parent = 0;
    }
    setChild(curr->right, "left", curr);
    setChild(curr, "right", temp);
}

void AVLTree::rotateRight(Node *curr) {     //rotate the subtree to right at the given node and returns the new subroot
    Node *temp = curr->left->right;
    if (curr->parent != nullptr) {
        replaceChild(curr->parent, curr, curr->left);
    }
    else {
        root = curr->left;
        root->parent = 0;
    }
    setChild(curr->left, "right", curr);
    setChild(curr, "left", temp);
}

void AVLTree::setChild(Node *parent, string whichChild, Node *child) {      //takes parent node and sets a child of choice
    if (whichChild == "left") {
        parent->left = child;
    }
    else {
        parent->right = child;
    }
    if (child != nullptr) {
        child->parent = parent;
    }
}

void AVLTree::replaceChild(Node *parent, Node *currChild, Node *newChild) {     //overwrites current child with new child
    if (parent->left == currChild) {
        setChild(parent, "left", newChild);
    }
    else {
        setChild(parent, "right", newChild);
    }
}

void AVLTree::visualizeTree(const string &outputFilename) {
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error"<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    visualizeTree(outFS,root);
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}

void AVLTree::visualizeTree(ofstream & outFS, Node *n) {
    if(n){
        if(n->left){
            visualizeTree(outFS,n->left);
            outFS<<n->data <<" -> " <<n->left->data<<";"<<endl;    
        }

        if(n->right){
            visualizeTree(outFS,n->right);
            outFS<<n->data <<" -> " <<n->right->data<<";"<<endl;    
        }
    }
}