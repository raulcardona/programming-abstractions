/*
 * File: 2_14.cpp
 * -------------
 * Heads/Tails 3 in a row
 * 
 * This program simulates a coin flip
 * We keep flipping until one result comes up 3 times in a row
 *
 */

#include <iostream>
#include "random.h"

using namespace std;


/* Function Prototypes */
string flipThemCoins(int & h, int & t);
void printResults(int h, int t, string c);

/* main */
int main() {
    int hCount = 0;
    int tCount = 0;
    
    string winner = flipThemCoins(hCount, tCount);
    printResults(hCount, tCount, winner);
    
    
    
    return 0;
}

/* Function to simulate the coin flipping
 * stops after 3 consecutives
 * passes reference to track the totals
 * returns the winning coin type.
 */
string flipThemCoins(int & h, int & t) {
    
    int hCCounter = 0;
    int tCCounter = 0;
    
    while (true) {
        if (hCCounter >= 3 || tCCounter >= 3) {
            break;
        }
        else if (randomChance(0.5)) {
            cout << "Heads" << endl;
            h++;
            hCCounter++;
            tCCounter = 0;
        }
        else {
            cout << "Tails" << endl;
            t++;
            tCCounter++;
            hCCounter = 0;
        }
        
    }
    
    string coin;
    if (h >  t) coin = "heads";
    else coin = "tails";
    return coin;
    
}

void printResults(int h, int t, string c) {
    
    
    cout << "It took " << h + t << " flips to get 3 consecutive " << c;
}