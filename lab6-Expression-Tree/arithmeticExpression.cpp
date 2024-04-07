#include "arithmeticExpression.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

arithmeticExpression::arithmeticExpression(const string &userInput) {
    root = 0;       //initializes empty tree
    infixExpression = userInput;       //set infixExpression to parameter value passed in
}

void arithmeticExpression::destroyTree(TreeNode* curr) {        //destructor helper function
    if (curr != nullptr) {
        destroyTree(curr->left);
        destroyTree(curr->right);
        delete curr;
    }
}

arithmeticExpression::~arithmeticExpression() {
    destroyTree(root);
}

void arithmeticExpression::buildTree() {
    string postfixExpress = this->infix_to_postfix(); //converts the infixExpression to its equivalent postfix string
    stack<TreeNode*> s;     //stack for tree
    char letter = 'a';      //key for the first node
    char c;
    for (unsigned i = 0; i < postfixExpress.size(); ++i) {
        c = postfixExpress.at(i);
        if (!isalpha(c)) {       //if node is an operator
            TreeNode* symbol = new TreeNode(c, letter + i);     //assign root node to root data field, the key for the first node is 'a', 'b' for the second node and so on.
            symbol->left = s.top();     //pop twice and set as children
            s.pop();
            symbol->right = s.top();
            s.pop();
            s.push(symbol);     //push new tree onto stack
            root = symbol;
        }
        else {      //if operand
            s.push(new TreeNode(c, letter + i));    //if node is alpha
        }
    } 


}

void arithmeticExpression::infix(TreeNode* exprTree) {      //infix helper function
    if (exprTree) {
        if (priority(exprTree->data)) {     //check for operator
            cout << "(";
            infix(exprTree->right);
            cout << exprTree->data;
            infix(exprTree->left);
            cout << ")";
            }
        else {
            infix(exprTree->left);      //inorder traversal of the tree if operand
            cout << exprTree->data;
            infix(exprTree->right);
        }            
    }
}

void arithmeticExpression::infix() {
    if (root == 0) {
        return;
    }
    else {
        infix(root);
    }
}

void arithmeticExpression::prefix(TreeNode* exprTree) {     //prefix helper function
    if (exprTree) {
        cout << exprTree->data;         //preorder traversal of the tree
        prefix(exprTree->right);
        prefix(exprTree->left);
    }
    else {
        return;
    }
}

void arithmeticExpression::prefix() {
    if (root == 0) {
        return;
    }
    else {
        prefix(root);
    }
}

void arithmeticExpression::postfix(TreeNode* exprTree) {    //postfix helper function
    if (exprTree) {
        postfix(exprTree->right);       //postorder traversal of the tree
        postfix(exprTree->left);
        cout << exprTree->data;
    }
    else {
        return;
    }
}

void arithmeticExpression::postfix() {
    if (root == 0) {
        return;
    }
    else {
        postfix(root);
    }

}

void arithmeticExpression::visualizeTree(ofstream &outFS, TreeNode *currNode) {      //visualizeTree hepler function for generating the dotty file
    if (!currNode) {
        return;
    }

    outFS << currNode->key << "[ label = " << "\"" << " ]" << endl;
    if (currNode->left) {
        outFS << currNode->key << "->" << currNode->left->key << "[ label = " << "\"" << currNode->left->data << "\"" << " ]" << endl;
        visualizeTree(outFS, currNode->left);
    } 
    if (currNode->right) {
        outFS << currNode->key << "->" << currNode->right->key << "[ label = " << "\"" << currNode->left->data << "\"" << " ]" << endl;
        visualizeTree(outFS, currNode->right);
    }
    outFS << endl;
}

void arithmeticExpression::visualizeTree(const string &outputFilename) {
    ofstream outFS(outputFilename.c_str());

    if (!outFS.is_open()) {
        cout << "Error opening " << outputFilename<<endl;
        return;
    }
    outFS << "digraph G {" << endl;
    visualizeTree(outFS,root);
    outFS << "}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}

int arithmeticExpression::priority(char op) {       //returns an integer according to the priority of the given operator
    int priority = 0;
    if (op == '(') {        
        priority =  3;
    }
    else if (op == '*' || op == '/') {
        priority = 2;
    }
    else if (op == '+' || op == '-') {
        priority = 1;
    }
    return priority;
}

string arithmeticExpression::infix_to_postfix() {       //returns the postfix notation equivalent to the given infix expression
    stack<char> s;
    ostringstream oss;
    char c;
    for(unsigned i = 0; i< infixExpression.size();++i){
        c = infixExpression.at(i);
        if(c == ' '){
            continue;
        }
        if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')'){ //c is an operator
            if( c == '('){
                s.push(c);
            }
            else if(c == ')'){
                while(s.top() != '('){
                    oss << s.top();
                    s.pop();
                }
                s.pop();
            }
            else{
                while(!s.empty() && priority(c) <= priority(s.top())){
                    if(s.top() == '('){
                        break;
                    }
                    oss << s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
        else{ //c is an operand
            oss << c;
        }
    }
    while(!s.empty()){
        oss << s.top();
        s.pop();
    }
    return oss.str();
}