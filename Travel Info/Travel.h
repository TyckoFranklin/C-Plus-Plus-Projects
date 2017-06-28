//file Travel.h - Travel class declaration file
#ifndef Travel_h
#define Travel_h
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
using namespace std;
class Travel
{
private:
	vector<string> people;
	vector<vector<string>> destinations;
	fstream fileI;
	class PersonNotFound{};
	class FileNotOpened{};
public:
	Travel(string fileName);
	void printNames();
	vector<string> getDestinations(string person); 
};


#endif

