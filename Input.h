#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Input {
private:
	char input;
	int dimX =0;					//dimensions of the board
	int dimY =0;
	double popDensity;
	string* file;
	int countX = 0;
	int countY = 0;
	bool usedFile = false;
	bool printFile = false;
	bool useEnter = false;
	unsigned int gameMode = 0;
public:
	Input();
	~Input();
	void userBoard();				//gets info to create a user defined board
	void fileBoard();				//gets the board from a file provided by user
	int getX();						//getters used for communication across objects
	int getY();
	int getCountX();
	int getCountY();
	double getPop();
	bool getBool();
	unsigned int getGameMode();
	bool getPrintFile();

	friend class World;
	friend class Simulation;
};

#endif
