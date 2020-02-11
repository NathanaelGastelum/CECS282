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
	return 0;
}

void Card::showCard()
{
	cout << rank << suit << ' ';
}
