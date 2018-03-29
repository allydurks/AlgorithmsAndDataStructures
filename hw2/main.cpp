#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <limits>

using namespace std;

int Sum(int *nums, int len);

int main(){
	int test1[] = {40, 100, 200, 2}; //len=4
	int test2[] = { 102, 30, 235, 253, 330, 12}; //len=6
					// { 12, 30, 102, 235, 253, 330}
	int test3[] = {10, 14, 15, 300, 2}; //len == 5
	int test4[] = {25, 75, 23, 78, 92, 10, 42, 12};
	int test5[] = {440, 200, 25, 715, 30, 17, 75}; //len ==7
	int test6[] = {20};
	int test7[] = {320, 250, 50, 80, 331, 400, 25};
	int test8[] = {10, 60};
	int test9[] = {0, 0 , 0, 0};
	int test10[] = {330, 20};
	int test11[] = {670, 330};
		//len ==10
	cout << "test 1: " << Sum(test1, 4) << endl;
		//should be 340
	cout << "test 2: " << Sum(test2, 6) << endl;
		//should be 330
	cout << "test 3: " << Sum(test3, 5) << endl;
		//should be 329
	cout << "test 4: " << Sum(test4, 8) << endl;
		//should be 245
	cout << "test 5: " << Sum(test5, 7) << endl;
		//should be 305
	cout << "test 6: " << Sum(test6, 1) << endl;
		// should be 20
	cout << "test 7: " << Sum(test7, 7) << endl;
		// should be 330
	cout << "test 8: " << Sum(test8, 2) << endl;
		// should be 70
	cout << "test 9: " << Sum(test9, 4) << endl;
		// should be 0
	cout << "test 10: " << Sum(test10,2) << endl;
		//should be 330
	cout << "test 11: " << Sum(test11,2) << endl;
		// should be 30
	return 0;
}	
