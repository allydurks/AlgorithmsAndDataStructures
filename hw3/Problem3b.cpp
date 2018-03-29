#include <iostream>
#include "Problem3b.h"

using namespace std;

int main(){
	numCell<int> num1(12);
	numCell<int> num2(22);
	numCell<string> num3("al");
	numCell<string> num4("go");
	numCell<string> num5("rith");
	numCell<string> num6("ms");
	
	listClass<int> listInts;
	listClass<string> listStrings;
	
	listInts.write(num1);
	listInts.write(num2);
	listInts.print();
	cout << "The sum of the integers is: " << listInts.sum() << endl;
	
	listStrings.write(num3);
	listStrings.write(num4);
	listStrings.write(num5);
	listStrings.write(num6);
	listStrings.print();
	cout << "The sum of the strings is: " << listStrings.sum() << endl;
		
	
	return 0;
}