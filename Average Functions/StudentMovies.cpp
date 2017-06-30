// File StudentMovies.cpp -- StudentMovies class function implementation file



#include "StudentMovies.h"
using namespace std;
/***********************************************************************************
*								StudentMovies::StudentMovies					   *
* 																				   *
* default constructor. Get the size of the array from user.	Initialize variables   *
************************************************************************************/
StudentMovies::StudentMovies()
{
	// get value count
	cout << "Please enter the number of Students: ";
	cin >> arraySize;
	// allocate an array for the values based on the amount of values to enter
	ptrvalues = new int[arraySize];
	studentIndexes = new int[arraySize];
	mode = new int[1];
	modeCount = 1;
	thereIsAMode = false;

}

/***********************************************************************************
*								StudentMovies::~StudentMovies					   *
* 																				   *
* deconstructor. de-allocate pointers											   *
************************************************************************************/
StudentMovies::~StudentMovies()
{
	delete ptrvalues;
	ptrvalues = 0;
	delete studentIndexes;
	studentIndexes = 0;
	delete mode;
	mode = 0;
}

/***********************************************************************************
*								StudentMovies::fillArray						   *
* 																				   *
* Get data from user and fill the array with it									   *
************************************************************************************/
void StudentMovies::fillArray()
{
	cout << "How many movies did each student see?" << endl;
	// Fill in all the scores
	for (int i = 0; i < arraySize; i++)
	{
			cout << "How many movies did student " << i << " see? ";
			cin >> *(ptrvalues + i);
			*(studentIndexes + i) = i;		
	}
}

/***********************************************************************************
*								StudentMovies::fillArray						   *
* 																				   *
* Sort the array. Keep original order by using an array of indexes				   *
************************************************************************************/
void StudentMovies::sortArray()
{
	//classic selection sort
	int minIndex, minValue, minIndexValue;
	for (int i = 0; i < (arraySize-1); i++)
	{
		minIndex = i;
		minValue = *(ptrvalues + i);
		minIndexValue = *(studentIndexes + i);
		for(int x = i+1; x < arraySize; x++)
		{

			if(*(ptrvalues + x) < minValue)
			{
				minValue = *(ptrvalues + x);
				minIndexValue = *(studentIndexes + x);
				minIndex = x;
			}
		}
		*(ptrvalues + minIndex) = *(ptrvalues + i);
		*(ptrvalues + i) = minValue;
		*(studentIndexes + minIndex) = *(studentIndexes + i);
		*(studentIndexes + i) =  minIndexValue;
	}
}

/***********************************************************************************
*								StudentMovies::display							   *
* 																				   *
* Display everything that has been calculated									   *
************************************************************************************/

void StudentMovies::display()
{

	// Display the scores
	cout << "Movies each student has seen : \n";
	for (int i = 0; i < arraySize; i++)
	{
		
		cout << "Student " << setw(3) << left << *(studentIndexes + i ) << " has seen " << setw(3) << left << *(ptrvalues +i) << " movies." << endl;
	
	}
	cout << "The Median amount of movies seen is " << median << endl;
	if(thereIsAMode)
	{
		cout << "The Mode amount of movies seen is ";
		for (int i = 0; i < modeCount; i++)
		{
			if(i > 0)
				cout << " and ";
			cout << *(mode + i);
		}
		cout << endl;
	} else 
	{
		cout << "The Mode amount of movies seen is: None, all the values are the same." << endl;
	}
	cout << "The Mean amount of movies seen is " << mean << endl;
}

/***********************************************************************************
*								StudentMovies::average  						   *
* 																				   *
* for use when median is made of two values. Get mean of 2 values				   *
************************************************************************************/

int StudentMovies::average(int one, int two)
{
	return (one + two)/2;

}

/***********************************************************************************
*								StudentMovies::getMedian						   *
* 																				   *
* return median																	   *
************************************************************************************/

int StudentMovies::getMedian()
{
	return median;
}

/***********************************************************************************
*								StudentMovies::calculateMedian					   *
* 																				   *
* Calculate the median. If there are two middle numbers, get the mean of those two *
************************************************************************************/

void StudentMovies::calculateMedian()
{
	//nothing in array, return 0
	if(arraySize == 0)
		{
			median = 0;
			return;
	}
	//only one element in the array, return that element
	if(arraySize == 1)
	{
			median = *ptrvalues;
			return;
	}
	//see if array is even or odd. if even, get the mean of the two medians.
	if(arraySize % 2 == 0)
	{
		median = average(*(ptrvalues + (arraySize/2)-1), *(ptrvalues + (arraySize/2)));
	}
	else
	{
		median = *(ptrvalues + ((arraySize + 1)/2)-1);
	}
}

/***********************************************************************************
*								StudentMovies::getMode							   *
* 																				   *
* return mode																	   *
************************************************************************************/

	int * StudentMovies::getMode()
	{
		return mode;
	}

/***********************************************************************************
*								StudentMovies::getMean							   *
* 																				   *
* return Mean																	   *
************************************************************************************/

	int StudentMovies::getMean()
	{
		return mean;
	}

/***********************************************************************************
*								StudentMovies::calculateMode					   *
* 																				   *
* Calculate the Mode. This function will also find more than one mode when there   *
* is more than one.																   *
************************************************************************************/

	void StudentMovies::calculateMode()
	{
		//get the mode. Go through the loop comparing values, keep the largest number of consecutive numbers.
		int modeSize = 0;
		int currentModeSize = 1;
		*mode = *ptrvalues;
		for (int i = 0; i < arraySize - 1; i++)
			{
				if(*(ptrvalues + i) == *(ptrvalues + i + 1))
				{
					currentModeSize++;
					if(currentModeSize > modeSize)
					{
						//found a more abundant mode, delete the mode array and start anew
						updateMode(0);
						*mode = *(ptrvalues + i);
						modeSize = currentModeSize;
					}
					else if (currentModeSize == modeSize)
					{
						// found another mode that equals the same amount of values as the current mode. 
						// add another element to *mode and then add the current mode as that last element
						updateMode(1);
						*(mode + modeCount - 1) = *(ptrvalues + i);
					}
					
				}
				else
				{
					currentModeSize = 1;
				}
			}
	}

/***********************************************************************************
*								StudentMovies::updateMode						   *
* 																				   *
* Adds 1 element to the Mode array or resizes the mode array back to 1 element	   *
************************************************************************************/

	void StudentMovies::updateMode(int typeOfUpdate)
	{
		thereIsAMode = true;
		// pass in 0 for resizing to 1 element, 1 for increasing the size by 1
		switch(typeOfUpdate)
		{
			case 0:
				{
					//change the modecount to 1 for new array.
					modeCount = 1;
					//free up the allocated memory.
					delete mode;
					mode = new int[modeCount];
					break;
				}
			case 1:
				{
					//create new pointer for array that will contain one more element
					int *tempPtr = new int[modeCount+1];
					//copy old array into new array
					for (int i = 0; i < modeCount; i++)
					{
						*(tempPtr + i) = *(mode + i);
					}
					//free up memory of old array
					delete mode;
					//set old array pointer to the new array
					mode = tempPtr;
					//set the address of the new pointer to 0. Probably doesn't matter.
					// Now if we delete mode it will free up the memory that tempPtr allocated. No memory leak!!
					tempPtr = 0;
					//add one to modeCount to reflect the change of adding an element
					modeCount++;
					break;
				}
		}		

				

	}

/***********************************************************************************
*								StudentMovies::calculateMean					   *
* 																				   *
* Calculate the Mean															   *
************************************************************************************/

	void StudentMovies::calculateMean()
	{
		int total = 0;
		for (int i = 0; i < arraySize; i++)
		{
			total += *(ptrvalues +i);
		}
		mean = total / arraySize;
	}