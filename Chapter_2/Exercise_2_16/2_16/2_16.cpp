/*
 * File: 2_16.cpp
 * -------------
 *  A checkerboard with the Stanford graphics library!
 *
 */

#include <iostream>
#include "gwindow.h"

using namespace std;

/* Constants */

double const SQUARE_SIZE = 100; // adjust this value to change everything's size.
double const PIECE_SIZE = 0.85 * SQUARE_SIZE;
double const PIECE_OFFSET = (SQUARE_SIZE - PIECE_SIZE) / 2;
double const WINDOW_WIDTH = SQUARE_SIZE * 8;


/* Function Prototypes */
void drawBoard(GWindow & gw);
void drawGreySquare(GWindow & gw, int x, int y, double width);
void drawWhiteSquare(GWindow & gw, int x, int y, double width);
void drawRedPiece(GWindow & gw, int x, int y, double width);
void drawBlackPiece(GWindow & gw, int x, int y, double width);


/* main */
int main() {
    GWindow gw(WINDOW_WIDTH, WINDOW_WIDTH);
    drawBoard(gw);
    return 0;
}

void drawBoard(GWindow & gw) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            double x = SQUARE_SIZE * j;
            double y = SQUARE_SIZE * i;
            
            if ((j + i) % 2 == 0) {
                drawGreySquare(gw, x, y, SQUARE_SIZE);
                if (i < 3) {
                    drawRedPiece(gw, x + PIECE_OFFSET, y + PIECE_OFFSET, PIECE_SIZE);
                }
            } else {
                drawWhiteSquare(gw, x, y, SQUARE_SIZE);
                if (i > 4) {
                    drawBlackPiece(gw, x + PIECE_OFFSET, y + PIECE_OFFSET, PIECE_SIZE);

                }
            }
        }
    }
}

void drawGreySquare(GWindow & gw, int x, int y, double width) {
    gw.setColor("LIGHT_GRAY");
    gw.fillRect(x, y, width, width);
}

void drawWhiteSquare(GWindow & gw, int x, int y, double width) {
    gw.setColor("WHITE");
    gw.fillRect(x, y, width, width);
}

void drawRedPiece(GWindow & gw, int x, int y, double width) {
    gw.setColor("RED");
    gw.fillOval(x, y, width, width);
}

void drawBlackPiece(GWindow & gw, int x, int y, double width) {
    gw.setColor("BLACK");
    gw.fillOval(x, y, width, width);
}
