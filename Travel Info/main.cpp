// main.cpp file
/* Programmer: Tycko Franklin

    Purpose: create a travel class that keeps track of people's favorite destinations. Display the destinations of a person
	Date modified: 06/11/17

   Compiler used:  MS VSE VC++ 2012 */


#include <iostream>
#include "Travel.h"
using namespace std;

int main()
{
	//set up the file in case it isn't there.....
	fstream fileout;
	fileout.open("travel.txt", ios::out);
	fileout << "4" << endl;
	fileout << "0 Paul" << endl;
	fileout << "2 Peter" << endl;
	fileout << "3 Dan" << endl;
	fileout << "4 David" << endl << endl;
	fileout << "0 3 Chicago Boston Memphis" << endl;
	fileout << "1 1 Boston" << endl;
	fileout << "2 5 Boston Seattle Pasco NewYork Memphis" << endl;
	fileout << "3 0" << endl;
	fileout.close();

	//Okay, now to the challenge!
	Travel ourTravels("travel.txt");
	string temp;

	//display the people in the file
	cout << "People on file:" << endl;
	ourTravels.printNames();
	
	//select person user types in.
	cout << "Please type a name to view that" << endl << "person's favorite destinations: ";
	cin >> temp;
	//get the destinations for that name.
	vector<string> destinations = ourTravels.getDestinations(temp);
	cout << "Destinations for " << temp << " include:";
	//if there are any destinations, display them
	if(destinations.size() > 0)
	{
		for(int i = 0; i < destinations.size(); i++)
			cout << " " << destinations[i];
		cout << endl;
	} //otherwise display this message
	else cout << " No destinations found for " << temp << "...." << endl;

	system("pause");
	return 0;
}