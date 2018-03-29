#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <fstream>
#include <math.h>
using namespace std;

long BinarySum(string filename){
	/*receives filename as input for txt with binary numbers 
	(up to 32 bits each), separated by carriage returns, 
	returns decimal sum of all the 
	numbers*/
	long sum = 0; //initialize to zero to avoid garbage
	string binaryNumber;
	long decimalNumber;
	ifstream myFile(filename.c_str());
	if (myFile.fail()){
		cout << "An error occurred with the input file." << endl;
	}
	else { 
		while (!myFile.eof()){
			getline(myFile, binaryNumber, '\n');
			decimalNumber = 0;
			long size = binaryNumber.size();
			for (int i = 0; i < size; i++){
				if (binaryNumber.c_str()[i] == '1')
					decimalNumber = decimalNumber + pow(2, size-i-1);
			}
			sum += decimalNumber;
			//cout << sum << endl;
		}
	}
	/*	add = (char*)toAdd.c_str();
		length = 32 - strlen(add);
		memmove(add + length, add, strlen(add));//moves string chars to the end
		for (int i = 0; i < length; i++)
			add[i] = '0';
		cout << add;
		cout << endl ;	free(add);*/
		
		/*for(i = 0; i < 8 ; i++){
   sum[i] = ((a[i] ^ b[i]) ^ c); // c is carry
   c = ((a[i] & b[i]) | (a[i] & c)) | (b[i] & c); 
}
			myFile >> toAdd; //reads in line from file
			cout << toAdd << endl;
			//add 0's to front of string to make it 32 bit
			arrayInputs[counter] = (char*)toAdd.c_str();
			*length = 32 - toAdd.length();
			for (int i = 0; i < length; i++)
				arrayInputs[counter][i] = '0';
			counter++;*/
	myFile.close();
	return sum;
	//return strtol(sum, &p, 2);// this will need to be in decimal
	//return dec sum of all numbers
}

int main(int argc, char* argv[]){
//had to change function prototype to comply with c++ 11
	//cout << argv[1] << endl;
	cout << BinarySum(argv[1]) << endl; 
	//should receive a file name from command line
	//call BinarySum function with provided file name
	//print out the output returned
	return 0;
}	
