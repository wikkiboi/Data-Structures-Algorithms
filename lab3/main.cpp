#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

template<typename T>
unsigned min_index(const vector<T> &vals, unsigned index) {     //returns the index of the min value starting from "index" to the end of the "vector"
    unsigned min = index;

    for (unsigned i = index; i < vals.size(); ++i) {    //checks all values starting from index in vector to find the min value
        if (vals.at(i) < vals.at(min)) {
            min = i;
        }
    }

    return min;
}

template<typename T>
void selection_sort(vector<T> &vals) {      //finds the index of the min value in the unsorted portion of the vector and sorts them
    unsigned min;

    for (unsigned i = 0; i < vals.size(); ++i) {    
        min = min_index(vals, i);           //takes the min value and swaps its index location with the current index being selection-sorted in the loop 
        T swap = vals.at(min);              
        vals.at(min) = vals.at(i);          //if the values are the same, it will assign the exact same value to that index again.
        vals.at(i) = swap;
    }
}

template<typename T>
T getElement(vector<T> vals, int index) {   //if an out of range exception occurs, it will catch it and indicate this exception
    try {
        return (vals.at(index));
    }
    catch (const std::out_of_range& excpt) {        //if the error occurs when attempting to return the value at the given index, then it will output the following
        cout << "out of range exception occured" << endl;
    }

    return 0;
}

vector<char> createVector(){
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    for(int i = 0; i < vecSize; i++)
    {
        vals.push_back(c);
        c++;
    }
    return vals;
}

int main(){

    //Part B
     srand(time(0));
     vector<char> vals = createVector();
     char curChar;
     int index;
     int numOfRuns = 10;
     while(--numOfRuns >= 0){
         cout << "Enter a number: " << endl;
         cin >> index;
         curChar = getElement(vals,index);
         cout << "Element located at " << index << ": is " << curChar << endl;
    }
    return 0;


    //Test harness

    //Int Vector
    cout << "Testing selection_sort for vector of integers" << endl;
    vector<int> testInt;
    testInt.push_back(20);
    testInt.push_back(-17);
    testInt.push_back(1);
    testInt.push_back(0);
    testInt.push_back(0);
    testInt.push_back(6);
    testInt.push_back(6);
    testInt.push_back(13);
    testInt.push_back(-9);
    testInt.push_back(-8);
    testInt.push_back(-4);
    testInt.push_back(17);
    testInt.push_back(-1);

    selection_sort(testInt);

    cout << "Expected: -17 -9 -8 -4 -1 0 0 4 6 6 13 17 20 " << endl;
    cout << "Actual: ";
    for (unsigned i = 0; i < testInt.size(); ++i) {
        cout << testInt.at(i) << " ";
    } 
    cout << endl << endl;

    //Double Vector
    cout << "Testing selection_sort for vector of doubles" << endl;
    vector<double> testDouble;
    testDouble.push_back(13.38);
    testDouble.push_back(13.34);
    testDouble.push_back(10.30);
    testDouble.push_back(19.40);
    testDouble.push_back(14.63);
    testDouble.push_back(13.32);
    testDouble.push_back(9.53);
    testDouble.push_back(13.70);
    testDouble.push_back(11.32);
    testDouble.push_back(11.13);
    testDouble.push_back(2.09);
    testDouble.push_back(10.30);
    testDouble.push_back(-6.00);
    testDouble.push_back(-9.96);
    testDouble.push_back(-8.16);
    testDouble.push_back(-8.27);
    testDouble.push_back(-7.74);
    testDouble.push_back(-5.55);
    testDouble.push_back(-19.70);
    testDouble.push_back(-7.03);

    selection_sort(testDouble);

    cout << "Expected: -19.70 -9.96 -8.27 -8.16 -7.74 -7.03 -6.00 -5.55 2.09 9.53 10.30 11.13 11.32 13.34 13.38 13.70 14.63 19.40 " << endl;
    cout << "Actual: ";

    for (unsigned i = 0; i < testDouble.size(); ++i) {
        cout << testDouble.at(i) << " ";
    }

    cout << endl << endl;

    //String Vector
    cout << "Testing selection_sort for vector of strings" << endl;
    vector<string> testString;

    testString.push_back("zjb");
    testString.push_back("y");
    testString.push_back("xv");
    testString.push_back("sd");
    testString.push_back("aop");
    testString.push_back("f");
    testString.push_back("pmj");
    testString.push_back("s");
    testString.push_back("vnybo");
    testString.push_back("ny");
    testString.push_back("ky");
    testString.push_back("ouz");
    testString.push_back("jrd");

    selection_sort(testString);

    cout << "Expected: aop f jrd ky ny ouz pmj s sd vnybo xv y zjb " << endl;
    cout << "Actual: ";

    for (unsigned i = 0; i < testString.size(); ++i) {
        cout << testString.at(i) << " ";
    }

    cout << endl;


}