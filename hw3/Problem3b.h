#ifndef PROB3B_H
#define PROB3B_H
#include <stdio.h>
#include <typeinfo>
#include <algorithm>
#include <list>
#include "Problem3a.h"
using namespace std;
//class numCell;
//this class implements 3 methods using lists
template <class T>
class listClass{
	private:
		T storedValue;
		
	public:
		listClass();
		listClass(numCell<T> initialValue);
		
		list <numCell<T> > listClass_ptrs;
		typename list<numCell<T> >::iterator it;
		
		void write(numCell<T> writeValue);
		T sum();
		void print();
		
		T total;
};

template <class T>
listClass<T>::listClass(){
	total = 0;
	storedValue = 0;
}

template <>
listClass<string>::listClass(){
	total = "";
	storedValue = "";
}

template <class T>
listClass<T>::listClass(numCell<T> initialValue){
	//this puts the values constructed into a list
	this->listClass_ptrs.push_back(initialValue);
	total = NULL;
}

template <class T>
void listClass<T>::write(numCell<T> writeValue){
	//this method write the value passed to the cell
	listClass_ptrs.push_back(writeValue);
}

template <class T>
void listClass<T>::print(){
	//prints out the content of the list	
	cout << "Contents of the list: \n";
	for (it = listClass_ptrs.begin(); it != listClass_ptrs.end(); ++it){
		cout << it->read() << " ";
	}
	cout << endl;
}

template <class T>
T listClass<T>::sum(){
	//computes and returns sum of all list elements
	for (it = listClass_ptrs.begin(); it != listClass_ptrs.end(); ++it){
		total += it->read(); //adds each cell to the total
	}
	return total;
}

#endif