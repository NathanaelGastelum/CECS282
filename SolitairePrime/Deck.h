// Nathanael Gastelum
// CECS 282-07
// Prog 1 - Solitaire Prime
// 2/12/2020

#ifndef Deck_h
#define Deck_h

#include "Card.h"

class Deck
{
private:

    Card deck[52];
	int cardsRemaining = 52;

public:

    Deck();

    void refreshDeck();
    Card deal();
    void shuffle();
    int cardsLeft();
    void showDeck();
};
#endif