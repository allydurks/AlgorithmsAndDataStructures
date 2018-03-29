#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <map>
using namespace std;
//collaborator Hannah Hebert 
//my name is Allison Durkan
string Analyze(string str, int size){
	//if str has < size char, returns str
	
	if (str.size() < size){
		return str;
	}
	//receives string and integer 0<size<10
	//returns most frequent occurring sequence of size characters in str
	//ties broken in favor of the first occurring sequence in the string
	map<string, int> analyzeMap;
	vector<string> substrings;
	
	for (int i = 0; i < str.size(); i++){
		substrings.push_back(str.substr(i, size));
	}
	//this goes through the map and counts how many times each substring occurs

	string mostFreq = "";
	int maxFreq = 0;
	
	for (vector<string>::iterator it = substrings.begin(); it != substrings.end(); it++){
		int count = ++analyzeMap[*it];
		if (count > maxFreq){
			maxFreq = count;
			mostFreq = *it;
		}
	}
	
	return mostFreq;
	/*	for (int i = 0; i < substrings.size(); i++){
		map<string, int>::iterator findSub = analyzeMap.find(substrings[i]);
		
		if (findSub != analyzeMap.end())
			analyzeMap[substrings[i]] += 1; //increments the number of occurences by 1
		else
			analyzeMap.insert(pair<string, int>(substrings[i],1));//if it doesn't find a match for the substring it adds it to the map
	}*/

	
	/*map<string, int>::iterator outerCompare = analyzeMap.begin();
	for (map<string, int>::iterator innerCompare = analyzeMap.begin(); innerCompare != analyzeMap.end(); innerCompare++){
		if (innerCompare->second > outerCompare->second) //compares the value in the second column
			innerCompare = outerCompare;
		cout << "inside" << endl;
	}
	
	return outerCompare->first;*/
}

int main(int argc, char* argv[]){
//had to change function prototype to comply with c++ 11
	int inputSize = atoi(argv[2]);
	string inputString = argv[1];
	cout << Analyze(inputString, inputSize) << endl;
	//receive a string and an integer from the command line
	//call Analyze function with two inputs
	//print out the output returned
	return 0;
	
}

