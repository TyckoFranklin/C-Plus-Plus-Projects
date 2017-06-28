//file Travel.cpp - Travel class implementation file

#include "Travel.h"
using namespace std;


//Travel::Travel
// Constructor opens the file from the fileName and reads in the data.
Travel::Travel(string fileName)
{
	try
	{
	fileI.open(fileName, ios::in);
	if(!fileI)
		throw Travel::FileNotOpened();
	int peopleCount;
	fileI >> peopleCount;
	string temp;
	for(int i = 0; i < peopleCount; i++)
	{
		//get past the subscript on that line....
		fileI >> temp;
		//get the name and add it to vector
		fileI >> temp;
		people.push_back(temp);
	}
	//get the favorite destinations
	int tempCount;
	for(int i = 0; i < peopleCount; i++)
	{
		fileI >> temp;
		fileI >> tempCount;
		vector<string> tempDestinations;
		for(int k = 0; k < tempCount; k++)
		{
			//get the destination and add it to tempDestinations
			fileI >> temp;
			tempDestinations.push_back(temp);
		}
		//add all the temp destinations to that person's destination list
		destinations.push_back(tempDestinations);
	}


	fileI.close();
	}
	catch(Travel::FileNotOpened)
	{
		cout << "Error opening file\nExiting now..." << endl;
		system("pause");
		exit(0);
	}
}

//Travel::printNames
//Prints all the stored names

void Travel::printNames()
{
	for(int i = 0; i < people.size(); i++)
		cout << people[i] << endl;
}


//Travel::getDestinations
// returns a string vector of the destinations of a person. If that person is not found, and empty vector is returned
vector<string> Travel::getDestinations(string person)
{
	try
	{
	int found = -1;
	for(int i = 0; i < people.size(); i++)
		if (people[i] == person)
			found = i;
	if(found == -1)
		throw Travel::PersonNotFound();
	else return destinations[found];
	}
	catch(Travel::PersonNotFound)
	{
		vector<string> empty;
		return empty;
	}
}