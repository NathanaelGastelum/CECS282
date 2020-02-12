#include "Card.h"
#include <iostream>

using namespace std;

Card::Card()
{
	// TODO why doesn't this work? Card's get random values instead of 'zz'
	Card('z', 'z');
}

Card::Card(char r, char s)
{
	rank = r;
	suit = s;
}

void Card::setCard(char r, char s)
{
	rank = r;
	suit = s;
}

int Card::getValue()
{
	int value;
	switch (rank)
	{
	case 'A':
		value = 1;
		break;
	case 'J':
		value = 10;
		break;
	case 'Q':
		value = 10;
		break;
	case 'K':
		value = 10;
		break;
	default:
		value = rank - '0';
		break;
	}
	return value;
}

void Card::showCard()
{
	cout << rank << suit << ' ';
}
