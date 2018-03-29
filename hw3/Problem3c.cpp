#include <iostream>
#include "Problem3c.h"

using namespace std;

int main(){
	numCell<int> num1(4);
	numCell<int> num2(11);
	numCell<string> num3("abcd");
	numCell<string> num4("ef");
	numCell<string> num5("ghijklm");
	
	listClass<int> listInts;
	listClass<string> listStrings;
	
	listInts.write(num1);
	listInts.write(num2);
	listInts.print();
	cout << num1.read() << " * " << num2.read() << " = " << listInts.product() << endl; 
	listStrings.write(num3);
	listStrings.write(num4);
	listStrings.write(num5);
	listStrings.print();
	cout << num3.read() << " * " << num4.read() << " * " << num5.read() <<
		" = " << listStrings.product() << endl; 
	return 0;
}