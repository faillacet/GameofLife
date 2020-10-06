#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Input {
private:
	char input;
	int dimX, dimY;
	double popDensity;
public:
	Input();
	~Input();
	void userBoard();
	void fileBoard();			//TODO READ FROM FILE
	int getX();
	int getY();
	double getPop();

	//File reading stuff below
	void getFile(string file);
};

Input::Input() {
	cout << "Would you like to to use a custom board? Respond Y/N" << endl;
	cin >> input;
	if (input == 'Y' || input == 'y') {
		fileBoard();
	}
	else if (input == 'N' || input == 'n') {
		userBoard();
	}
	else {
		cout << "Input could not be understood.  Defaulting to user defined board." << endl;
		userBoard();
	}
}

Input::~Input() {

}

void Input::userBoard() {
	cout << "We will randomly generate a board for you!" << endl;
	cout << "What would you like the dimensions of the world to be?  Please enter an integer greater than 0." << endl;
	cout << "Number of Columns: ";
	cin >> dimX;
	cout << "Number of Rows: ";
	cin >> dimY;

	if (dimX <= 0 || dimY <= 0) {
		cout << "Incorrect input. Setting to defaults." << endl;
		dimX = 5;
		dimY = 5;
	}

	cout << "World Dimensions set to: " << dimX << " X " << dimY << endl;
	cout << "What would you like the starting population density to be?  Please enter a decimal between 0 and 1." << endl;
	cout << "Population Density: ";
	cin >> popDensity;

	if (popDensity <= 0 || popDensity >= 1) {
		cout << "Incorrect input.  Setting to default (.5)." << endl;
		popDensity = .5;
	}

	cout << endl << "Population Density set to: " << popDensity << endl;
	cout << "Thank you!  All parameters set, click enter to begin the Simulation." << endl;
	system("pause");
}

void Input::fileBoard() {
	string fileName;
	cout << "Please Enter the name of the file u wish to use.  Must be in the same directory as this program." << endl;
	cout << "File Name: ";
	cin >> fileName;
	
	ifstream myFile(fileName);
	string x;
	if (myFile.is_open()) {
		while (getline(myFile, x)) {
																	//TODO READ FROM A FILE
		}
		myFile.close();

		cout << "File loaded, click eneter to begin Simulation." << endl;
		system("pause");
	}
	else {
		cout << "Error opening file, exiting program..." << endl;
	}
}

int Input::getX() {
	return dimX;
}

int Input::getY() {
	return dimY;
}

double Input::getPop() {
	return popDensity;
}
