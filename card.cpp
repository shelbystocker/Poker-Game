/* File: card.h
 * Course: CS216-00x
 * Project: Lab 7
 * Purpose: the implementation of member functions for the Card class.
 * Author: Shelby Stocker
 */

#include "card.h"


// Default constructor marks card as invalid
Card::Card() 
{
 suit = Invalid;
 point = 0; 
}

// Alternate constructor
Card::Card(cSuits s, cPoints p) 
{
 suit = s;
 point = p;
}

// compare with another Card object passed in as parameter: other
// if the object your are working on has higher point than other, return 1;
// if the object your are working on has lower point than other, return -1;
// otherwise, return 0
int Card::compareTo(Card other)
{
  if (point > other.point) // compares the 2 points
	return 1;
  if (point < other.point)
	return -1;
  return 0; // returns 0 if one point is not higher
}

// Display a description of the Card object to standard output
// The output should look like:
//   
void Card::print() 
{ 
  if (point == 11) // checks if the point is a J
  {
  if (suit == Spade)
	cout << SPADE << " J" << SPADE << endl;
  else if (suit == Club)
	cout << CLUB << " J" << CLUB << endl;
  else if (suit == Heart)
	cout << HEART << " J" << HEART << endl;
  else  if (suit == Diamond) 
	cout << DIAMOND << " J" << DIAMOND << endl;
  } 
  if (point == 12) // checks if the point is a Q
  {
  if (suit == Spade)
        cout << SPADE << " Q" << SPADE << endl;
  else if (suit == Club)
        cout << CLUB << " Q" << CLUB << endl;
  else if (suit == Heart)
        cout << HEART << " Q" << HEART << endl;
  else  if (suit == Diamond)
        cout << DIAMOND << " Q" << DIAMOND << endl;
  }
  if (point == 13) // checks if the point is a K
  {
  if (suit == Spade)
        cout << SPADE << " K" << SPADE << endl;
  else if (suit == Club)
        cout << CLUB << " K" << CLUB << endl;
  else if (suit == Heart)
        cout << HEART << " K" << HEART << endl;
  else  if (suit == Diamond)
        cout << DIAMOND << " K" << DIAMOND << endl;
  }
 if (point == 14) // checks if the point is an A
  {
  if (suit == Spade)
        cout << SPADE << " A" << SPADE << endl;
  else if (suit == Club)
        cout << CLUB << " A" << CLUB << endl;
  else if (suit == Heart)
        cout << HEART << " A" << HEART << endl;
  else  if (suit == Diamond)
        cout << DIAMOND << " A" << DIAMOND << endl;
  }
 if (point <  11) // checks if the point is not a face card
  {
  if (suit == Spade)
        cout << SPADE << " " << point << SPADE << endl;
  else if (suit == Club)
        cout << CLUB << " " << point  << CLUB << endl;
  else if (suit == Heart)
        cout << HEART << " " << point << HEART << endl;
  else  if (suit == Diamond)
        cout << DIAMOND << " " << point << DIAMOND << endl;
  }

}
