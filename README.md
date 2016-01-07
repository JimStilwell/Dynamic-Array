# Dynamic-Array
Fun little program to predict inventory growth over time. A modified Fibonacci sequence using a dynamically growing array.

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
