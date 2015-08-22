//
//  9_12.cpp
//  Programming Abstractions C++
//
//  Created by Ben Mills on 8/21/15.
//
//  MiniMax Nim with one pile

#include <iostream>
#include <string>
#include "simpio.h"
#include "error.h"
#include "strlib.h"
#include "console.h"
#include "vector.h"

using namespace std;

/* Constants */
const int N_COINS = 13;
const int MAX_MOVE = 3;
const int WINNING_POSITION = 100;
const int LOSING_POSITION = -WINNING_POSITION;
const int MAX_DEPTH = 20;


/* Enumerators */
enum Player { HUMAN, COMPUTER};

Player opponent(Player player) {
    return (player == HUMAN) ? COMPUTER : HUMAN;
}

const Player STARTING_PLAYER = HUMAN;

/* Structures */
struct Move {
    int nTaken;
};

/* Class */
class Nim {
    
public:
    void play() {
        initGame();
        while (!gameIsOver()) {
            displayGame();
            if (getCurrentPLayer() == HUMAN) {
                makeMove(getUserMove());
            } else {
                Move move = getComputerMove();
                displayMove(move);
                makeMove(move);
            }
            switchTurn();
        }
        announceResult();
    }
    
    void printInsructions() {
        cout << "Welcome to the game of Nim!" << endl;
        cout << "In this game, we will start with a pile of" << endl;
        cout << N_COINS << " coins on the table.  On each turn, you" << endl;
        cout << "and I will alternately take between 1 and" << endl;
        cout << MAX_MOVE << " coins from the table.  The plater who" << endl;
        cout << "takes the last coin loses." << endl << endl;
        
    }
    
private:
    
    void initGame() {
        nCoins = N_COINS;
        whoseTurn = STARTING_PLAYER;
    }
    
    bool gameIsOver() {
        return (nCoins <= 1);
    }
    
    void displayGame() {
        cout << "There are " << nCoins << " coins in the pile" << endl;
    }
    
    Player getCurrentPLayer() {
        return whoseTurn;
    }
    
    void makeMove(int move) {
        nCoins -= move;
    }
    
    Move getComputerMove() {
        return findBestMove();
    }
    
    void displayMove(Move move) {
        cout << "I'll take " << move.nTaken << "." << endl;
    }
    
    void makeMove(Move move) {
        nCoins -= move.nTaken;
    }
    
    void switchTurn() {
        whoseTurn = opponent(whoseTurn);
    }
    
    Move findBestMove() {
        int rating;
        return findBestMove(0, rating);
    }
    
    Move findBestMove(int depth, int &rating) {
        Vector<Move> moveList;
        Move bestMove;
        int minRating = WINNING_POSITION + 1;
        generateMoveList(moveList);
        if (moveList.isEmpty()) error("No moves available");
        for (Move move: moveList) {
            makeMove(move);
            int moveRating = evaluatePosition(depth + 1);
            if (moveRating < minRating) {
                bestMove = move;
                minRating = moveRating;
            }
            retractMove(move);
        }
        rating = -minRating;
        return bestMove;
    }
    
    int evaluatePosition(int depth) {
        if (gameIsOver() || depth >= MAX_DEPTH) {
            return evaluateStaticPosition();
        }
        int rating;
        findBestMove(depth, rating);
        return rating;
    }

    int getUserMove() {
        while (true) {
            int nTaken = getInteger("How many would you like: ");
            int limit = (nCoins < MAX_MOVE) ? nCoins : MAX_MOVE;
            if (nTaken > 0 && nTaken <= limit) return nTaken;
            cout << "That's cheating! Please choose a number";
            cout << " between 1 and " << limit << "." << endl;
            cout << "There are " << nCoins << " coins in the pile." << endl;
        }
    }
    
    void generateMoveList(Vector<Move> &moveList) {
        Move move;
        int limit = (nCoins < MAX_MOVE) ? nCoins : MAX_MOVE;
        for (int i = 1; i <= limit; i++) {
            move.nTaken = i;
            moveList.add(move);
        }
    }
    
    void retractMove(Move move) {
        nCoins += move.nTaken;
    }
    
    int evaluateStaticPosition() {
        switch (nCoins) {
            case 1:
                return LOSING_POSITION;
                break;
            case 2:
                return WINNING_POSITION;
                break;
            case 3:
                return 50;
                break;
            case 4:
                return 25;
                break;
            case 5:
                return LOSING_POSITION;
                break;
            default:
                return 0;
                break;
        }
    }
    
    
    
    void announceResult() {
        if (nCoins == 0) {
            cout << "You took the last coin.  You lose." << endl;
        } else {
            cout << "There is only one coin left." << endl;
            if (whoseTurn == HUMAN) {
                cout << "I win." << endl;
            } else {
                cout << "I lose." << endl;
            }
        }
    }

    
/* Instance Variables */
    int nCoins;
    Player whoseTurn;
    
};

/* Main Program */
int main() {
    Nim game;
    game.printInsructions();
    game.play();
    return 0;
}
               
