#include "simulation.h"

Simulation::Simulation() {

}

Simulation::Simulation(unsigned int x) {
	gameMode = x;
}

Simulation::~Simulation() {

}

unsigned int Simulation::isFilled(int a, int b, World& world) {
	if (world.grid2[a][b]== 'X') {
		return 1;
	}
	else if (world.grid2[a][b]=='-') {
		return 0;
	}
	else {
		cout << "This doesnt work!" << endl;
		return 0;
	}
}

unsigned int Simulation::neighborsN(int a, int b, World& world) {		//a=Y b=X
	unsigned int count = 0;									//corners first
	if (a == 0 && b== 0) {								//case top left
		count += isFilled(1,0,world);
		count += isFilled(1,1,world);
		count += isFilled(0,1,world);
		return count;
	}
	else if (a==world.dimY-1 && b==world.dimX-1) {		//case bottom right
		count += isFilled(a-1,b,world);
		count += isFilled(a-1,b-1,world);
		count += isFilled(a,b-1,world);
		return count;
	}
	else if (a==0 && b==world.dimX-1) {					//case top right
		count += isFilled(a,b-1,world);
		count += isFilled(a+1,b,world);
		count += isFilled(a+1,b-1,world);
		return count;
	}
	else if (a==world.dimY-1 && b==0) {					//case bottom left
		count += isFilled(a,b+1,world);
		count += isFilled(a-1,b,world);
		count += isFilled(a-1,b+1,world);
		return count;
	}													//EDGES 
	else if (a==0 && b!=world.dimX-1) {					//Top row			
		count += isFilled(a,b-1,world);					
		count += isFilled(a,b+1,world);
		count += isFilled(a+1,b-1,world);
		count += isFilled(a+1,b,world);
		count += isFilled(a+1,b+1,world);
		return count;
	}
	else if (a!=world.dimY-1 && b==0){					//Left side collumn
		count += isFilled(a-1,b,world);					
		count += isFilled(a-1,b+1,world);
		count += isFilled(a,b+1,world);
		count += isFilled(a+1,b+1,world);
		count += isFilled(a+1,b,world);
		return count;
	}
	else if (a==world.dimY-1 && b!=world.dimX-1) {		//Bottom row
		count += isFilled(a,b-1,world);					
		count += isFilled(a-1,b-1,world);
		count += isFilled(a-1,b,world);
		count += isFilled(a-1,b+1,world);
		count += isFilled(a,b+1,world);
		return count;
	}
	else if (a!=world.dimY-1 && b==world.dimX-1) {		//Right side collumn
		count += isFilled(a-1,b,world);					
		count += isFilled(a-1,b-1,world);
		count += isFilled(a,b-1,world);
		count += isFilled(a+1,b-1,world);
		count += isFilled(a+1,b,world);
		return count;
	}
	else {												//general case (anywhere in the middle)
		count += isFilled(a-1,b-1,world);					
		count += isFilled(a-1,b,world);
		count += isFilled(a-1,b+1,world);
		count += isFilled(a,b-1,world);
		count += isFilled(a,b+1,world);
		count += isFilled(a+1,b-1,world);
		count += isFilled(a+1,b,world);
		count += isFilled(a+1,b+1,world);
		return count;
	}
}

void Simulation::runDeafult(World& world) {
	for (int i =0;i<world.dimY;++i){
		for (int j =0;j<world.dimX;++j){
			if (neighborsN(i,j, world) <2){
				world.grid[i][j] = '-';
			}
			else if (neighborsN(i,j,world) == 2) {
				world.grid[i][j] = world.grid[i][j];
			}
			else if (neighborsN(i,j, world)==3) {
				world.grid[i][j] = 'X';
			}
			else if (neighborsN(i,j,world)>3) {
				world.grid[i][j] = '-';
			}
		}
	}
}

unsigned int Simulation::neighborsM(int a, int b, World& world) {		//a=Y b=X
		unsigned int count = 0;									//corners first
	if (a == 0 && b== 0) {										//case top left
		if (isFilled(0,0,world)==1) {
			count +=3;
		}
		if (isFilled(1,0,world)==1) {
			count +=2;
		}
		if (isFilled(0,1,world)==1) {
			count +=2;
		}
		count += isFilled(1,1,world);
		return count;
	}
	else if (a==world.dimY-1 && b==world.dimX-1) {		//case bottom right
		if (isFilled(world.dimX-1,world.dimX-1,world) == 1) {
			count +=3;
		}
		if (isFilled(a-1,b,world)==1) {
			count +=2;
		}
		if (isFilled(a,b-1,world)==1) {
			count +=2;
		}
		count += isFilled(a-1,b-1,world);
		return count;
	}
	else if (a==0 && b==world.dimX-1) {					//case top right
		if (isFilled(0,world.dimX-1,world)==1) {
			count +=3;
		}
		if (isFilled(a,b-1,world)==1) {
			count +=2;
		}
		if (isFilled(a+1,b,world)==1) {
			count +=2;
		}
		count += isFilled(a+1,b-1,world);
		return count;
	}
	else if (a==world.dimY-1 && b==0) {					//case bottom left
		if (isFilled(world.dimY-1,0,world)==1) {
			count +=3;
		}
		if (isFilled(a,b+1,world)==1) {
			count +=2;
		}
		if (isFilled(a-1,b,world)==1) {
			count +=2;
		}
		count += isFilled(a-1,b+1,world);
		return count;
	}													//EDGES 
	else if (a==0 && b!=world.dimX-1) {					//Top row	
		if (isFilled(a,b,world)==1) {
			count +=1;
		}		
		if (isFilled(a,b-1,world)==1) {
			count +=2;
		}
		if (isFilled(a,b+1,world)==1) {
			count +=2;
		}					
		count += isFilled(a+1,b-1,world);
		count += isFilled(a+1,b,world);
		count += isFilled(a+1,b+1,world);
		return count;
	}
	else if (a!=world.dimY-1 && b==0){					//Left side collumn
		if (isFilled(a,b,world)==1) {
			count +=1;
		}
		if (isFilled(a-1,b,world)==1) {
			count +=2;
		}
		if (isFilled(a+1,b,world)==1) {
			count +=2;
		}			
		count += isFilled(a-1,b+1,world);
		count += isFilled(a,b+1,world);
		count += isFilled(a+1,b+1,world);
		return count;
	}
	else if (a==world.dimY-1 && b!=world.dimX-1) {		//Bottom row
		if (isFilled(a,b,world)==1) {
			count +=1;
		}
		if (isFilled(a,b-1,world)==1) {
			count +=2;
		} 
		if (isFilled(a,b+1,world)==1) {
			count +=2;
		}		
		count += isFilled(a-1,b-1,world);
		count += isFilled(a-1,b,world);
		count += isFilled(a-1,b+1,world);
		return count;
	}
	else if (a!=world.dimY-1 && b==world.dimX-1) {		//Right side collumn
		if (isFilled(a,b,world)==1){
			count +=1;
		}
		if (isFilled(a-1,b,world)==1) {
			count +=2;
		}
		if (isFilled(a+1,b,world)==1) {
			count +=2;
		}				
		count += isFilled(a-1,b-1,world);
		count += isFilled(a,b-1,world);
		count += isFilled(a+1,b-1,world);
		return count;
	}
	else {												//general case (anywhere in the middle)
		count += isFilled(a-1,b-1,world);					
		count += isFilled(a-1,b,world);
		count += isFilled(a-1,b+1,world);
		count += isFilled(a,b-1,world);
		count += isFilled(a,b+1,world);
		count += isFilled(a+1,b-1,world);
		count += isFilled(a+1,b,world);
		count += isFilled(a+1,b+1,world);
		return count;
	}
}	

void Simulation::runMirror(World& world) {
	for (int i =0;i<world.dimY;++i){
		for (int j =0;j<world.dimX;++j){
			if (neighborsM(i,j, world) <2){
				world.grid[i][j] = '-';
			}
			else if (neighborsM(i,j,world) == 2) {
				world.grid[i][j] = world.grid[i][j];
			}
			else if (neighborsM(i,j, world)==3) {
				world.grid[i][j] = 'X';
			}
			else if (neighborsM(i,j,world)>3) {
				world.grid[i][j] = '-';
			}
		}
	}
}	

unsigned int Simulation::neighborsD(int a, int b, World& world) {
	unsigned int count = 0;									//corners first
	if (a == 0 && b== 0) {								//case top left
		count += isFilled(1,0,world);
		count += isFilled(1,1,world);
		count += isFilled(0,1,world);
		count += isFilled(world.dimY-1,0,world);
		count += isFilled(0,world.dimX-1,world);
		count += isFilled(world.dimY-1,world.dimX-1,world);
		count += isFilled(1,world.dimX-1,world);
		count += isFilled(world.dimY-1, 1, world);
		return count;
	}
	else if (a==world.dimY-1 && b==world.dimX-1) {		//case bottom right
		count += isFilled(a-1,b,world);
		count += isFilled(a-1,b-1,world);
		count += isFilled(a,b-1,world);
		count += isFilled(0,world.dimX-1,world);
		count += isFilled(world.dimY-1,0, world);
		count += isFilled(0,0,world);
		count += isFilled(0,world.dimX-2,world);
		count += isFilled(world.dimY-2,0,world);
		return count;
	}
	else if (a==0 && b==world.dimX-1) {					//case top right
		count += isFilled(a,b-1,world);
		count += isFilled(a+1,b,world);
		count += isFilled(a+1,b-1,world);
		count += isFilled(world.dimY-1,world.dimX-1,world);
		count += isFilled(0,0,world);
		count += isFilled(world.dimY-1,0,world);
		count += isFilled(world.dimY-1,world.dimX-2,world);
		count += isFilled(1,0,world);
		return count;
	}
	else if (a==world.dimY-1 && b==0) {					//case bottom left
		count += isFilled(a,b+1,world);
		count += isFilled(a-1,b,world);
		count += isFilled(a-1,b+1,world);
		count += isFilled(0,0,world);
		count += isFilled(world.dimY-1,world.dimX-1,world);
		count += isFilled(0,world.dimX-1,world);
		count += isFilled(world.dimY-2,world.dimX-1,world);
		count += isFilled(0,1,world);
		return count;
	}													//EDGES 
	else if (a==0 && b!=world.dimX-1) {					//Top row			
		count += isFilled(a,b-1,world);					
		count += isFilled(a,b+1,world);
		count += isFilled(a+1,b-1,world);
		count += isFilled(a+1,b,world);
		count += isFilled(a+1,b+1,world);
		count += isFilled(world.dimY-1,b-1,world);
		count += isFilled(world.dimY-1,b,world);
		count += isFilled(world.dimY-1,b+1,world);
		return count;
	}
	else if (a!=world.dimY-1 && b==0){					//Left side collumn
		count += isFilled(a-1,b,world);					
		count += isFilled(a-1,b+1,world);
		count += isFilled(a,b+1,world);
		count += isFilled(a+1,b+1,world);
		count += isFilled(a+1,b,world);
		count += isFilled(a-1,world.dimX-1,world);
		count += isFilled(a,world.dimX-1,world);
		count += isFilled(a+1,world.dimX-1,world);
		return count;
	}
	else if (a==world.dimY-1 && b!=world.dimX-1) {		//Bottom row
		count += isFilled(a,b-1,world);					
		count += isFilled(a-1,b-1,world);
		count += isFilled(a-1,b,world);
		count += isFilled(a-1,b+1,world);
		count += isFilled(a,b+1,world);
		count += isFilled(0,b-1,world);
		count += isFilled(0,b,world);
		count += isFilled(0,b+1,world);
		return count;
	}
	else if (a!=world.dimY-1 && b==world.dimX-1) {		//Right side collumn
		count += isFilled(a-1,b,world);					
		count += isFilled(a-1,b-1,world);
		count += isFilled(a,b-1,world);
		count += isFilled(a+1,b-1,world);
		count += isFilled(a+1,b,world);
		count += isFilled(a-1,0,world);
		count += isFilled(a,0,world);
		count += isFilled(a+1,0,world);
		return count;
	}
	else {												//general case (anywhere in the middle)
		count += isFilled(a-1,b-1,world);					
		count += isFilled(a-1,b,world);
		count += isFilled(a-1,b+1,world);
		count += isFilled(a,b-1,world);
		count += isFilled(a,b+1,world);
		count += isFilled(a+1,b-1,world);
		count += isFilled(a+1,b,world);
		count += isFilled(a+1,b+1,world);
		return count;
	}
}	

void Simulation::runDonut(World& world) {
	for (int i =0;i<world.dimY;++i){
		for (int j =0;j<world.dimX;++j){
			if (neighborsD(i,j, world) <2){
				world.grid[i][j] = '-';
			}
			else if (neighborsD(i,j,world) == 2) {
				world.grid[i][j] = world.grid[i][j];
			}
			else if (neighborsD(i,j, world)==3) {
				world.grid[i][j] = 'X';
			}
			else if (neighborsD(i,j,world)>3) {
				world.grid[i][j] = '-';
			}
		}
	}
}

void Simulation::simulate(World& world, Input input) {
	while (world.isEmpty==false && world.isSame == false) {
		if (gameMode ==1) {
			runDeafult(world);
		}
		else if (gameMode==2) {
			runMirror(world);
		}
		else {
			runDonut(world);
		}

		if (input.useEnter == true) {
			world.display();
			world.checkAll();
			world.copyGrid();
			pause();
		}
		else {
			world.display();
			world.checkAll();
			world.copyGrid();
			std::this_thread::sleep_for (std::chrono::milliseconds(250));		//taken from stack overflow, used to have a small delay between generations
		}
	}
}

void Simulation::pause() {							//taken from stack overflow, used as system("pause")
	cout << "Press ENTER to continue..."; 
	cin.clear();
	cin.sync();
	cin.get();
}

void Simulation::simulateF(World& world, Input input) {
	int counter = 0;
	int generation = 0;
	ofstream myFile("TrentonFaillace.txt");
	if (myFile.is_open()) {
		while (world.isEmpty==false && world.isSame == false && counter < 100000) {			//maxed out so computer doesnt crash (hopefully)
			counter++;
			if (gameMode ==1) {
				runDeafult(world);
				myFile << "Generation: " << generation <<endl;
				generation++;
				for (int i=0; i<world.dimY;++i) {
					myFile << endl;
					for (int j = 0; j < world.dimX; ++j) {
						myFile << world.grid[i][j];
					}
				}
			myFile << endl << endl;
			}
			else if (gameMode==2) {
				runMirror(world);
				myFile << "Generation: " << generation <<endl;
				generation++;
				for (int i=0; i<world.dimY;++i) {
					myFile << endl;
					for (int j = 0; j < world.dimX; ++j) {
						myFile << world.grid[i][j];
					}
				}
				myFile << endl << endl;
			}
			else {
				runDonut(world);
				myFile << "Generation: " << generation <<endl;
				generation++;
				for (int i=0; i<world.dimY;++i) {
					myFile << endl;
					for (int j = 0; j < world.dimX; ++j) {
						myFile << world.grid[i][j];
					}
				}
				myFile << endl << endl;
			}
			world.checkAll();
			world.copyGrid();
		}
		myFile.close();
	}
	else {
		cout<< "Error writing to file... :(" << endl;
	}		
}
