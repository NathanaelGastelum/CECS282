#ifndef Deck_h
#define Deck_h

#include "Card.h"

class Deck
{
private:
    /* data */
public:
    Deck(/* args */);

    void refreshDeck();
    Card deal();
    void shuffle();
    int cardsRemaining;
    void showDeck();
};
#endif