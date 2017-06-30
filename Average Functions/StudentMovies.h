// File StudentMovies.h -- StudentMovies class specification file
#ifndef StudentMovies_h
#define StudentMovies_h
#include <iostream>
#include <iomanip>
using namespace std;
class StudentMovies
{
private:
	int *ptrvalues;
	int *studentIndexes;
	int arraySize;
	int median;
	int mean;
	int *mode;
	int modeCount;
	bool thereIsAMode;
public:
	StudentMovies(); //default constructor
	~StudentMovies(); // destructor
	void fillArray();
	void display();
	void sortArray();
	int getMedian();
	int average(int one, int two);
	int *getMode();
	int getMean();
	void calculateMedian();
	void calculateMode();
	void calculateMean();
	void updateMode(int typeOfUpdate);

};
#endif
