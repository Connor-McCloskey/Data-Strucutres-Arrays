//not sure what goes here, but something
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "SetFunctions.h"

//Function definitions
//Function for validating ints
void ValidateIntsTest(string stringTest, vector <int> &testVector)
{
	int testing;
	stringstream ss;
	ss << stringTest;

	while (!ss.eof())
	{
		ss >> testing;
		if (ss.fail())
		{
			cout << "Failure" << endl;
			ss.clear();
		}
		testVector.push_back(testing);
	}
}

//Function for placing validating values into bags
void PlaceinBag(ArrayBag &bag, vector <int> fullVector)
{
	int size = fullVector.size();
	for (int i = 0; i < size; i++)
	{
		bag.add(fullVector[i]);
	}
}