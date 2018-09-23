/*
 * Course: CS216-004
 * Project: Project 2
 * Purpose: to decide the best FIVE-card poker hand out of SEVEN cards according to poker hand ranking
 * the testing cases are created for the purpose of testing your definition of PokerHand class          
 */

#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <vector>
#include "pokerhand.h"
#include "deck.h"
#include "card.h"
#include "rank.h"

using namespace std;

// avoid magic numbers
const int SEVEN = 7;
const int FIVE = 5;
const int TWO = 2;

// decide the best five cards out of seven cards
// best means the highest ranking of five-card poker hand defined in the poker game
// pass in a vector of seven cards 
// (const call by reference: safe for the arugment and no copy is made for efficiency)
// return the best PokerHand object which represents the best five-card poker hand
PokerHand findBest(const vector<Card>& cards);

int main()
{
  Deck d; // creates a deck called d
  Card temp; // creates a card called temp
  string playAgain = " "; // used to see if user wants to play again
  vector<Card> myCards; // contains users cards
  vector<Card> compCards; // contains computers cards
  PokerHand myBest; // stores the users best hand
  PokerHand compBest; // stores the computers best hand

  
  while (playAgain != "Q")
  {
    d.createDeck();
    cout << "The cards in your hand are:" << endl;
    d.shuffleDeck(); // shuffles the deck d

    // deals user 2 cards
    for (int i = 0; i < TWO; i++)
    {
      temp = d.deal_a_card();
      temp.print(); // prints the dealt card 
      myCards.push_back(temp);
    }

    cout << '\n' << "The FIVE cards on the deck to share are:" << endl;
    cout << "********************" << endl;

    // deals 5 shared cards
    for (int j = 0; j < FIVE; j++)
    {
      temp = d.deal_a_card();
      myCards.push_back(temp);
      compCards.push_back(temp);
      temp.print(); // prints the dealt card
    }

    cout << '\n' << "********************" << endl;
    cout << "The cards in computer's hand are:" << endl;
 
   // deals the computer 2 cards
   for (int k = 0; k < TWO; k++)
    {
      temp = d.deal_a_card();
      compCards.push_back(temp);
      temp.print(); // prints the dealt card
    }

    cout << '\n' << "Player 1: You" << endl;
    myBest = findBest(myCards); // finds the users best 5 card hand
    cout << "Player 2: Computer" << endl;    
    compBest = findBest(compCards); // finds the computers best 5 card hand
   
    // compares the hands and decides on a winner
    if (myBest.compareHand(compBest) < 0)
      cout << "Sorry, the computer wins the game!" << endl << endl;
    else if (myBest.compareHand(compBest) > 0)
      cout << "Congratulations, you win the game!" << endl << endl;
    else
      cout << "It is a tie game!" << endl << endl;

    // removes the users and computers cards
    for (int s = 0; s < SEVEN; s++)
    {
      myCards.pop_back();
      compCards.pop_back();
    }  

    // asks if the user wants to play again
    cout << "Do you want to play poker game again (Press ""q"" or ""Q"" to quit the program)";
    getline(cin, playAgain); // gets user input
    if (playAgain == "q" || playAgain == "Q")
    {
      playAgain = "Q";
      cout << '\n' << "Thank you for using this program!" << endl;
    }
     cout << endl;
  } 
  return 0;
}


PokerHand findBest(const vector<Card>& cards)
{

    PokerHand bestH;
    PokerHand cardsH;

    // check if the parameter is valid
    if (cards.size() != SEVEN)
    {
        cout << "Invalid Cards, we need SEVEN cards!" << endl;
        return cardsH; // return a PokerHand object by default constructor
    }

    // Consider all possible ways of dropping two cards
    // from all seven cards 
    // i is the index of the first card dropped
    // and j is the index of the second card dropped.
    // There are 21 different ways to pick 5 cards out of 7
    for (int i=0; i < SEVEN; i++)
    {
        for (int j=i+1; j < SEVEN; j++)
        {
            Card pick[FIVE];
            int index = 0;

            // Iterate over all seven cards and assign them to the pick[] array
            // exclude cards with index numbers of #i and #j.
            for (int k=0 ; k < SEVEN ; k++)
            {
                if (k == i || k == j)
                    continue;
                pick[index] = cards[k];
                index++;
            }

            // create a PokerHand with pick[]
            cardsH.setPokerHand(pick, FIVE); 

            // Check to see if current pick is better than
            // the best you have seen so far
            if (bestH.compareHand(cardsH) < 0)
            {
                bestH = cardsH ;
            }
        }
    }

    // Now bestH holds the best poker hand among all 21 poker hands
    cout << "*** Best five-card hand ***" << endl;
    bestH.print();
    cout << endl << endl;
    return bestH;
}






