// Reid_Nolan_HW3_[Countdown].cpp : Defines the entry point for the console application.
//Program for removing leading and trailing zeroes from and reverse an iteger input by the user.
//BONUS: Program also drops the sign of the integer input by the user and sorts those integers by ascending value.

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

//define Number class
class Number
{
private:
	int userInput = 0;	
	int reversedNumber = 0;	
	int arrayLength = 0;
	string sortedNumber = "";
public:	
	void input();
	void reverse();
	void sort();
	void output();
};

//function to prompt for and validate input
void Number::input()
{
	//declare and initialize boolean for while loop
	bool intGood = false;

	//repeat prompt until user input is good
	while (!intGood)
	{
		//prompt for and read in input
		cout << "Enter an integer: ";
		cin >> userInput;

		//handle input failure
		if (cin.fail())
		{
			cout << "Error! Input failure. Try again." << endl << endl;
			cin.clear();
			cin.ignore(512, '\n');
		}
		//terminate if userInput is 0
		else if (userInput == 0)
		{
			cout << "exiting program...";
			exit(1);
		}
		//set loop to true if input is non-zero
		else if (userInput < 0 || userInput > 0)
		{
			intGood = true;
		}
		else
		{
			//no else needed
		}
	}
}

//function to reverse integer
void Number::reverse()
{
	//declare and initialize local variables
	const int divisor = 10;
	int newNumber = 0;
	int dividedNumber = 0;

	//save integer into new variable
	newNumber = userInput;

	//perform calculation on any non-zero integer
	while (newNumber < 0 || newNumber > 0)
	{
		dividedNumber = newNumber % divisor;
		reversedNumber = (reversedNumber * divisor) + dividedNumber;
		newNumber /= divisor;
	}
}

//function to implement selection-sort on reversed integer
void Number::sort()
{
	//drop sign if necessary
	if (reversedNumber < 0)
	{
		sortedNumber = to_string(reversedNumber * -1);
	}
	else if (reversedNumber > 0)
	{
		sortedNumber = to_string(reversedNumber);
	}
	else
	{
		//no else needed
	}

	//get length of string to use in for loop located below
	arrayLength = sortedNumber.length();

	//selection-sort loop
	for (int startIndex = 0; startIndex < arrayLength - 1; startIndex++)
	{
		//declare and initialoze local variables
		int smallestIndex = 0;
		int temp = 0;

		//save first to smallest
		smallestIndex = startIndex;

		for (int currentIndex = startIndex + 1; currentIndex < arrayLength; currentIndex++)
		{
			if (sortedNumber[currentIndex] < sortedNumber[smallestIndex])
			{
				smallestIndex = currentIndex;				
			}
			else
			{
				//no else needed
			}			
		}
		temp = sortedNumber[smallestIndex];
		sortedNumber[smallestIndex] = sortedNumber[startIndex];
		sortedNumber[startIndex] = temp;
	}
}

//function to display output
void Number::output()
{
	//display output from reverse and sort
	cout << "Reverse of " << userInput << " is " << reversedNumber << endl;
	cout << "Sorted in ascending order: ";
	
	//loop through string elements and display
	for (int i = 0; i < arrayLength; i++)
	{
		cout << sortedNumber[i];
	}
	cout << endl;
}

//main function
int main()
{	
	//display program header
	cout << "Reid_Nolan_HW3_[Countdown]" << endl;
	cout << "Countdown 5-4-3-2-1-0!" << endl;
	cout << " -enter 0 to exit" << endl << endl;
	
	//loop for indefinite use (option to terminate located in input funtion)
	while (true)
	{
		//declare instance of class
		Number countdown;
		
		//call member functions on instance of class
		countdown.input();
		countdown.reverse();
		countdown.sort();
		countdown.output();
		cout << endl;
	}
}