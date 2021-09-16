/*
 * Hand.h
 *
 *  Created on: Apr 20, 2021
 *      Author: nickm
 */

#ifndef HAND_H_
#define HAND_H_
#include "Card.h"
#include "GenericPlayer.h"
#include <string>
#include <vector>

class Hand : public GenericPlayer{
public:
	Hand();
	Hand(string playerName);
	string DisplayHand();
	string DisplayHandValue();
	bool GetAceBust();
	bool GetHasAce();
	int GetLargerValue();
	int GetSmallerValue();
	void AddCard(Card input);
	virtual ~Hand();
private:
	int handValue;
	int handValue2;
	int largerValue;
	int smallerValue;
	string hand;
	bool hasAce = false;
	bool aceBust = false;
	vector<Card> handVector;
};

#endif /* HAND_H_ */
