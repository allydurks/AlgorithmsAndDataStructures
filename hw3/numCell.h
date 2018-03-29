#ifndef numCELL_H
#define numCELL_H

#include <stdio.h>

/* A class for storing and manipulating integers */
class numCell{

private:
    int storedValue;
    //string storedString;
    
public:
    numCell();                                // constructor 
    numCell(int initialValue);                // constructor for int type
    //numCell(string initialString);		//constructor for string type
    int read();                               // return the content of the cell
    void write(int value);                    // write value to cell
    numCell& swap (numCell& otherCell);       // swap the contents of this cell with another
    numCell& operator=(numCell& otherCell);   // copy constructor
    numCell& operator+(numCell& otherCell);   // return the sum of this and otherCell
};

#endif /* numCell_h */
