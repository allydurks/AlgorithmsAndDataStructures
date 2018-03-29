//Allison Durkan, EC330 HW2
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
/* This function accepts an integer array, nums, 
containing len > 0 positive integers, and returns
the sum closest to 330 that was found by adding up
to three integers in the array (where each element
in the array can only be included once in the sum).

Ex: [nums] contains [10 100 200 2] and len ==4, the 
function returns 310=200+100+10
[nums] contains [10 100 230 2] and len ==4, the function
returns 330=100+230 */

//instead of brute-forcing the solution, we are going to sort the array
//by using a quicksort we will use O(n log n)
//which will benefit us in the end
int partition(int* input, int p, int r)
{	//used to return the partition of the part of
	//the array that is going to be sorted
    int pivot = input[r];

    while ( p < r ) {
        while ( input[p] < pivot )
            p++;
        while ( input[r] > pivot )
            r--;
        if ( input[p] == input[r] )
            p++;
        else if ( p < r ){
            int tmp = input[p];
            input[p] = input[r];
            input[r] = tmp;
        }
    }
    return r;
}

//the quicksort recursive function, calls the partition function
// sorts the array in ascending order
void quicksort(int* input, int p, int r)
{	//p is left most index, r is rightmost index
    if ( p < r ){
        int j = partition(input, p, r);        
        quicksort(input, p, j-1);
        quicksort(input, j+1, r);
    }
}

int Sum(int *nums, int len){
	//it will place 3 ptrs at various points in the array
	//gradually the pointers will move closer to each other
	//this implementation is in O(n^2) time
	int sum = 0; // used when sum of numbers is calculated
	int checkSum = 0; // to be used in len = 2 case
	int compare = 0; // used to find the element(s) closest to 330
	int j,k; // used to iterate through array
	if (len == 1) // there is only one element, therefore it is the closest to 330
		return nums[0];
	if (len == 2){
		if (nums[0] == 330 || nums[1] == 330)
			return 330;
		checkSum = nums[0] + nums[1];
		if (fabs(checkSum - 330) < fabs(compare - 330)) // if the sum of the two is between 0 and 330
			compare = checkSum;
		if (fabs(nums[0] - 330) < fabs(compare - 330)) // if the index is closer to 330 than the sum
			compare = nums[0];
		if (fabs(nums[1] - 330) < fabs(compare - 330)) // if the index of this one is closer to 330 than the other
			compare = nums[1];
		return compare; // this is to check and see which value is closest to 330
	}	

	quicksort(nums,0,len-1); // for all len > 2, we will need to sort before running this algorithm
	for (int i = 0; i < len - 2; i++ ){
		j = i + 1; // the index after id
		k = len - 1; // the end of the array 
		while (k > j){ //this can only happen while the rightmost pointer is greater than the middle
			//cout << "compare: " << compare << endl;
			sum = nums[i] + nums[j] + nums[k];
			//cout << "numbers: " << nums[i] << " "
				//<< nums[j] << " " << nums[k] << endl;
			//checkSum = nums[j] + nums[k];
			//cout << "SUM: " << sum << endl;
			if (sum == 330 || nums[k] == 330 || nums[j] == 330 || nums[i] == 330){
				return 330;
			}
			else if (sum > 330){ // when the sum is too big, decrement the end pointer
				k--;			// this works because the array is sorted in ascending order
			}
			else if (sum < 330){ // sum is too little, increment the middle pointer
				j++;
			}
			
			if (fabs(sum - 330) < fabs(compare - 330)){ // checks to see if this sum is closer to 330 than previous
				compare = sum;
			}
			if( fabs( (nums[j] + nums[k]) - 330) < fabs(compare - 330)){
				compare = nums[j] + nums[k]; // checks to see if sum of the two is closer to 330
			}
			if( fabs( (nums[i] + nums[k]) - 330) < fabs(compare - 330)){
				compare = nums[i] + nums[k]; // checks all the sets of two
			}
			if( fabs( (nums[j] + nums[i]) - 330) < fabs(compare - 330)){
				compare = nums[j] + nums[i]; // checks all sets of two
			}
		}
	}
	return compare; // will return the sum closest to 330
}

/*
I used i,j,k like pointer to the different indexes of the array,
with i on the left, j on the next element and k on the end
and I moved them depending on whether the sum was too close or too far
from the target value of 330
*/