/*
 *    File: 5_18.cpp
 *    -------------
 *    A bouncing balls and mousetrap simulation in a 25x25 square grid.
 *    How many time intervals will it take for the balls to stop moving?
 *
 *    In writing this simulation, you should make the following simplifying assumptions:
 *
 *        Every ping-pong ball that falls always lands on a mousetrap,
 *        chosen randomly by selecting a random row and column in the grid.
 *        If the trap is loaded, its balls are released into the air.
 *        If the trap has already been sprung, having a ball fall on it has no effect.
 *        Once a ball falls on a mousetrap—whether or not the trap
 *        is sprung—that ball stops and takes no further role in the simulation.
 *        Balls launched from a mousetrap bounce around the room and land again after a
 *        random number of simulation cycles have gone by. That random interval is chosen
 *        independently for each ball and is always between one and four cycles."
 *
 */

#include <iostream>
#include "grid.h"
#include "random.h"
#include "queue.h"
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

    runSimulation(timeElapsed, numSprung, maxAirborne);
    printReport(timeElapsed, numSprung, maxAirborne);
    return 0;
}

void runSimulation(int &timeElapsed, int &numSprung, int &maxAirborne) {
    int ballsInAir = 0;
    Queue<int> queue;
    queue.enqueue(randomInteger(MIN_BALL_CYCLES, MAX_BALL_CYCLES));
    ballsInAir++;
    Grid<int> grid(GRID_SIZE, GRID_SIZE);
    for (int i = 0, i < GRID_SIZE, i++) {
        for (int j = 0, j < GRID_SIZE, j++) {
            grid.set(i, j, BALLS_PER_TRAP);
        }
    }
    while (ballsInAir > 0) {
        if (queue.peek() > 0) { //Checking to see if the ball is still bouncing around the room.
           queue.enqueue(queue.dequeue() - 1); //This subtracts one bounce cycle and puts the ball back in the queue.
        } else { //The ball is done bouncing around the room.
            int currentX = randomInteger(0, GRID_SIZE); // choosing where it will land
            int currnetY = randomInteger(0, GRID_SIZE); //
            if (grid.get(currentX, currnetY) > 0) { // As long as the square hasn't been set off before do this:
                ballsInAir--;
                grid.set(currentX, currnetY, 0);
                queue.enqueue(randomInteger(MIN_BALL_CYCLES, MAX_BALL_CYCLES));
                queue.enqueue(randomInteger(MIN_BALL_CYCLES, MAX_BALL_CYCLES));
                ballsInAir += 2;
                numSprung += 2;
            } else {
                ballsInAir--;
            }
            if (maxAirborne < ballsInAir) {
                maxAirborne = ballsInAir;
            }
        }
        timeElapsed++;
    }
}

void printReport(int timeElapsed, int numSprung, int maxAirborne) {
    cout << "---------- RESULTS --------------";
    cout << "Max number of balls airborne: " << maxAirborne;
    cout << "Percentage of traps sprung:   " << (GRID_SIZE * GRID_SIZE) / numSprung << "%";
    cout << "Total time units elapsed:     " << timeElapsed;
}
