//Ceramic Tile -- brief statement as to the file’s purpose
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
int InputFilter(int filterOption = 1);

int main()
{
	//In cout statement below substitute your name and lab number
	cout << "Cody Moore -- Lab Number 1" << endl << endl;

	//Variable declarations
	int roomNum;
	int tileSize;
	int numTiles;

	//Program logic

	cout << "Welcome to the Ceramic Tile Planner. Please enter an integer. Decimals will be ignored."<< endl << endl;

	cout << "Please enter the amount of rooms you would like to tile." << endl;
	roomNum = InputFilter();

	cout << "Please enter the size of tiles in square inches." << endl;
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



	for (int i = 0; i < roomNum; i++)
	{
		tilesX = 0;
		tilesY = 0;

		cout << "Please enter the length of the room in feet and inches, separated by a space. (Example: 17 4)" << endl; // gets x size of room
		
		ftx = InputFilter();
		inx = InputFilter(2);

		cout << "Please enter the width of the room in feet and inches, separated by a space. (Example: 17 4)" << endl; // gets y size of room
		
		fty = InputFilter();
		iny = InputFilter(2);

		magnitudex = (ftx * 12) + inx; // gets total size in inches for x and y
		magnitudey = (fty * 12) + iny;

		while (tilesX * tileSize < magnitudex) // finds amount of tiles needed for room by adding one and checking total covered area until amount of tiles * tilesize exceeds magnitude
		{
			tilesX++;
		}
		while (tilesY * tileSize < magnitudey)
		{
			tilesY++;
		}
		amountTiles = tilesX * tilesY; // finds total amount of tiles for the entire room, given the amount of tiles necessary for the x-axis and y-axis
		totalAmountTiles += amountTiles;

		cout << "Amount of tiles needed: " << amountTiles << endl;
	}
	cout << "Total amount of tiles need: " << totalAmountTiles << endl;
	return totalAmountTiles;
}

void CalculateBoxes(int totalTiles)
{
	int numBoxes = ceil(totalTiles / 20.0);
	cout << "The needed number of boxes is " << numBoxes;
	cout << "There are " << (numBoxes * 20) - totalTiles << " wasted tiles.";
}

int InputFilter(int filterOption)
{
	int placeholder;
	string filterStatement = "Your input must be a positive integer"; // custom error message
	cin >> placeholder;

	// experiment getline to check whole given value for acceptability, remove double and float issue

	switch (true) // allows additional hints to user for inpupt  
	{
	case 1:
		while (cin.fail() || placeholder < 0)
		{
			cout << filterStatement << "." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> placeholder;
		}
		break;
	case 2:
		filterStatement += " and less than 12"; // this prompts the user to use a number less than 12, although this function does not cause the logic to loop if it is less than 12
		while (cin.fail() || placeholder < 0 || placeholder >= 12)
		{
			cout << filterStatement << "." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> placeholder;
		}
		break;
	default:
		break;
	}




	return floor(placeholder);
}



