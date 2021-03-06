//Ceramic Tile -- calculate number of tiles necessary to tile a given size rectangular room
//CSIS 112-002
//<Sources if necessary>


//Include statements
#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

//Global declarations: Constants and type definitions only -- NO variables

//Function prototypes
int CalculateTiles(int roomNum, int tileSize);
void CalculateBoxes(int totalTiles);
int InputFilter(bool& error, int filterOption = 1);
void BoolValChange(bool& var, bool value);

int main()
{
	//In cout statement below substitute your name and lab number
	cout << "Cody Moore -- Lab Number 1" << endl << endl;

	//Variable declarations
	int roomNum;
	int tileSize;
	int numTiles;

	//Program logic

	cout << "Welcome to the Ceramic Tile Planner. Please enter an integer. Decimals will be ignored and truncated."<< endl << endl;

	cout << "Please enter the amount of rooms you would like to tile." << endl;
	roomNum = InputFilter();

	cout << "Please enter the size of a tile in square inches." << endl;
	tileSize = InputFilter();


	numTiles = CalculateTiles(roomNum, tileSize);

	CalculateBoxes(numTiles);


	//Closing program statements
	system("pause");
	return 0;
}

//Function definitions

int CalculateTiles(int roomNum, int tileSize)
{
	double ftx;
	double fty;
	double inx;
	double iny;
	double magnitudex;
	double magnitudey;
	int tilesX;
	int tilesY;
	int amountTiles = 0;
	int totalAmountTiles = 0;
	bool inputError = false;


	for (int i = 0; i < roomNum; i++)
	{
		tilesX = 0;
		tilesY = 0;

		cout << "Please enter the length of the room in feet and inches, separated by a space. (Example: 17 4)" << endl; // gets x size of room
		
		do
		{
			ftx = InputFilter(inputError);
			inx = InputFilter(inputError, 2);
		} while (inputError);
		

		cout << "Please enter the width of the room in feet and inches, separated by a space. (Example: 17 4)" << endl; // gets y size of room
		
		do
		{
			ftx = InputFilter(inputError);
			inx = InputFilter(inputError, 2);
		} while (inputError);

		magnitudex = (ftx * 12) + inx; // gets total size in inches for x and y
		magnitudey = (fty * 12) + iny;

		tilesX = ceil(magnitudex / tileSize); // must be ceil otherwise rounding will be off
		tilesY = ceil(magnitudey / tileSize);

		amountTiles = tilesX * tilesY; // finds total amount of tiles for the entire room, given the amount of tiles necessary for the x-axis and y-axis
		totalAmountTiles += amountTiles;

		cout << "Amount of tiles needed: " << amountTiles << endl;
	}
	cout << "Total amount of tiles needed: " << totalAmountTiles << endl;
	return totalAmountTiles;
}

void CalculateBoxes(int totalTiles)
{
	int numBoxes = ceil(totalTiles / 20.0);
	cout << "The needed number of boxes is " << numBoxes <<  endl;
	cout << "There are " << (numBoxes * 20) - totalTiles << " wasted tiles." << endl;
}

int InputFilter(bool& error, int filterOption)
{
	double placeholder;
	string filterStatement = "Your input must be a positive integer"; // custom error message
	cin >> placeholder;
	error = false;

	// experiment getline to check whole given value for acceptability, remove double and float issue

	switch (filterOption) // allows additional hints to user for input by allowing additional error statements or additional errors  
	{
	case 1:
		while (cin.fail() || placeholder < 0)
		{
			cout << filterStatement << "." << endl; // period allows additional statements to be added to error message before final printing
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> placeholder;
			error = true;
		}
		break;
	case 2:
		filterStatement = "Your inches must be a positive integer and less than 12"; // this prompts the user to use a number less than 12, although this function does not cause the logic to loop if it is less than 12
		while (cin.fail() || placeholder < 0 || placeholder >= 12)
		{
			cout << filterStatement << "." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> placeholder;
			error = true;
		}
		break;
	default:
		break;
	}

	return floor(placeholder);
}

void BoolValChange(bool & var, bool value)
{
	var = value;
}


