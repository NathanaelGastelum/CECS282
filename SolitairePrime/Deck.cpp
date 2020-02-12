// Nathanael Gastelum
// CECS 282-07
// Prog 1 - Solitaire Prime
// 2/12/2020

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
	cardsRemaining = 52;

	char suit[] = { 'S','C','H','D' };
	char rank[] = { 'A','2','3','4','5','6','7','8','9','T','J','Q','K' };

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

Card Deck::deal()
{
	Card topCard = deck[52-cardsRemaining];
	cardsRemaining--;
	return topCard;
}

void Deck::shuffle()
{
	// swap card x and card y 10,000 times
	srand(time(0));
	for (int i = 0; i < 10000; i++)
	{
		int x = rand()%52;
		int y = rand()%52;

		Card c = deck[x];
		deck[x] = deck[y];
		deck[y] = c;
	}
}

int Deck::cardsLeft()
{
	return cardsRemaining;
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