#ifndef WORLD_H
#define WORLD_H

#include "Input.h"
#include <iostream>
#include <string>
#include <cstring>
#include <random>
using namespace std;

class World {
private:
	char** grid;
	char** grid2;
	int dimY = 5;		//dimensions
	int dimX = 5;	
	int generation = 1;
	bool isFill;			//check if bacteria is in grid location
	bool isEmpty = false;         
	bool isSame = false;  
public:
	World();							//default constructor
	World(int dimX, int dimY);			//constructor that includes dimesions of grid
	~World();							//default destructor - frees memory

	void display();						//prints world to screen
	void fillBoard(Input input);		//fills a user defined board based on popdensity
	void copyFromFile(Input input);		//copies the board from a file into the world object
	void copyGrid();					//used to copy grid 1 to grid 2
	bool checkIsEmpty();				//checks if the grid is empty/produces a pattern
	bool checkIsSame();					//checks the previous generation with the next to see if they are the same
	void checkAll();					//void func that uses the above 2 functions

	friend class Input;
	friend class Simulation;
 };

#endif
