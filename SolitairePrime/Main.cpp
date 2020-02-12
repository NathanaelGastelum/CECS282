#include "Deck.h"
#include "Card.h"
#include <iostream>

using namespace std;

void gameLoop(Deck deck);

int main() 
{
	cout << "Welcome to Solitaire Prime!\n"
		<< "1) New Deck\n"
		<< "2) Display Deck\n"
		<< "3) Shuffle Deck\n"
		<< "4) Play Solitaire Prime\n"
		<< "5) Exit\n";

	Deck deck;

	gameLoop(deck);

    return 0;
}

void gameLoop(Deck deck) {
	
	int i;
	cin >> i;

	switch (i)
	{
	case 1:
		deck.refreshDeck();
		break;
	case 2:
		deck.showDeck();
		break;
	case 3:
		/* code */
		break;
	case 4:
		/* code */
		break;
	case 5:
		exit(0);

	default:
		cout << "Invalid input";
		break;
	}

	gameLoop(deck);
}