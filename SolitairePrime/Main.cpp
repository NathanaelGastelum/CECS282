// Nathanael Gastelum
// CECS 282-07
// Prog 1 - Solitaire Prime
// 2/12/2020

#include "Deck.h"
#include "Card.h"
#include <iostream>

using namespace std;

void gameLoop(Deck deck);
void play(Deck deck);
bool isPrime(int num);

int main() 
{
	Deck deck;

	gameLoop(deck);

    return 0;
}

void gameLoop(Deck deck) {
	
	cout << "\nWelcome to Solitaire Prime!\n"
		<< "1) New Deck\n"
		<< "2) Display Deck\n"
		<< "3) Shuffle Deck\n"
		<< "4) Play Solitaire Prime\n"
		<< "5) Exit\n";

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
		deck.shuffle();
		break;
	case 4:
		play(deck);
		break;
	case 5:
		exit(0);

	default:
		cout << "Invalid input";
		break;
	}

	gameLoop(deck);
}

void play(Deck deck) {
	
	cout << "\nPlaying Solitaire Prime!\n\n";
	
	Card hand[52];

	int pileCount = 0;
	int sum = 0;

	for (int i = 0; i < 52; i++)
	{
		hand[i] = deck.deal();
		hand[i].showCard();

		sum = sum + hand[i].getValue();

		if (isPrime(sum))
		{
			cout << "Prime: " << sum;
			cout << '\n';
			pileCount++;

			if (deck.cardsLeft() == 0) {
				cout << "\nWinner in " << pileCount << " piles!\n";
				return;
			}

			sum = 0;
			i = 0;
		}
		if (deck.cardsLeft() == 0) {
			cout << "\n\nLoser after " << pileCount << " piles :(\n";
			return;
		}
	}
}

bool isPrime(int num) {
	if (num <= 1)
	{
		return false;
	}

	for (int i = 2; i < num; i++)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	return true;
}