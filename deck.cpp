/* File: deck.cpp
 * Course: CS216-00x
 * Project: Lab 8 (as part of Project 2)
 * Purpose: the implementation of member functions for the Deck class.
 *
 */

#include <cstdlib>
#include <ctime>
#include "deck.h"
        
// create a standard 52-card deck
void Deck::createDeck()
{   
    // counts through the suits
    for (int s= Card::Spade; s <= SUITS; s++)
    {
        // counts through the points
        for (Card::cPoints val = CARD_START; val < RANKS + CARD_START; val++)
        {
            Card::cSuits suit = static_cast<Card::cSuits>(s);
            Card newcard(suit, val);
            deck.push_back(newcard); // adds the new card to the deck
        }
    }

}

// shuffle the cards in 52-card deck
void Deck::shuffleDeck()
{
srand(time(0));
    Card temp;  // for swapping
    for (int i = deck.size()-1; i>= 1; i--)
    {
        int j = rand() % (i+1); // generates a random number
        temp = deck[j];
        deck[j] = deck[i];
        deck[i] = temp;
    }

}

// return a card from the tail of the deck
Card Deck::deal_a_card()
{
    Card* last;
    last = &deck[deck.size()-1];
    deck.pop_back(); // gets rid of the last card
    return *last;
}
