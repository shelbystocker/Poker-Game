/* File: pokerhand.cpp
 * Course: CS216-002
 * Project: Project 2
 * Purpose: the implementation of member functions for the pokerhand class.
 * Author: Shelby Stocker
 */

#include "pokerhand.h" 
#include <iomanip>
#include <iostream>


// Default constructor.
// We allow a blank PokerHand to be created.
// However, the default constructor should make sure
// that hand_rank is (Rank::NoRank, 0).
PokerHand::PokerHand()
{
  for (int i = 0; i < FIVE; i++) 
  {
    cards[i].suit = Card::Invalid; // sets the suit to Invalid
    cards[i].point = 0; // sets the point to 0
  }  
  hand_rank.kind = Rank::NoRank; // sets kind to NoRank
  hand_rank.point = 0; // sets point to 0
} 

// It should store the FIVE cards
// given as parameters in the cards[] array.
// if size is not FIVE, display "Invalid number of cards!"
// It should also immediately evaluate the hand, determine
// its rank: ranking kind and the card value
void PokerHand::setPokerHand(Card in_hand[], int size)
{
  if (size != FIVE) // makes sure size is 5
    cout << "Invalid number of cards!" << endl;
  else {
    for (int i = 0; i<FIVE; i++) // sets cards to in_hand
    {
      cards[i].suit = in_hand[i].suit; 
      cards[i].point = in_hand[i].point;
    }
   sort(); // sorts the cards in descending order
   bool x;
   // checks what kind the hand is and replaces it if a better hand is found
   x = isHighCard();
   x = isPair();
   x = isThreeOfAKind();
   x = isStraight();
   x = isFlush();
   x = isFullHouse();
   x = isFourOfAKind();
   x = isStraightFlush();
  }
}

// Compare this hand versus otherHand according
// to the rules of poker. 
// Returns a negative number (< 0) 
// if this hand loses to the otherHand.
// Returns a positive number (> 0) 
// if this hand beats the otherHand.
// Returns zero if it's a tie.
// An invalid hand loses to any hand. If both hands
// are invalid, the result is undefined (could be
// negative, zero or positive).
//
int PokerHand::compareHand(const PokerHand &otherHand)
{
  if (otherHand.hand_rank.kind > hand_rank.kind)
    return -1; // if otherHand wins 
  else if (otherHand.hand_rank.kind < hand_rank.kind)
    return 1; // if this hand wins
  else if (otherHand.hand_rank.point > hand_rank.point)
    return -1; // if otherHand wins
  else if (otherHand.hand_rank.point < hand_rank.point)
    return 1; // if this hand wins
  else return 0; // if niether hand won
}

// Prints out the five cards and its rank to standard output.
// It should look like:
// Five cards:
// one card per line
// then followed by "Its rank is: rank"
void PokerHand::print()
{
  cout << "Five cards in order: " << endl;
  for (int i = 0; i < FIVE; i++) 
    cards[i].print(); // uses print from Card class
  hand_rank.print(); // uses print from Rank class
}

// Return the rank of this hand
Rank PokerHand::getRank() const
{
  return hand_rank;
}

// Returns true if the hand is a StraightFlush
// and set the hand_rank (StraightFlush, highest point of the sequential five cards)
// otherwise returns false
bool PokerHand::isStraightFlush()
{
  // checks if they are in order and all the same suit
  if ( isSequence() && isAllOneSuit() )
  {
    hand_rank.kind = Rank::StraightFlush; 
    hand_rank.point = cards[0].point;
    return true;
  }
  return false;
}

// Returns true if the hand is a Four of a Kind
// and set the hand_rank (FourOfAKind, highest point of the same four cards)
// otherwise returns false
bool PokerHand::isFourOfAKind()
{
  // checks to see if the first 4 cards are the same
  if (cards[0].point == cards[1].point && cards[1].point == cards[2].point && cards[2].point == cards[3].point && cards[3].point != cards[4].point)
  {
    hand_rank.kind = Rank::FourOfAKind;
    hand_rank.point = cards[0].point;
    return true;
  }
  // checks to see if the last 4 cards are the same
  else if (cards[1].point == cards[2].point && cards[2].point == cards[3].point && cards[3].point == cards[4].point && cards[4].point != cards[0].point)
  {
    hand_rank.kind = Rank::FourOfAKind;
    hand_rank.point = cards[4].point;
  }
  return false;
}

// Returns true if the hand is a Full House
// and set the hand_rank (FullHouse, highest point of the same three cards)
// otherwise returns false
bool PokerHand::isFullHouse()
{
  // checks to see if the first 3 cards and the last 2 cards are the same
  if (cards[0].point == cards[1].point && cards[1].point == cards[2].point && cards[2].point != cards[3].point && cards[3].point == cards[4].point)
  {
    hand_rank.kind = Rank::FullHouse;
    hand_rank.point = cards[0].point;
    return true;
  }  
  // checks to see if the first 2 cards and the last 3 cards are the same
  if (cards[0].point == cards[1].point && cards[1].point != cards[2].point && cards[2].point == cards[3].point && cards[3].point == cards[4].point)
  {
    hand_rank.kind = Rank::FullHouse;
    hand_rank.point = cards[4].point;
    return true;
  }  
  return false;
}

// Returns true if the hand is a Flush
// and set the hand_rank (Flush, highest point of the five cards)
// otherwise returns false
bool PokerHand::isFlush()
{
  // checks that they are all the same suit but not a sequence
  if (!(isSequence()) && isAllOneSuit() )
  {
    hand_rank.kind = Rank::Flush;
    hand_rank.point = cards[0].point;
    return true;
  }
  return false;
}

// Returns true if the hand is a Straight
// and set the hand_rank (Straight, highest point of the sequential five cards)
// otherwise returns false
bool PokerHand::isStraight()
{
  // checks that they are in sequence but not the same suit
  if (!(isAllOneSuit()) && isSequence() )
  {
    hand_rank.kind = Rank::Straight;
    hand_rank.point = cards[0].point;
    return true;
  }
  return false;
}  

// Returns true if the hand is a Three of a Kind
// and set the hand_rank (ThreeOfAKind, highest point of the same three cards)
// otherwise returns false
bool PokerHand::isThreeOfAKind()
{
  // checks if the first 3 are the same and dont equal the other 2
  if (cards[0].point == cards[1].point && cards[1].point  == cards[2].point && cards[2].point != cards[3].point && cards[3].point != cards[4].point)
  {
    hand_rank.kind = Rank::ThreeOfAKind;
    hand_rank.point = cards[0].point;
    return true;
  }
  // checks if the middle 3 are the same and dont equal the other 2
  if (cards[1].point == cards[2].point && cards[2].point == cards[3].point && cards[3].point != cards[4].point && cards[4].point != cards[0].point)
  {
    hand_rank.kind = Rank::ThreeOfAKind;
    hand_rank.point = cards[1].point;
    return true;
  }
  // checks if the last 3 are the same and dont equal the other 2
  if (cards[2].point == cards[3].point && cards[3].point == cards[4].point && cards[4].point != cards[1].point && cards[1].point != cards[0].point)
  {
    hand_rank.kind = Rank::ThreeOfAKind;
    hand_rank.point = cards[2].point;
    return true;
  }
  return false;
}

// Returns true if the hand is a Pair (we consider either one pair or two pairs is a Pair)
// and set the hand_rank (Pair, highest point of any pair)
// otherwise returns false
bool PokerHand::isPair()
{
  for (int i = 0; i < FIVE-1; i++)
  {
    // checks if the cards point equals the next cards point
    if (cards[i].point == cards[i+1].point)
    {
      hand_rank.kind = Rank::Pair;
      hand_rank.point = cards[i].point; 
      return true;
    } 
  }
  return false;
}

// Returns true if the hand is a High Card
// and set the hand_rank (High Card, highest point of the five cards)
// otherwise returns false
bool PokerHand::isHighCard()
{
  // does not check anything
  hand_rank.kind = Rank::HighCard;
  hand_rank.point = cards[0].point;
  return true;
}

// helper functions (private)
// they are helpful for the public member functions of this class
// however they cannot be called outside of the class
// to help sort the FIVE cards in decreasing order by card points
void PokerHand::sort()
{
  bool s = true; // creates a bool and makes it true
    int m = 0;
    Card temp;
    while (s) // checks that s is true
    {
      s = false; // sets s to false
      m++;
      for (int i = 0; i < FIVE-m; i++)
      {
        // compares 2 cards points and switches them
        if (cards[i].point < cards[i+1].point)
        {
          temp = cards[i];
	  cards[i] = cards[i+1];
	  cards[i+1] = temp;
	  s = true;
        }
      }
    }
}
	
// to help decide if FIVE cards are all of one suit
// return true if they are
// otherwise return false
bool PokerHand::isAllOneSuit()
{
  // checks if all the cards have the same suit
  if (cards[0].suit == cards[1].suit && cards[1].suit == cards[2].suit && cards[2].suit == cards[3].suit && cards[3].suit == cards[4].suit)
    return true;
  return false;
}

// to help decide if FIVE cards are in a continuous sequence
// return true if they are 
// otherwise return false
bool PokerHand::isSequence()
{
  for (int i = 0; i < FIVE-1; i++)
  {
    // checks if the cards point -1 equals the next cards point
    if (cards[i].point-1 != cards[i+1].point)
	return false;
  }
  return true;
}

