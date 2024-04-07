#ifndef STACK_H
#define STACK_H
#define MAX_SIZE 20     //Declare constant in stack.h called MAX_SIZE and set to 20
#include <stdexcept>

using namespace std;

template<class T>       //template stack class
class stack {
    public:
        stack() {   //constructs an empty stack
            size = 0;
        }

        void push(T val) {     //inserts a new element (val) of type T
            if (size == MAX_SIZE) {  //if array is full, throw an overflow_error exception
                throw overflow_error("Called push on full stack.");
            }
            else {
                data[size] = val;
                ++size;
            }
        }

        void pop() {         //removes the last element from data
            if (size == 0) {    //if array is empty, throw an out_of_range exception
                throw out_of_range("Called pop on empty stack.");
            }
            else {
                --size;
            }
        }

        void pop_two() {     //removes the last two elements from data
            if (size == 1) {    //if array is empty or is of size 1, throw an out_of_range exception for each case respectively
                throw out_of_range("Called pop_two on a stack of size 1.");
            }
            else if (size == 0) {
                throw out_of_range("Called pop_two on empty stack");
            }
            else {
                size = size - 2;
            }
        }

        T top() {       //returns the top element of stack (last inserted element)
            if (size == 0) {    //If stack is empty, throw an underflow_error exception with error message "Called top on empty stack.".
                throw underflow_error("Called top on empty stack.");
            }
            else {              
                return data[size - 1];
            }
        }

        bool empty() {     // returns true if the stack is empty otherwise it returns false
            return (size == 0);
        }

    private:
        T data[MAX_SIZE];   //array with maximum size of 20
        int size;           //stores the current number of elements in the stack

};

#endif















