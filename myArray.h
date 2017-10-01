/*
 * Bryce Tant
 * October 1st, 5:30pm
 * Function: Create and test an Array object using previous code
 * Input: None
 * Output: Arrays
*/

#include <iostream>
using namespace std;
 
class myArray
{
	public: 
		myArray();
		myArray(int, double); 
		myArray(double*, int);
		~myArray();
		
		void insert(int, double);
		void remove(int);
		double get(int index);
		void clear();
		int find(double);
		void print();
		void init();
        int getSize();
        void setArr(int index, double value);
        bool equals(myArray &rhs);
		
		
	private: 
		int size; 
		double *arr;
        void setSize(int value);
};
