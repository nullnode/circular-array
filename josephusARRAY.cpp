#include "stdafx.h"
#include <iostream>
using namespace std;

int arraySize = 10; // holds the size of our array for processing

// Precondition: we have to make sure our people array and our index variables are both initialized
// Postcondition: we output the remaining members of our array based on our size variable
// This function helps us keep track of the array in order to make sure we're eliminating the correct index.
void Print(int people[], int size)
{
	for (int i = 0; i < size; i++) // size is simply our arraySize int we passed in, so it's an accurate number of how big our array is
	{
		cout << people[i] << " "; // output of the value at each index
	}
	cout << endl;
}

// Precondition: people array and index must be initialized
// Postcondition: our array is "collapsed" after an elimination and we output the value eliminated, the index it was located at, and the remaining survivors by calling the print function.
// In order to remain within the bounds of our array, we have add 1 to our index and iterate through arraySize, then use a temporary variable to shift each element down.
// After we "collapse" the array by shifting each element, we decrement our arraySize variable and output the results. 
// IMPORTANT: In order to output the correct result, we output index + 1 because we started our array values at 1 but array indices begin at 0.
void Collapse(int people[], int index)
{
	int indexTemp; // used to help us shift the elements down the array
	for (int i = index + 1; i < arraySize; i++) // starting at index + 1 so we correctly eliminate index, then iterating through our arraySize variable
	{
		indexTemp = i - 1; // since we added 1 in the for loop to begin at the proper location, we now have to decrement i by 1 and store it inside our temp variable
		people[indexTemp] = people[i]; // we "crunch" or "collapse" our array by setting the value at indexTemp to be the value at i, the math is easy to visualize if you think of the array like a circle
	}

	arraySize--; // decrementing our arraySize after the collapse
	cout << "index: " << index << " was killed " << " Remaining survivors:  "; // displays the value we eliminated and the index it was located in
	Print(people, arraySize); // tossing in our freshly altered people array and arraySize values to be printed out
}

// Precondition: our people array and starting index variables must be initialized, we also need to either pass in a variable to be used as a killswitch or hardcode a number in the argument when calling this function
// Postcondition: we find the 5th element in our array, send the array and index to be processed for collapsing as if it were a circle, then recurse for as long as our arraySize is greater than 1
// Modulus is used to find our element to eliminate, then we call our collapse method to get rid of it and shift the elements, then we recurse until the size of the array is 1.
void Josephus(int people[], int &index, int kill_switch)
{
	index += kill_switch;
	index = index % arraySize; // locating which element to eliminate; our first run will be 5 % 10 which gives us 5. 
	Collapse(people, index); // calling our collapse function and telling it which index to "crunch"
	if (arraySize > 1) // since we want 1 survivor, our base case will be determining whether or not our array size is greater than 1
		Josephus(people, index, kill_switch); // each recurse will eliminate an element down to 1 final survivor
}

int main(int argc, char *argv)
{
	int people[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; // this array will be treated as circular and will hold our "players"
	int num = 0; // int for holding the index of the array that we start the game at

	Josephus(people, num, 5); // we pass in our array, our starting index, and a hardcoded value of 5 which will be used as our Nth player to eliminate.
	cout << "10 people in total, eliminating each 5th person. Survivor is: " << people[0] << endl; // after eliminating each 5th index, our array has collapsed into 1 index left, which is our survivor
    return 0;
}

