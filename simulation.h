#pragma once

class Simulation {
private:
	unsigned int gameMode;  //1 = default, 2=mirror, 3=donut
public:
	Simulation();			//defaults to 1
	Simulation(unsigned int x);
	~Simulation();


};



Simulation::Simulation() {

}

Simulation::Simulation(unsigned int x) {
	gameMode = x;
}

Simulation::~Simulation() {

}
