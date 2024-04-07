#include "Node.h"
#include <string>

using namespace std;

Node::Node() {
    count = 0;
    data = "";
    left = 0;
    right = 0;
    parent = 0;
}

Node::Node(string _data) {
    count = 1;
    data = _data;
    left = 0;
    right = 0;
    parent = 0;
}