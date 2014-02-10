#ifndef _card_h
#define _card_h

#include <iostream>
#include <string>

const int ACE = 1;
const int JACK = 11;
const int QUEEN = 12;
const int KING = 13;

enum Suit { CLUBS, DIAMONDS, HEARTS, SPADES };

class Card {

public:

	Card();

	Card(std::string str);

	Card(int rk, Suit st);

	int getRank();

	Suit getSuit();

	std::string toString();

private:

	Suit suit;
	int rank;

};

/* Operator overloads */
std::ostream &operator<<(std::ostream &os, Card car);

#endif