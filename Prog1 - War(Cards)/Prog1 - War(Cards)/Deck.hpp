// Deck.hpp

#ifndef Deck_hpp
#define Deck_hpp
#include <stdio.h>
#include "Card.hpp"

class Deck
{
    private:
        Card storage[52];
        int size;
    public:
        Deck();
        void display();
        Card deal();
        void shuffle();
        int cardsLeft();
        void reinitialize();
};

#endif /* Deck_hpp */
