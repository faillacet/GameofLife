#include "World.h"

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
	grid = new char*[y];							//y=row x=col
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

World::~World() {											//NOT DELETING PROPERLY??? WHY???  FIXXED WORKING FINE
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
	cout << "Generation: " << generation;
	generation++;
	for (int i=0; i<dimY;++i) {
		cout << endl;
		for (int j = 0; j < dimX; ++j) {
			cout << grid[i][j];
		}
	}
	cout << endl <<endl;
}

void World::copyFromFile(Input input) {
	for (int i =0; i<input.countY;++i){
		for (int j=0;j<input.countX;++j) {
			grid[i][j] = input.file[i][j];
		}
	}

}

void World::fillBoard(Input input) {
	int total = dimY*dimX;
	int bacteria = total*input.popDensity;

	const int range_from  = 0;										//code from stack overflow to get random number
	const int range_to    = dimY-1;
	const int range_to2   = dimX-1;
	random_device                  rand_dev;
	mt19937                        generator(rand_dev());
	uniform_int_distribution<int>  distr(range_from, range_to);
	uniform_int_distribution<int>  distr2(range_from, range_to2);
	
	int XX =0;
	int YY =0;
	for (int i =0; i<bacteria;++i) {
		grid[distr(generator)][distr2(generator)] = 'X';
	}

	for (int i =0;i<dimY;++i) {					//fills rest of board that didnt get bacteria
		for (int j=0;j<dimX;++j) {
			if (grid[i][j]!='X'){
				grid[i][j] = '-';
			}
		}
	}
}

void World::copyGrid() {
	for (int i =0;i<dimY;++i) {
		for (int j=0;j<dimX;++j) {
			grid2[i][j] = grid[i][j];
		}
	}
}

bool World::checkIsEmpty() {
	for (int i =0;i<dimY;++i) {
		for (int j=0;j<dimX;++j) {
			if (grid[i][j]=='X') {
				return false;
			}
		}
	}
	return true;
}

bool World::checkIsSame() {
	int count = 0;
	for (int i =0;i<dimY;++i) {
		for (int j=0;j<dimX;++j) {
			if (grid[i][j]==grid2[i][j]) {
				count++;
			}
		}
	}
	if (count == dimY*dimX) {
		return true;
	}
	return false;
}

void World::checkAll() {
	isEmpty = checkIsEmpty();
	isSame = checkIsSame();
}
