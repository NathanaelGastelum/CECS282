#include "Deck.h"
#include "Card.h"
#include <iostream>

using namespace std;

int Main() 
{
	Card test;
	test.showCard();
    int i;
    cout << "Welcome to Solitaire Prime!\n"
         << "1) New Deck\n"
         << "2) Display Deck\n"
         << "3) Shuffle Deck\n"
         << "4) Play Solitaire Prime\n"
         << "5) Exit\n";
    cin >> i;

    switch (i)
    {
    case 1:
        /* code */
        break;
    case 2:
        /* code */
        break;
    case 3:
        /* code */
        break;
    case 4:
        /* code */
        break;
    case 5:
        /* code */
        break;
    
    default:
        cout << "Invalid input";
        break;
    }

    return 0;
}