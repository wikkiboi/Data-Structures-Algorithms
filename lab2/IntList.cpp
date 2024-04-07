#include <iostream>
#include "IntList.h"

using namespace std;

IntList::IntList() {        //initializes empty list with dummy head and dummy tail
    dummyHead = nullptr;
    dummyTail = nullptr;
}

IntList::~IntList() {
    while(dummyHead != nullptr) {
        IntNode *temp = dummyHead->next;
        delete dummyHead;
        dummyHead = temp;
    }
}

void IntList::push_front(int data) { //inserts a data value (within a new node) at the front end of the list. O(1) operation.
    IntNode *newNode = new IntNode(data);

    if (dummyHead == nullptr) {     //if list is empty, point dummy head/tail to the new node 
        newNode->next = nullptr;
        newNode->prev = nullptr;
        dummyHead = newNode;
        dummyTail = newNode;
    }
    else {
        newNode->next = dummyHead;  //else, have dummy head point to the new node where dummy head is the next value after the new node's head value
        newNode->prev = nullptr;
        dummyHead->prev = newNode;
        dummyHead = newNode;
    }
}

void IntList::pop_front() {  //removes the node at the front end of the list (the node after the dummy head). O(1) operation.
    if (dummyHead != nullptr) {     //does nothing if list is empty
        IntNode *temp = dummyHead;

        if (dummyHead == dummyTail) {   //if list contains one node, set list to be empty
            dummyHead = nullptr;
            dummyTail = nullptr;
        }
        else {
            dummyHead = dummyHead->next;
            dummyHead->prev = nullptr;
        }

        delete temp;
    }
}

void IntList::push_back(int data) { //inserts a data value (within a new node) at the back end of the list. O(1) operation.
    IntNode *newNode = new IntNode(data);
    newNode->next = nullptr;

    if (dummyHead == nullptr && dummyTail == nullptr) { //when the list is empty, point dummy head/tail to the new node
        dummyHead = newNode;
        dummyTail = newNode;
        newNode->prev = nullptr;
    }
    else {         //point tail to the new last node
    dummyTail->next = newNode;
    newNode->prev = dummyTail;
    dummyTail = newNode;
    }
}

void IntList::pop_back() {  //removes the node at the back end of the list (the node before the dummy tail). O(1) operation
    if (dummyHead != nullptr) {     //does nothing if list is empty
        if (dummyHead == dummyTail) {   //case if list contains a single node
            delete dummyTail;
            dummyTail = nullptr;
            dummyHead = nullptr;
        }
        else {
            IntNode *temp = dummyTail;
            dummyTail = dummyTail->prev;
            dummyTail->next = nullptr;
            delete temp;
        }
    }
}

bool IntList::empty() const {   //returns true if the list does not store any data values (it only has dummy head and dummy tail).
    if (dummyHead == dummyTail && dummyHead == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

ostream & operator<<(ostream &out, const IntList &rhs) { //outputs to the stream all of the integer values within the list on a single line, each separated by a space.
    IntNode *current = rhs.dummyHead;

    while (current != nullptr) {
        out << current->data;
        current = current->next;

        if (current != nullptr) {
            out << " ";
        }
    }

    return out;
}

void IntList::printReverse() const { //prints to a single line all of the int values stored in the list in REVERSE order, each separated by a space.
    if (dummyHead != nullptr) {
        IntNode* current = dummyTail;

        while (current != dummyHead) {
            cout << current->data;
            current = current->prev;
            if (current != dummyHead) {
                cout << " ";
            }
        }

        cout << " " << dummyHead->data;          //print out final value or when list contains a single node
    }
}
