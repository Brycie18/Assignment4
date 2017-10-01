/*
 * Bryce Tant
 * October 1st, 5:30pm
 * Function: Create and test an Array object using previous code
 * Input: None
 * Output: Arrays
*/

#include "myArray.h"
using namespace std;

myArray::myArray() {
    size = 0;
    arr = new double[size];
}

myArray::myArray(int _size, double num) {
    size = _size;
    arr = new double[size];
    for(int i = 0; i < size; i++) { //sets all elements to num
        arr[i] = num;
    }
}

myArray::myArray(double *_arr, int _size) {
    size = _size;
    for(int i = 0; i < size; i++) {
        _arr[i] = arr[i];
    }
    delete [] arr;
    setSize(size);
    arr = _arr;
}

myArray::~myArray() {
    delete [] arr;
}

int myArray::getSize() {
    return size;
}

void myArray::setSize(int value) {
    if (value > 0) {
        size = value;
    }
}

void myArray::setArr(int index, double value) {
    if ((index >= 0) && (index < size)) {
        arr[index] = value;
    } else {
        cout << "NO!" << endl;
    }
}

double myArray::get(int index) {
    if ((index >= 0) && (index < size)) {
        return arr[index];
    } else {
        return arr[size - 1];
    }
}

void myArray::print() {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void myArray::init() { //populates the array
	cout << "Please enter " << size << " elements to populate the array" << 	endl;

	for(int i = 0; i < size; i++) {
	cin >> arr[i];
	}
}

bool myArray::equals(myArray& rhs){
    bool result(true);

    if (getSize() != rhs.getSize()) {
        result = false;
    } else {
        for (int i = 0; i < getSize(); i++) {
            if (get(i) != rhs.get(i)) {
                result = false;
            }
        }
    }
    return result;
}

int myArray::find(double num) { //checks if a specified element is in the array

	for(int i = 0; i < size; i++) {

	if(arr[i] == num)
	return i;

	}
	return -1;

}

void myArray::insert(int index, double num) { //Inserts an element at the specified index

	double *localArray = new double[size + 1];
	if(index >= size + 2) {
	cout << "That index is not within the bounds of 0...n+1" << endl;
	}

	for(int i = 0; i < size; i++) {

	if(i < index)
	localArray[i] = arr[i];

	if(i == index)
	localArray[i] = num;

	if(i > index)
	localArray[i] = arr[i-1];
	
	}
	localArray[size] = size;
	size++;
	delete [] arr;
	arr = localArray;
}

void myArray::remove(int index) { //removes the element at the specified index
	
	if(index > size)
	cout << "Index is not within the bounds of 0..n" << endl;	

	for(int i = index; i < size; i++) {

	arr[i] = arr[i+1];
	
	}
	size--;
}

void myArray::clear() { //deletes all elements 

	delete [] arr;
	size = 0;

}



