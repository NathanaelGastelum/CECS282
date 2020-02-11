#ifndef Deck_h
#define Deck_h

#include "Card.h"

class Deck
{
private:

    Card deck[52];

public:

    Deck();

    void refreshDeck();
    Card deal();
    void shuffle();
    int cardsRemaining();
    void showDeck();
};
#endif