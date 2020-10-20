/*
NAME: Connor McCloskey
LAST DATE MODIFIED: 02/01/2017
ASSIGNMENT: Data Structures Homework 2
DESCRIPTION: This program demonstrates basic containers
STATUS: COMPLETE
COMMENTS: Should run to assignement specifications
*/

#include "ArrayBag.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "SetFunctions.h"

using namespace std;

int main()
{
	//Variables
	ArrayBag bag1, bag2, resultsBag;
	ifstream inputFile;
	string string1;
	string string2;
	vector <int> numberVectorOne;
	vector <int> numberVectorTwo;

	//Opening the input file
	inputFile.open("setInput.txt");
	if (inputFile.fail())
	{
		cout << "Failure opening file." << endl;
	}

	//Reading in the two string from the file
	while (!inputFile.eof())
	{
		getline(inputFile, string1);
		getline(inputFile, string2);
	}

	//Passing the strings to a function to validate ints
	ValidateIntsTest(string1, numberVectorOne);
	ValidateIntsTest(string2, numberVectorTwo);

	//Placing the validated ints into the bags
	PlaceinBag(bag1, numberVectorOne);
	PlaceinBag(bag2, numberVectorTwo);

	//Adding/subtracting the bags
	resultsBag = bag1 + bag2;

	//Print the bag by converting it to a vector and printing it out
	vector <ItemType> printResults1;
	printResults1 = resultsBag.toVector();
	int size = printResults1.size();

	cout << "Printing addition of bags: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << printResults1[i] << endl;
	}

	 resultsBag = bag1 - bag2;
	//Print the bag by converting it to a vector and printing it out
	 vector <ItemType> printResults2;
	 printResults2 = resultsBag.toVector();
	 int size2 = printResults2.size();
	 cout << "Printing subtraction of bags: " << endl;
	 for (int index = 0; index < size2; index++)
	 {
		 cout << printResults2[index] << endl;
	 }

	return 0;
}