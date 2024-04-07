#include "IntList.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    IntList test;
    cout << "push 1 to front of list" << endl;
    test.push_front(1);
    cout << test << endl;
    
    cout << "push 2 to front of list" << endl;
    test.push_front(2);
    cout << test << endl;
    
    cout << "push 3 to back of list" << endl;
    test.push_back(3);
    cout << test << endl;
    
    cout << "push 4 to back of list" << endl;
    test.push_back(4);
    cout << test << endl;
    
    cout << "push 5 to back of list." << endl;
    test.push_back(5);
    cout << test << endl;
    
    cout << "pop back." << endl;
    test.pop_back();
    cout << test << endl;
    
    cout << "pop front." << endl;
    test.pop_front();
    cout << test << endl;
    
    cout << "Print list in reverse." << endl;
    test.printReverse();
    cout << endl;
    
    cout << "Is list is empty?: ";
    if (!test.empty())
    {
        cout << "No" << endl;
        
    }
    else 
    {
        cout << "Yes" << endl;
    }
    
    cout << "Empty the list." << endl;
    for (int i = 0; i < 3; ++i)
    {
        test.pop_back();
    }
    
    cout << "Empty now?:" << endl;
    if (!test.empty())
    {
        cout << "No" << endl;
        
    }
    else 
    {
        cout << "Yes" << endl;
    }


    test.pop_back();

    return 0;
}