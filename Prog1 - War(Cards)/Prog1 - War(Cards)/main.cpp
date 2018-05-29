//  Kyle Pamintuan
//  CECS 282 - Section 05
//  Prog1 - War(Cards)
//  Due Date:     September 13, 2016
//  Turn-In Date: September 13, 2016

// main.cpp

#include <iostream>
#include "Deck.hpp"
#include "Card.hpp"

using namespace std;

string stringFunction(char s, int r)    // This function prints the cards in plain english
{
    string words[4] = {"Ace", "Jack", "Queen", "King"};
    string moreWords[4] = {" of Clubs", " of Diamonds", " of Hearts", " of Spades"};
    string newString;
    
    if (r == 1)     // If rank equals 1 --> Ace
    {
        // Suits
        if (s == 'c')
            newString = words[0] + moreWords[0];
        else if (s == 'd')
            newString = words[0] + moreWords[1];
        else if (s == 'h')
            newString = words[0] + moreWords[2];
        else if (s == 's')
            newString = words[0] + moreWords[3];
        
        return newString;
    }
    else if (r == 11)       // If rank equals 12 --> Jack
    {
        // Suits
        if (s == 'c')
            newString = words[1] + moreWords[0];
        else if (s == 'd')
            newString = words[1] + moreWords[1];
        else if (s == 'h')
            newString = words[1] + moreWords[2];
        else if (s == 's')
            newString = words[1] + moreWords[3];
        
        return newString;
    }
    else if (r == 12)       // If rank equals 12 --> Queen
    {
        //Suits
        if (s == 'c')
            newString = words[2] + moreWords[0];
        else if (s == 'd')
            newString = words[2] + moreWords[1];
        else if (s == 'h')
            newString = words[2] + moreWords[2];
        else if (s == 's')
            newString = words[2] + moreWords[3];
        
        return newString;
    }
    else if (r == 13)       // If rank equals 13 --> King
    {
        // Suits
        if (s == 'c')
            newString = words[3] + moreWords[0];
        else if (s == 'd')
            newString = words[3] + moreWords[1];
        else if (s == 'h')
            newString = words[3] + moreWords[2];
        else if (s == 's')
            newString = words[3] + moreWords[3];
        
        return newString;
    }
    else                // If rank equals 2,3,4,5,6,7,8, or 9
    {
        // Suits
        if (s == 'c')
            newString = to_string(r) + moreWords[0];
        else if (s == 'd')
            newString = to_string(r) + moreWords[1];
        else if (s == 'h')
            newString = to_string(r) + moreWords[2];
        else if (s == 's')
            newString = to_string(r) + moreWords[3];
        
        return newString;
    }

}

int main(int argc, const char * argv[])
{
    //  Create a deck of cards
    Deck cardDeck;
    
    bool toggle2 = true;
    while (toggle2)     // While user still wants to have the program running
    {
        // Menu and user input
        cout << "============== WAR ==============" << endl;
        cout << endl;
        cout << endl;
        cout << "Menu" << endl;
        cout << "1) Get a new card deck" << endl;
        cout << "2) Show all remaining cards in the deck" << endl;
        cout << "3) Shuffle" << endl;
        cout << "4) Play WAR!" << endl;
        cout << "5) Exit" << endl;
        int selection;
        cin >> selection;
        
        if (selection == 1)     // If user chooses menu option 1
        {
            // Create a new deck of cards and draw all cards
            cardDeck.reinitialize();
            cardDeck.display();
            cout << endl;
        }
        else if (selection == 2)    // If user chooses menu option 2
        {
            // Print the number of cards left and draw the them
            cout << "There are " << cardDeck.cardsLeft() << " cards left" << endl;
            cout << endl;
            cardDeck.display();
            cout << endl;
        }
        else if (selection == 3)    // If user chooses menu option 3
        {
            // Shuffle current deck and draw all cards
            cardDeck.shuffle();
            cout << "There are " << cardDeck.cardsLeft() << " cards left" << endl;
            cout << endl;
            cardDeck.display();
            cout << endl;
        }
        else if (selection == 4)    // If user chooses menu option 4
        {
            // PLAY WAR!
            cout << "GET READY TO PLAY WAR!" << endl;
            cout << endl;
            
            // Shuffle deck
            cardDeck.shuffle();
            
            bool toggle = true;
            while (toggle)      // While user still wants to play
            {
                // Prints the number of cards left in the deck
                cout << endl;
                cout << "There are " << cardDeck.cardsLeft() << " cards in the deck." << endl;
                cout << "...dealing..." << endl;
                
                // Deals player 1 card
                Card c1 = cardDeck.deal();
                cout << endl;
                cout << "One for you..." << endl;
                
                // Prints player 1 card in plain english & draws the card
                cout << stringFunction(c1.getSuit(), c1.getRank()) << endl;
                c1.displayCard();
                cout << endl;
                
                // Deals player 2 card
                Card c2 = cardDeck.deal();
                cout << endl;
                cout << "One for me..." << endl;
                
                // Prints player 2 card in plain english & draws the card
                cout << stringFunction(c2.getSuit(), c2.getRank()) << endl;
                c2.displayCard();
                cout << endl;
                
                // Compare card ranks and announce winner or tie game
                if (c1.getRank() == 1 || (c1.getRank() > 1 && c1.getRank() > c2.getRank()))
                    cout << "You Win!!!" << endl;
                else if (c2.getRank() == 1 || (c2.getRank() > 1 && c2.getRank() > c1.getRank()))
                    cout << "I Win!!!" << endl;
                else
                    cout << "Tie Game" << endl;
                cout << endl;

                // See if user still wants to play
                cout << "Wanna play again? (yes or no)" << endl;
                string userInput;
                cin >> userInput;
                
                if (userInput.compare("no") == 0 || cardDeck.cardsLeft() <= 0)    // If 'no' OR 0 cards left to play, end game and go back to menu
                {
                    cout << endl;
                    cout << "Game Over" << endl;
                    toggle = false;
                }
                else if (userInput.compare("yes") == 1 && userInput.compare("no") == 1)  // If user does not type in 'yes' or 'no', end game
                {
                    cout << endl;
                    cout << "Wrong Input" << endl;
                    toggle = false;
                }
            }
            cout << endl;
        }
        else if (selection == 5)    // If user chooses menu option 5
        {
            // Say farewell and end the program
            cout << endl;
            cout << "Goodbye"<< endl;
            toggle2 = false;
        }
        else                       // Otherwise
        {
            // End program
            toggle2 = false;
        }

    }
}
