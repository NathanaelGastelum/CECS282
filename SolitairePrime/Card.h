#ifndef Card_h
#define Card_h

class Card 
{
private:

public:
    Card();
    Card(char r, char s);

    void setCard(char r, char s);
    int getValue;
    void showCard();

};
#endif