#include "Card.h"
#include <iostream>

using namespace std;

Card::Card()
{
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
	cout << rank << suit << "\n";
}
