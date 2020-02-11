#include "Deck.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

Deck::Deck()
{
	for (int s = 0; s < 4; s++)
	{
		char suit;
		switch (s)
		{
		case 0:
			suit = 'S';
			break;
		case 1:
			suit = 'C';
			break;
		case 2:
			suit = 'H';
			break;
		case 3:
			suit = 'D';
			break;
		}

		for (int i = 1; i < 14; i++)
		{
			switch (i)
			{
				case 1:
					deck[i].setCard('A', suit);
					break;
				case 10:
					deck[i].setCard('T', suit);
					break;
				case 11:
					deck[i].setCard('J', suit);
					break;
				case 12:
					deck[i].setCard('Q', suit);
					break;
				case 13:
					deck[i].setCard('K', suit);
					break;
				default:
					deck[i].setCard(i, suit); 
					break;
			}
		}
	}
	
}

void Deck::refreshDeck()
{
	//TODO test this
	Deck();
}

Card Deck::deal()
{
	int i = 0;
	Card topCard = deck[i];
	i++;
	return topCard;
}

void Deck::shuffle()
{
	srand(time(0));
	for (int i = 0; i < 10000; i++)
	{
		int x = rand()%52;
		int y = rand()%52;

	}

	// swap card x and card y 10,000 times

}

void Deck::showDeck()
{
	for (int i = 0; i < 52; i++)
	{
		deck[i].showCard();

		if (i % 13 == 0)
		{
			cout << '\n';
		}
	}
}