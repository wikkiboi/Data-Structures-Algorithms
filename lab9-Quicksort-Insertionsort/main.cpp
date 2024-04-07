#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

const int NUMBERS_SIZE = 50000;

int genRandInt(int low, int high) {
   return low + rand() % (high - low + 1);
}

void fillArrays(int arr1[], int arr2[],int arr3[]){ //generate 3 test arrays for sort functions
    for(int i = 0; i < NUMBERS_SIZE; ++i){
        arr1[i] = genRandInt(0,NUMBERS_SIZE);
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }
}

void Quicksort_midpoint(int numbers[NUMBERS_SIZE], int i, int k) {
    if (k == i + 1) {   //if array consists of only i and k
        if (numbers[i] > numbers[k]) {
            int temp;       //sort/swap i and k
            temp = numbers[i];
            numbers[i] = numbers[k];
            numbers[k] = temp;
        }
        return;
    }
    if (i >= k) {
        return;
    }

    int pivot = numbers[i + (k - i) / 2];       //pivot is the midpoint element
    int l = i - 1;
    int r = k + 1;

    while (l <= r) {    //quicksort
        do {
            ++l;    //find size of left side of pivot
        } while (numbers[l] < pivot && l <= r);
        do {
            --r;    //find size of right side of pivot
        } while (numbers[r] > pivot && l <= r);

        if (l <= r) {   //sort
            int temp;       //swap l and r
            temp = numbers[l];
            numbers[l] = numbers[r];
            numbers[r] = temp;
        }
    }
    
    Quicksort_midpoint(numbers, i, r);      //partition is done recursively on each side of the pivot
    Quicksort_midpoint(numbers, r + 1, k);
}

void Quicksort_medianOfThree(int numbers[NUMBERS_SIZE], int i, int k) {
    if (k == i + 1) {
        if (numbers[i] > numbers[k]) {
            int temp;
            temp = numbers[i];
            numbers[i] = numbers[k];
            numbers[k] = temp;
        }
        return;
    }
    if (i >= k) {
        return;
    }

    int mid = numbers[i + (k - i) / 2];
    int pivot;  //pivot is the median of the leftmost, midpoint, and rightmost value

    if (numbers[i] < numbers[mid] && numbers[mid] < numbers[k]) {   //check which of the three values is the median
        pivot = mid;
    }
    else if (numbers[i] < numbers[mid] && numbers[i] > numbers[k]) {
        pivot = i;
    }
    else {
        pivot = k;
    }

    int l = i - 1;
    int r = k + 1;

    while (l <= r) {    //quicksort
        do {
            ++l;
        } while (numbers[l] < pivot && l <= r);
        do {
            --r;
        } while(numbers[r] > pivot && l <= r);

        if (l <= r) {
            int temp;
            temp = numbers[l];
            numbers[l] = numbers[r];
            numbers[r] = temp;
        }
    }

    Quicksort_midpoint(numbers, i, r);
    Quicksort_midpoint(numbers, r + 1, k);    
}

void InsertionSort(int numbers[NUMBERS_SIZE], int numbersSize) {
    int i;
    int j;
    int key;
    int count = 0;

    for (j = 1; j < NUMBERS_SIZE; ++j) {      //loop through array to sort
        key = numbers[j];
        i = j - 1;
        while (i >= 0 && numbers[i] > key) {    //check if the current value in the array is not sorted, i.e. is less than the value before it. 
            numbers[i+1] = numbers[i];  //move the value up one position in the array
            --i;        //move backwards in the array
            ++count;
        }       //Loop until the beginning of array is reached or current value is greater than the value before it

        numbers[i + 1] = key;       //insert key into correct and sorted position
    }
}



int main() {

int arr1[NUMBERS_SIZE];  //Quicksort_midpoint array
int arr2[NUMBERS_SIZE]; //Quicksort_medianOfThree array
int arr3[NUMBERS_SIZE]; //InsertionSort array
fillArrays(arr1, arr2, arr3);

const int CLOCKS_PER_MS = CLOCKS_PER_SEC / 1000; //clock per milliseconds

clock_t Start1 = clock();
Quicksort_midpoint(arr1, 0, NUMBERS_SIZE - 1); //call quicksort_midpoint function 
clock_t End1 = clock();
int elapsedTime1 = (End1 - Start1) / CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.

clock_t Start2 = clock();
Quicksort_medianOfThree(arr2, 0, NUMBERS_SIZE); //call quicksort_medianofthree function 
clock_t End2 = clock();
int elapsedTime2 = (End2 - Start2) / CLOCKS_PER_MS;

clock_t Start3 = clock();
InsertionSort(arr3, NUMBERS_SIZE); //call insertionsort function 
clock_t End3 = clock();
int elapsedTime3 = (End3 - Start3) / CLOCKS_PER_MS;

cout << "Quicksort_midpoint algorithm runtime: " << elapsedTime1 << endl;
cout << "Quicksort_medianOfThree algorithm runtime: " << elapsedTime2 << endl;
cout << "InsertionSort algorithm runtime: " << elapsedTime3 << endl;
}