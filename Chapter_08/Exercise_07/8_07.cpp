#include <iostream>
#include "vector.h"
#include "card.h"

using namespace std;

int countFifteens(Vector<Card> &cards);
int calculateFifteens(Vector<Card> cards, int total);

int main(int argc, char* argv[]) {
	Card a(ACE, DIAMONDS), b(5, SPADES), c(10, SPADES), d(4, HEARTS), e(9, CLUBS);
	Vector<Card> cards;
	cards += a, b, c, d, e;
	cout << cards << endl;
	cout << "Total fifteens: " << countFifteens(cards) << endl;

	Card f(5, CLUBS), g(5, DIAMONDS), h(5, HEARTS), i(5, SPADES), j(JACK, CLUBS);
	cards.clear();
	cards += f, g, h, i, j;
	cout << cards << endl;
	cout << "Total fifteens: " << countFifteens(cards) << endl;
	return 0;
}

int countFifteens(Vector<Card> &cards) {
	int total = 0;
	return calculateFifteens(cards, total);
}

int calculateFifteens(Vector<Card> cards, int total) {
	if (cards.isEmpty() && total != 15) {
		return 0;
	} else if (cards.isEmpty() && total == 15) {
		return 1;
	} else {
		int element = cards[0].getRank();
		if (element > 10) { // to follow rules of Cribbage face cards are worth 10.
			element = 10;
		}
		Vector<Card> rest = cards;
		rest.remove(0);
		total += element;
		int count = total / 15;
		return calculateFifteens(rest, total) + calculateFifteens(rest, total - element);
	}
}