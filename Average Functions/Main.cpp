
/* Programmer: Tycko Franklin

    Purpose: Statistical functions, with added Mode functionality, for movies watched by students.
	Date modified: 04/24/17

   Compiler used:  MS VSE VC++ 2012 */

#include <iostream>
#include "StudentMovies.h"
using namespace std;

int main()
{
	//set up the class, fill the array from user input, sort the array, and run each calculate function.
	StudentMovies sm;
	sm.fillArray();
	sm.sortArray();
	sm.calculateMedian();
	sm.calculateMode();
	sm.calculateMean();

	//display the results
	sm.display();

	system("pause");
	return 0;
}
