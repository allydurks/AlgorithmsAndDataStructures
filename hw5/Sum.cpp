#include <iostream>
#include <vector>
#include "Sum.h"

using namespace std;

sumClass::sumClass(){

}

// The following method computes the sum of the integers from low to high inclusive
long long sumClass::Sum(int low, int high){
    vector<int> numbers;
    /*    
    // Step 1: build a vector of integers
    for (int ii=low; ii<=high; ii++)
    {
        numbers.insert(numbers.begin(), ii);
    }*/
        
    // Step 2: add all elements in the vector
    int result = 0;
    int start = low;
    vector<int>::iterator iter;
    iter = numbers.begin();
        
    //for (iter=numbers.begin(); iter!=numbers.end(); iter++)
    do{
	//numbers.insert(numbers.begin(), start);
	//if (start <= high){
		numbers.push_back(start); //push_back improves the running time because it has constant complexity
        	result += start;
		start++;
		iter++;
	//}
	//cout << "anything " << *iter << ' '; 	
    }while (start <= high);
        
    // Step 3: return the result
    return result;
}
