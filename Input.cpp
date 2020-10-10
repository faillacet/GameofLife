#include "Input.h"

Input::Input() {
	cout << "Would you like to to use a File? Respond Y/N" << endl;
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
	cout << "We will generate a board for you!" << endl;
	cout << "What would you like the dimensions of the world to be?  Please enter an integer greater than 0." << endl;
	cout << "Number of Columns: ";
	cin >> dimX;
	cout << "Number of Rows: ";
	cin >> dimY;

	if (dimX < 1 || dimY <= 1) {
		cout << "Incorrect input. Setting to defaults." << endl;
		dimX = 5;
		dimY = 5;
	}

	cout << "World Dimensions set to: " << dimX << " X " << dimY << endl;
	cout << "What would you like the starting population density to be?  Please enter a decimal between 0 and 1. (.3-.7 works best)" << endl;
	cout << "Population Density: ";
	cin >> popDensity;

	if (popDensity <= 0 || popDensity >= 1) {
		cout << "Incorrect input.  Setting to default (.5)." << endl;
		popDensity = .5;
	}

	cout << "Population Density set to: " << popDensity << endl;
	cout << "Thank you!  All parameters set." << endl;
	cout << "Please choose a Game Mode.  1 = Default, 2 = Mirror, 3 = Donut" <<endl;
	cout << "Game Mode: ";
	cin >> gameMode;
	if (gameMode <1 || gameMode >3) {
		cout << "Input not understood, using default GameMode." <<endl;
		gameMode=1;
	}
	char c;
	cout << "Would you like to print to a file? Type Y/N" << endl;
	cin >> c;
	if (c == 'Y' || c == 'y') {
		printFile = true;
	}
	else {
		cout << "Printing to console." <<endl;
		cout << "Would you like to press enter between generations? Type Y/N" <<endl;
		cin >> c;
		if (c =='Y'||c=='y'){
			useEnter=true;
		}
	}
}

void Input::fileBoard() {
	bool check = false;
	string fileName;
	cout << "Please Enter the name of the file u wish to use.  Must be in the same directory as this program." << endl;
	cout << "File Name: ";
	cin >> fileName;

	int countZ=0;
	int count=0;
	ifstream myFile(fileName);
	string x;
	if (myFile.is_open()) {
		while (getline(myFile, x)) {
			countZ++;
		}
		myFile.close();
	}
	else { 
		cout << "Error opening file." << endl;
	}
	file = new string[countZ];
	ifstream myFile2(fileName);
	if (myFile2.is_open()) {
		while(getline(myFile2, x)){
			if (count >1){
				file[count-2]=x;
			}
			count++;
		}
		countX=x.length();
		countY=countZ-2;
		myFile2.close();
		cout << "File loaded, Please choose a Game Mode.  1 = Default, 2 = Mirror, 3 = Donut" <<endl;
		cout << "Game Mode: ";
		cin >> gameMode;
		if (gameMode <1 || gameMode >3) {
			cout << "Input not understood, using default GameMode." <<endl;
			gameMode=1;
		}
		usedFile=true;
	}
	else {
		cout <<"Error opening file, switching to manual board generation." << endl;
		check = true;
		userBoard();
	}
	if (check == false) {
		char c;
		cout << "Would you like to print to a file? Type Y/N" << endl;
		cin >> c;
	if (c == 'Y' || c == 'y') {
		printFile = true;
	}
	else {
		cout << "Not understood, printing to console." <<endl;
		cout << "Would you like to use a pause between generations? Type Y/N" <<endl;
		cin >> c;
		if (c =='Y'||c=='y'){
			useEnter=true;
		}
	}
	}

}

int Input::getX() {
	return dimX;
}

int Input::getY() {
	return dimY;
}

int Input::getCountX() {
	return countX;
}

int Input::getCountY() {
	return countY;
}

double Input::getPop() {
	return popDensity;
}

bool Input::getBool() {
	return usedFile;
}

unsigned int Input::getGameMode() {
	return gameMode;
}

bool Input::getPrintFile() {
	return printFile;
}
