#include <iostream>
#include <string>
#include "Problem3a.h"

using namespace std;

/* a sum of integers is defined as an arithmetiic sum,
the sum of strings is defined as their concatenation */

int main(int argc, const char * argv[]) {
/*
    numCell<int> num1(15);
    numCell<int> num2;
    cout << "Contents top:\n Cell 1: " << num1.read() << ", Cell 2: " << num2.read() << endl;
    num1.write(12);
    num2.write(3);
    cout << "Contents after write:\n Cell 1: " << num1.read() << ", Cell 2: " << num2.read() << endl;
    
    num1.swap(num2);
    cout << "Contents after swap:\n Cell 1: " << num1.read() << ", Cell 2: " << num2.read() << endl;
    
    num1 = num1 + num2;
    cout << "Contents after adding cell 2 to cell 1:\n Cell 1 : " << num1.read() << ", Cell 2: " << num2.read() << endl;
  */  
	numCell<int> num1(46);
	numCell<int> num2(2);
	numCell<int> num3(15);
	numCell<string> num4("abra");
	numCell<string> num5("cadabra");
	numCell<string> num6("temp");
	numCell<string> num7("lates ");
	numCell<string> num8("are ");
	numCell<string> num9("us");
	numCell<string> num10("eful");
	
	cout << "Contents for 3.a.i: \n Cell 1: " << num1.read() << ", Cell 2: " << num2.read() << ", Cell 3: " 
		<< num3.read() << endl;
	
	cout << "Contents for 3.a.ii: \n Cell 1: " << num4.read() << ", Cell 2: " << num5.read() << endl;
	
	cout << "Contents for 3.a.iii: \n Cell 1: " << num6.read() << ", Cell 2: " << num7.read() << ", Cell 3: " 
		<< num8.read() << ", Cell 4: " << num9.read() << ", Cell 5: " << num10.read() << endl;
	
	num1 = num1 + num2;
	num1 = num1 + num3;
	
	cout << "Contents after adding Cells 2 and 3 to Cell 1 of part i: " << num1.read() << endl;
	
	num4 = num4 + num5;
	
	cout << "Contents after adding Cell 2 to Cell 1 of part ii: " << num4.read() << endl; 
	
	num6 = num6 + num7;
	num6 = num6 + num8;
	num6 = num6 + num9;
	num6 = num6 + num10;
	
	cout << "Contents after adding all Cells to Cell 1 of part iii: " << num6.read() << endl;
	
    return 0;
}
