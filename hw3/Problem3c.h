#ifndef PROB3B_H
#define PROB3B_H
#include <stdio.h>
#include <typeinfo>
#include <algorithm>
#include <vector>
#include <list>
#include "Problem3a.h"
using namespace std;
//class numCell;
//this class implements 3 methods using lists
template <class T>
class listClass{
		
	public:
		listClass();
		listClass(numCell<T> initialValue);
		
		list <numCell<T> > listClass_ptrs;
		typename list<numCell<T> >::iterator it;
		
		void write(numCell<T> writeValue);
		T sum();
		void print();
		T product();
		T total;
		T prod;
};

template <class T>
listClass<T>::listClass(){
	total = 0;
	prod = 1; // so we won't immediately have 0 product
}

template <>
listClass<string>::listClass(){
	total = "";
	prod = "";
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

template <class T>
T listClass<T>::product(){
	for (it = listClass_ptrs.begin(); it != listClass_ptrs.end(); ++it){
		prod *= it->read(); //keeps multiplying the product
	}
	return prod;
}

template<>
string listClass <string> :: product() {
	vector <string> addLetters;
	vector <int> sortSize;
	vector <int> size;
	vector <string> finalProd;
	int min, max;
	string total, temp;
	
	for (it = listClass_ptrs.begin(); it != listClass_ptrs.end(); ++it){
		size.push_back((it->read()).size()); //
		sortSize.push_back((it->read()).size());
		addLetters.push_back((it->read()));
	}
	
	sort(sortSize.begin(), sortSize.end()); //sorts the elements in ascending order
	min = sortSize[0]; // the minimum value in the sorted array is at index 0
	max = sortSize[sortSize.size() - 1]; // max value in sorted array is at last index, so size - 1
	
	for (int i = 0; i < max; i++){
		for (int j = 0; j <= addLetters.size(); j++){
			if (i > (size[j] - 1))
				continue;
			temp = addLetters[j].at(i); //.at returns a reference to character at position i in the string
			finalProd.push_back(temp);
		}
	}
	
	for (int k = 0; k < finalProd.size(); k++){
		prod += finalProd[k]; // the prod now is a string of the letters from the finalProd vector
	}
	
	return prod;
}

#endif