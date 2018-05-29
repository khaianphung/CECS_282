// Card.hpp

#ifndef Card_hpp
#define Card_hpp
#include <stdio.h>

class Card
{
    public:
        Card();            
        Card (char s, int r );
        void setCard(char s, int r);
        int getRank();
        char getSuit();
        void displayCard();
        void printSuits(char s);
    private:
        char suit;
        int rank;
};

#endif /* Card_hpp */
