// Deck.cpp

#include <iostream>
#include "Deck.hpp"
#include "Card.hpp"

using namespace std;

// Constructor
Deck::Deck()
{
    size = 52;
    char suits[4] = {'c','s','h','d'};
    
    for (int i = 0; i < 4; i++)    // 4 suits
    {
        for (int j = 1; j < 14; j++)   // 13 cards for each suit
        {
            storage[i*13 + (j-1)].setCard(suits[i], j);    // Set the card to a specific rank and suit
        }
    }
}

// Draws the cards in the deck
void Deck::display()
{
    for (int i = 0; i < size; i++)
    {
        storage[i].displayCard();
    }
}

// Deals a card from the deck and decrement the size variable
Card Deck::deal()
{
    size--;
    return storage[size];
}

// Returns the number of cards left to play
int Deck::cardsLeft()
{
    return size;
}

// Shuffles the deck of cards
void Deck::shuffle()
{
    int a,b;
    
    for (int i = 0; i < 100; i++)
    {
        // Random number from 1 to deck size
        a = rand()%size;
        b = rand()%size;
        
        Card c1;
        c1 = storage[a];            // Set the randomly selected card to a temporary Card variable
        storage[a] = storage[b];    // Now, Set the first randomly selected card to a second randomly selected card
        storage[b] = c1;            // Finally, Set the second randomly selected card as the temporary Card variable
    }
}

// Reset the deck of cards
void Deck::reinitialize()
{
    size = 52;
    char suits[4] = {'c','s','h','d'};
    
    for (int i = 0; i < 4; i++)    // 4 suits
    {
        for (int j = 1; j < 14; j++)   // 13 cards for each suit
        {
            storage[i*13 + (j-1)].setCard(suits[i], j);    // Set the card to a specific rank and suit
        }
    }
}