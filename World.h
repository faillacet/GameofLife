#pragma once
#include <iostream>
using namespace std;

class World {
private:
	char** grid;
	char** grid2;
	int dimY = 5;		//dimensions
	int dimX = 5;	
	int generation = 0;
	bool isFill;			//check if bacteria is in grid location
public:
	World();				//default constructor
	World(int dimX, int dimY);			//constructor that includes dimesions of grid
	~World();				//default destructor

	void display();			//prints world to screen
	//void simulate();		//simulates one breeding time
	friend class Input;

 };

World::World() {
	grid = new char*[5];
	for (int i = 0; i < 5; ++i) {
		grid[i] = new char[5];
	}
	grid2 = new char*[5];
	for (int i = 0; i < 5; ++i) {
		grid2[i] = new char[5];
	}

}

World::World(int x,int y) {							//row first, them col
	grid = new char*[y];
	for (int i = 0; i < y; ++i) {
		grid[i] = new char[x];
	}
	grid2 = new char*[y];
	for (int i = 0; i < y; ++i) {
		grid2[i] = new char[x];
	}
	dimX = x;
	dimY = y;
}

World::~World() {											//NOT DELETING PROPERLY??? WHY???
	for (int i = 0; i < dimY; ++i) {
		delete[] grid[i];
	}
	delete[] grid;
	for (int i = 0; i < dimY; ++i) {
		delete[] grid2[i];
	}
	delete[] grid2;
}

void World::display() {

	/*for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			grid[i][j] = 'X';
		}
	}*/
	cout << "Generation: " << generation << endl << endl;
	generation += 1;
	for (int i=0; i<5;++i) {
		cout << endl;
		for (int j = 0; j < 5; ++j) {
			cout << grid[i][j];
		}
	}
	cout << endl;
}
