/*
	Author: Jim Stilwell
	Date: 01/06/2016
	IDE: Eclipse Kepler SR2
	Language: C++ (MinGW / http://mingw.org/)
	
	Problem Description
	-------------------
	Scientist have discovered a new plant.
	The fruit of the plant can feed 1 person for a whole week, the plant never dies.
	The Fruit needs 1 week to grow, so each weak you can harvest its fruit.
	Also the plant gives 1 fruit more than the week before.
	To get more plants you need to plant a fruit.
	Now you need to calculate after how many weeks you would have to wait before you can support a group of x people, given y fruits to start with.
	Input
	15 1
	Expected Output
	5
	Actual Output (with details)
	Week: 1   0, Weekly Yield: 0
	Week: 2   1, 0, Weekly Yield: 1
	Week: 3   2, 1, 0, 0, 0, Weekly Yield: 3
	Week: 4   3, 2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, Weekly Yield: 8
	Week: 5   4, 3, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, Weekly Yield: 21
	Number of weeks 5
	Current Weekly Yield 21


	Assumptions:
	All fruit harvested is replanted at the end of each week.
	You have succeeded when you have a week in which you can produce enough food to feed the entire population
	It takes a full week after a plant has been deployed for it to yield fruit

	My Solution:
	This is a modified Fibonacci Sequence
	Create an Array with an initial size of 1
	The array grows by 1 place for each new plant created every week
	Each element of the array stores the number of weeks each plant has existed (fruit yield)

	Challenge:
	Dynamically resize the array each week to hold the number of plants currently growing.

	URL: https://www.reddit.com/r/dailyprogrammer/comments/3twuwf/20151123_challenge_242_easy_funny_plant/

 */

#include <stdlib.h>
#include <iostream>
using namespace std;

int main() {
	// Simulated User Input
	int 	StartingFruit 				= 1;
	int 	NumberOfPeopleToSupport 	= 15;

	// Program variables
	int 	TargetInventory				= NumberOfPeopleToSupport;
	int 	PlantArrayCurrentSize 		= StartingFruit;
	int		OldPlantArraysize			= PlantArrayCurrentSize;
	int* 	PlantArray 					= new int[PlantArrayCurrentSize];  	// allocated on heap
	int 	NumberOfWeeksPassed 		= 0;
	int 	WeeklyYeild 				= StartingFruit;					// Total Fruit produced during any given week

	for(int i=0; i<PlantArrayCurrentSize; i++){								// Initialize the Array;
		PlantArray[i] = 0;
	}

	while (WeeklyYeild < TargetInventory) {									// Check for success

		WeeklyYeild = 0; 													// Re-plant anything in the WeeklyYield

		for(int i=0; i<PlantArrayCurrentSize; i++){
			WeeklyYeild = WeeklyYeild + PlantArray[i];						// Add up all of the seeds produced this week
		}

		NumberOfWeeksPassed++;												// Iterate the week

		OldPlantArraysize = PlantArrayCurrentSize;							// Hold on to the old plant array size so we can use it for bounds checking
		PlantArrayCurrentSize = PlantArrayCurrentSize + WeeklyYeild; 		// Figure out our new plant total (plant all the new fruit)

		int* TempPlantArray = new int[PlantArrayCurrentSize];				// Create a temp array large enough to hold the current plant inventory

		cout << "Week: " << NumberOfWeeksPassed << "   ";

		for(int i=0; i<PlantArrayCurrentSize; i++){							// Copy the values from the old array into the new one and initialize any new elements to 0
			if(i < OldPlantArraysize){
				TempPlantArray[i] = PlantArray[i];
			}
			else {
				TempPlantArray[i] = 0;
			}
			cout << TempPlantArray[i] << ", ";
		}
		cout << "Weekly Yield: " << WeeklyYeild << endl;
        delete [] PlantArray;              									// free old array memory.
        PlantArray = TempPlantArray;                 						// now PlantArray points to new TempPlantArray.

        for(int i=0; i<PlantArrayCurrentSize; i++){
			PlantArray[i]++;												// Increase the fruit yield for each plant in the array by one (Due to one weeks growth)
		}

	}

	delete [] PlantArray;													// free up array memory
	cout << "Number of weeks " << NumberOfWeeksPassed << endl << "Current Weekly Yield " << WeeklyYeild << endl; // Show results
	return 0;
}
