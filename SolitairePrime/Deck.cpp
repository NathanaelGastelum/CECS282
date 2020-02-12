#include "Deck.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

Deck::Deck()
{
	char suit[] = { 'S','C','H','D' };
	char rank[] = { 'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
	
	int c = 0;
	for (int s = 0; s < 4; s++)
	{
		for (int i = 0; i < 13; i++)
		{
			deck[c].setCard(rank[i], suit[s]);
			c++;
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

int Deck::cardsRemaining()
{
	return 0;
}

void Deck::showDeck()
{
	for (int i = 0; i < 52; i++)
	{
		deck[i].showCard();
		cout << ' ';

		if ((i + 1) % 13 == 0)
		{
			cout << '\n';
		}
	}
	cout << '\n';
}