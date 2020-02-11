#ifndef Card_h
#define Card_h

class Card 
{
private:

	char rank;
	char suit;

public:

    Card();
    Card(char r, char s);

    void setCard(char r, char s);
    int getValue();
    void showCard();

};
#endif