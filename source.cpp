#include "World.h"
#include "Input.h"
#include "simulation.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {							//relativly simple main	
	Input input;											//creates input object, automatically gets all needed information from user
	if (input.getBool()==true) {							//checks to see if was read from a file or not (needs to use differing variables)
		World world(input.getCountX(),input.getCountY());
		world.copyFromFile(input);

		Simulation sim(input.getGameMode());				//simulation class is created and game mode is set
		if (input.getPrintFile()==false) {					//Runs simulation to terminal
			world.display();
			world.copyGrid();
			sim.simulate(world,input);
		}
		else {												//Runs simulation to file output
			world.copyGrid();
			sim.simulateF(world,input);
		}
	}	
	else {
		World world(input.getX(),input.getY());				//same as above, but uses a user generated board
		world.fillBoard(input);								//fills the board

		Simulation sim(input.getGameMode());	
		if (input.getPrintFile()==false) {					//simulation runs to terminal
			world.display();
			world.copyGrid();
			sim.simulate(world,input);
		}
		else {												//simulation runs to outputted file
			world.copyGrid();
			sim.simulateF(world,input);
		}
	}
	cout << "Thank you!" <<endl;							//Thank user for using program :)
	return 0;
}

