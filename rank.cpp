/* File: rank.cpp
 * Course: CS216-002
 * Project: Project 2
 * Purpose: the implementation of member functions for the Rank class.
 * Author: Shelby Stocker
 */

#include "rank.h"
#include <iomanip>

// Default constructor
Rank::Rank()
{
  kind = NoRank;
  point = 0;
}

// Alternate constructor.
// Create a Rank object with specified ranking name and points.
// The alternate constructor should make sure that
// the values of the arguments are valid.
// If invalid arguments are given, a Rank object should
// be created with NoRank for its ranking name and 0 for its points.
Rank::Rank(hRanks r, rPoints p)
{
  // checks to see if it has a rank
  if (r == HighCard || r == Pair || r == ThreeOfAKind || r == Straight || r == Flush || r == FullHouse || r == FourOfAKind || r == StraightFlush)
    kind = r;
  else 
    kind = NoRank; // sets kind to NoRank if it does not have a rank
  if (2 <= p <= 14) // checks if it has a valid point
    point = p;
  else 
    point = 1; // sets point to 1 if it doesnt have a valid point
}



// Display a description of the hand-ranking category to standard output.
// The output should look like:
//   StraightFlush( J)
//   FourOfAKind( 4)
//   FullHouse( K)
//   Flush( A)
//   ThreeOfAKind(10)
void Rank::print()
{
  cout << "Its rank is: ";
  // finds which kind is right and prints it
  switch (this->Rank::kind) {
    case NoRank: cout << "NoRank";
        break;
    case HighCard: cout << "HighCard";
        break;
    case Pair: cout << "Pair";
        break;
    case ThreeOfAKind: cout << "ThreeOfAKind";
        break;
    case Straight: cout << "Straight";
     break;
    case Flush: cout << "Flush";
        break;
    case FullHouse: cout << "FullHouse";
        break;
    case FourOfAKind: cout << "FourOfAKind";
        break;
    case StraightFlush: cout << "StraightFlush";
        break;
    }

   if (this->point < 11)
        cout << "( " << this->point << ")" << endl;
  // finds which point is right and prints it
  switch (this->point) {
    case 11: cout << "( J)" << endl;
        break;
    case 12: cout << "( Q)" << endl;
        break;
    case 13: cout << "( K)" << endl;
        break;
    case 14: cout << "( A)" << endl;
        break;
    }   
}
