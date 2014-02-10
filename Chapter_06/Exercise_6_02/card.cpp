#include <iostream>
#include <string>
#include "strlib.h"
#include "card.h"

using namespace std;

/* Function Prototypes */
string suitToString(Suit st);


/* Constructors */
Card::Card() {
	/* Empty */
}

Card::Card(string str) {
	/* TO DO */
}

Card::Card(int rk, Suit st) {
	rank = rk;
	suit = st;
}

/* Methods */
int Card::getRank() {
	return rank;
}

Suit Card::getSuit() {
	return suit;
}

string Card::toString() {
	switch (rank) {
		case 1: return "A" + suitToString(suit);
		case 11: return "J" + suitToString(suit);
		case 12: return "Q" + suitToString(suit);
		case 13: return "K" + suitToString(suit);
		default: return integerToString(rank) + suitToString(suit);
 	}
	
}

/* Operator overloads */
ostream &operator<<(ostream &os, Card car) {
	return os << car.toString();
}

/* Helper Functions */
string suitToString(Suit st) {
	switch (st) {
		case CLUBS: return "C";
		case DIAMONDS: return "D";
		case HEARTS: return "H";
		case SPADES: return "S";
		default: return "?";
	}
}
