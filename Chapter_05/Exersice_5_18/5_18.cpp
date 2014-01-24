/*
 * File: 5_18.cpp
 * -------------
 * A bouncing balls and mousetrap simulation in a 25x25 square grid.
 * How many time intervals will it take for the balls to stop moving?
 * 

	"In writing this simulation, you should make the following simplifying assumptions:

	• Every ping-pong ball that falls always lands on a mousetrap, 
		chosen randomly by selecting a random row and column in the grid. 
		If the trap is loaded, its balls are released into the air. 
		If the trap has already been sprung, having a ball fall on it has no effect.
	• Once a ball falls on a mousetrap—whether or not the trap 
		is sprung—that ball stops and takes no further role in the simulation.
	• Balls launched from a mousetrap bounce around the room and land again after a 
		random number of simulation cycles have gone by. That random interval is chosen 
		independently for each ball and is always between one and four cycles."

*
*/

#include <iostream>
#include "grid.h"

using namespace std;

/*Constants*/

const int GRID_SIZE = 25;
const int BALLS_PER_TRAP = 2;
const int MIN_BALL_CYCLES = 1;
const int MAX_BALL_CYCLES = 4;


/*Function Prototypes*/

void runSimulation(int &timeElapsed, int &numSprung, int &maxAirborne);
void printReport(int timeElapsed, int numSprung, int maxAirborne);

/*Main*/

int main() {
	
	int timeElapsed = 0;
	int numSprung = 0;
	int maxAirborne = 0;

	runSimulation(grid, timeElapsed, numSprung, maxAirborne);
	printReport(timeElapsed, numSprung, maxAirborne);

}

void runSimulation(int &timeElapsed, int &numSprung, int &maxAirborne) {
	Grid<bool>(GRID_SIZE, GRID_SIZE) grid;
}

void printReport(int timeElapsed, int numSprung, int maxAirborne) {

}
