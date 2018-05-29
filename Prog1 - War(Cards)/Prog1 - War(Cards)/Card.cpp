// Card.cpp

#include <iostream>
#include "Deck.hpp"
#include "Card.hpp"

using namespace std;

// Constructor
Card::Card()
{
    suit = ' ';
    rank = 0;;
}

// Constructor - Receieves a rank and suit
Card::Card(char s, int r)
{
    suit = s;
    rank = r;
}

// Setter - Sets the card to specific rank and suit
void Card::setCard(char s, int r)
{
    suit = s;
    rank = r;
}

// Getter - Returns the rank of the card
int Card::getRank()
{
    return rank;
}

// Getter - Returns the suit of the card
char Card::getSuit()
{
    return suit;
}

// Draws the middle of the card which contains the suit
void Card::printSuits(char s)
{
    if (s == 'c')
    {
        cout << "[   *   ]" << endl;
        cout << "[*  *  *]" << endl;
        cout << "[ * * * ]" << endl;
        cout << "[   *   ]" << endl;
        cout << "[   *   ]" << endl;
    }
    else if (s == 'd')
    {
        cout << "[       ]" << endl;
        cout << "[  * *  ]" << endl;
        cout << "[ *   * ]" << endl;
        cout << "[  * *  ]" << endl;
        cout << "[       ]" << endl;
    }
    else if (s == 'h')
    {
        cout << "[ ** ** ]" << endl;
        cout << "[*  *  *]" << endl;
        cout << "[ *   * ]" << endl;
        cout << "[  * *  ]" << endl;
        cout << "[   *   ]" << endl;
    }
    else if (s == 's')
    {
        cout << "[   *   ]" << endl;
        cout << "[  * *  ]" << endl;
        cout << "[ ***** ]" << endl;
        cout << "[*  *  *]" << endl;
        cout << "[   *   ]" << endl;
    }

}

// Draws the top and bottom portions of the card
void Card::displayCard()
{
        if (rank < 10 && rank != 1)     // If rank is 2,3,4,5,6,7,8, or 9
        {
            cout << " ------- " << endl;
            cout << "[" << rank << "      ]" << endl;
            if (suit == 'c')
            {
                printSuits('c');
            }
            else if (suit == 'd')
            {
                printSuits('d');
            }
            else if (suit == 'h')
            {
                printSuits('h');
            }
            else if (suit == 's')
            {
                printSuits('s');
            }
            cout << "[      " << rank << "]" << endl;
            cout << " ------- " << endl;
        }
        else if (rank == 10)    // If rank is 10
        {
            cout << " ------- " << endl;
            cout << "[" << rank << "     ]" << endl;
            if (suit == 'c')
            {
                printSuits('c');
            }
            else if (suit == 'd')
            {
                printSuits('d');
            }
            else if (suit == 'h')
            {
                printSuits('h');
            }
            else if (suit == 's')
            {
                printSuits('s');
            }
            cout << "[     " << rank << "]" << endl;
            cout << " ------- " << endl;
        }
        else if (rank > 10 || rank == 1)    // If rank is 1 (Ace), 11 (Jack), 12 (Queen), or 13 (King)
        {
            cout << " ------- " << endl;
            if (rank == 1)      // If rank is 1 --> Ace
            {
                cout << "[A      ]" << endl;
                if (suit == 'c')
                {
                    printSuits('c');
                }
                else if (suit == 'd')
                {
                    printSuits('d');
                }
                else if (suit == 'h')
                {
                    printSuits('h');
                }
                else if (suit == 's')
                {
                    printSuits('s');
                }
                cout << "[      A]" << endl;
            }
            else if (rank == 11)        // If rank is 11 --> Jack
            {
                cout << "[J      ]" << endl;
                if (suit == 'c')
                {
                    printSuits('c');
                }
                else if (suit == 'd')
                {
                    printSuits('d');
                }
                else if (suit == 'h')
                {
                    printSuits('h');
                }
                else if (suit == 's')
                {
                    printSuits('s');
                }
                cout << "[      J]" << endl;
            }
            else if (rank == 12)        // If rank is 12 --> Queen
            {
                cout << "[Q      ]" << endl;
                if (suit == 'c')
                {
                    printSuits('c');
                }
                else if (suit == 'd')
                {
                    printSuits('d');
                }
                else if (suit == 'h')
                {
                    printSuits('h');
                }
                else if (suit == 's')
                {
                    printSuits('s');
                }
                cout << "[      Q]" << endl;

            }
            else if (rank == 13)        // If rank is 13 --> King
            {
                cout << "[K      ]" << endl;
                if (suit == 'c')
                {
                    printSuits('c');
                }
                else if (suit == 'd')
                {
                    printSuits('d');
                }
                else if (suit == 'h')
                {
                    printSuits('h');
                }
                else if (suit == 's')
                {
                    printSuits('s');
                }
                cout << "[      K]" << endl;
            }
            cout << " ------- " << endl;
        }
}

