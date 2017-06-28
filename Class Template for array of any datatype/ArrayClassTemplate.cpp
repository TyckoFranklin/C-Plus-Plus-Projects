// main.cpp file
/* Programmer: Tycko Franklin

    Purpose: Create class template for a dynamic array of any data type
	Date modified: 06/3/17

   Compiler used:  MS VSE VC++ 2012 */
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <ctime>
using namespace std;

template <class T>
class DynamicArray
{
private:
	T *myArray;
	int size;
public:
	DynamicArray(int size);
	~DynamicArray();
	void fill();
	void sortMyArray();
	void display();

};
	
    //constructor. allocate myArray based on size.
	template <class T>	
	DynamicArray<T>::DynamicArray(int size)
	{
		this->size = size;
		myArray = new T[size];
	}

	//deconstructor. Deallocate myArray.
	template <class T>	
	DynamicArray<T>::~DynamicArray()
	{
		delete [] myArray;
	}

	// fill the array up based on size
	template <class T>	
	void DynamicArray<T>::fill()
	{
		for(int i =0; i < size; i++)
		{
			// added the .5 in there to show up when T is a double.
			myArray[i] = i + i + .5;
		}
		//make it a random array
		random_shuffle(myArray, (myArray + size));
	}
	

	//sort myArray
	template <class T>	
	void DynamicArray<T>::sortMyArray()
	{
		//let's sort this array out!!!
		sort(myArray, (myArray + size));
	}


	//display the contents of myArray
	template <class T>	
	void DynamicArray<T>::display()
	{
		for(int i =0; i < size; i++)
		{
			if (i == 0)
				cout << myArray[i];
			else cout << ", " << myArray[i];
		}
		cout << endl;
	}





int main()
{
	// set the srand seed to the current time.
	srand(time(0));

	//do the double data type for DynamicArray
	DynamicArray<double> daDouble(10);
	daDouble.fill();
	cout << "Double Array: " << endl;
	daDouble.display();
	daDouble.sortMyArray();
	cout << "Double Array sorted: " << endl;
	daDouble.display();

	//do the int data type for DynamicArray
	DynamicArray<int> daInt(10);
	daInt.fill();
	cout << "Int Array: " << endl;
	daInt.display();
	daInt.sortMyArray();
	cout << "Int Array sorted: " << endl;
	daInt.display();



	system("pause");
	return 0;
}