#ifndef SIMULATION_H
#define SIMULATION_H

#include "World.h"
#include <thread>         
#include <chrono> 

class Simulation {
private:
	unsigned int gameMode = 1;  //1 = default, 2=mirror, 3=donut
public:
	Simulation();			//defaults to 1
	Simulation(unsigned int x);
	~Simulation();

	unsigned int isFilled(int a, int b, World& world);			//check a location to see if it contains - or X *returns 1 if X 0 if -

	unsigned int neighborsN(int a, int b, World& world);		//neighbor checker for default gamemode
	void runDeafult(World& world);								//run a single sim of deafulat gamemode
	
	unsigned int neighborsM(int a, int b, World& world);		//neighbor checker for Mirror gamemode
	void runMirror(World& world);								//run a single sim of Mirror gamemode

	unsigned int neighborsD(int a, int b, World& world);		//neigbor checker for Donut gamemode
	void runDonut(World& world);								//run a single sin of Donut gamemode

	void simulate(World& world, Input input);					//will use any of the above functions depending on game mode
	void simulateF(World& world, Input input);					//same function but prints to file instead of console

	void pause();												//function used if user wants a pause between generations
	
	friend class Input;
	friend class World;
};

#endif
