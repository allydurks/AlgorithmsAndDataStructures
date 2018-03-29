/*templatized version of the numcell class that can store/add either an int or a string
compute 46 + 2 + 15
"abra" + "cadabra"
"temp" + "lates " + "are " + "us" + "eful" */

#include "Problem3a.h"


numCell::numCell(){
    storedValue = 0;
}

numCell::numCell(T initialValue){
    storedValue = initialValue;
}


T numCell::read(){
    return storedValue;
}

void numCell::write(T value){
    storedValue = value;
}

numCell& numCell::swap(numCell& otherCell){
    T tmp = this->read();
    write(otherCell.read());
    otherCell.write(tmp);
    return *this;
}

numCell& numCell::operator=(numCell& otherCell){
    write(otherCell.read());
    return *this;
}

numCell& numCell::operator+(numCell& otherCell){
    
    numCell *result = new numCell();
    result->write(this->read() + otherCell.read());
    return *result;
}
