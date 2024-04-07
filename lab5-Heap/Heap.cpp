#include "Heap.h"

using namespace std;

Heap::Heap() {
	numItems = 0;
}

void Heap::enqueue(PrintJob* job) {
	if(numItems < MAX_HEAP_SIZE) {      //does nothing if max heap size is already reached
		arr[numItems] = job;        //inserts PrintJob into end of array
		
        int index = numItems;
        while(index >= 1 && arr[index]->getPriority() > arr[(index - 2) / 2]->getPriority()) {     //sorts new element until PrintJob priority matches
            swap(arr[index], arr[(index - 1) / 2]);     //swap PrintJob with next highest priority starting from bottom
            index = (index - 1) / 2;
	    }
        ++numItems;
    }
}

void Heap::dequeue() {      //Removes the node with highest priority from the heap. 
    if (numItems == 0) {    //does nothing if array is empty
        return;
    }
    if (numItems == 1) {    //removes the only element in array
        --numItems;
    }
    else if (arr[1]->getPriority() < arr[numItems - 1]->getPriority() && arr[2]->getPriority() < arr[numItems - 1]->getPriority()) {    //checks if first 3 elements are in order of priority
        arr[0] = arr[numItems - 1];       
        --numItems;
    }
    else {
        trickleDown(0);
        --numItems;
    }
    return;
}

PrintJob* Heap::highest() {     //Returns the node with highest priority (root)
	if (numItems == 0) {
        return nullptr;
    }
    else {
        return arr[0];
    }
}

void Heap::print() {        //Prints the PrintJob with highest priority in the following format: Priority: priority, Job Number: jobNum, Number of Pages: numPages
	if (numItems > 0) {
		cout << "Priority: " << arr[0]->getPriority() << ", Job Number: " << arr[0]->getJobNumber() << ", Number of Pages: " << arr[0]->getPages() << endl;	
	}
	else {
		cout << "The heap is empty." << endl;
	}
}

void Heap::trickleDown(int index) {
    if (((2 * index + 1) < numItems) && ((2 * index + 2) < numItems)) {     //check if there are 2 children 
        if (arr[2 * index + 1]->getPriority() > arr[2 * index + 2]->getPriority()) {        //left child is greater than the right
        arr[index] = arr[2 * index + 1];
        trickleDown(2 * index + 1);

        }
        else {         //right child is greater than the left
            arr[index] = arr[2 * index + 2];
            trickleDown(2 * index + 2);
        }
    }
    else if (((2 * index + 1) < numItems)) {        //case for only one child
        arr[index] = arr[2 * index + 1];
    }
return;
}