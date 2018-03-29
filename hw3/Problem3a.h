#ifndef PROB3A_H
#define PROB3A_H
#include <stdio.h>
using namespace std;
template <class T>
class numCell {

private:
	T storedValue;
	
public:
	numCell();			//default constructor
	numCell(T initialValue);	//constructor for template type T
	T read();                               // return the content of the cell
    void write(T value);                    // write value to cell
    numCell& swap (numCell& otherCell);       // swap the contents of this cell with another
    numCell& operator=(numCell& otherCell);   // copy constructor
    numCell& operator+(numCell& otherCell);   // return the sum of this and otherCell
};

/*templatized version of the numcell class that can store/add either an int or a string
compute 46 + 2 + 15
"abra" + "cadabra"
"temp" + "lates " + "are " + "us" + "eful" */

template <class T>
numCell<T>::numCell(){
    storedValue = 0;
}

template<>
numCell<string>::numCell(){
	storedValue = "";
}

template <class T>
numCell<T>::numCell(T initialValue){
    storedValue = initialValue;
}

template <class T>
T numCell<T>::read(){
    return storedValue;
}

template <class T>
void numCell<T>::write(T value){
    storedValue = value;
}

template <class T>
numCell<T>& numCell<T>::swap(numCell<T>& otherCell){
    T tmp = this->read();
    write(otherCell.read());
    otherCell.write(tmp);
    return *this;
}

template <class T>
numCell<T>& numCell<T>::operator=(numCell<T>& otherCell){
    write(otherCell.read());
    return *this;
}

template <class T>
numCell<T>& numCell<T>::operator+(numCell<T>& otherCell){
    
    numCell *result = new numCell();
    result->write(this->read() + otherCell.read());
    return *result;
}


#endif
