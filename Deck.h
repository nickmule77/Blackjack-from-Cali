/*
 * Deck.h
 *
 *  Created on: Apr 20, 2021
 *      Author: nickm
 */

#ifndef DECK_H_
#define DECK_H_

#include "Hand.h"
#include "Card.h"
#include <string>
#include <vector>

class Deck : public Hand {
public:
	void Shuffle();
	void Deal();
	void RemoveTopCard();
	void DealTopCard(Hand* playerHand);
	Card SeeTopCard();
	Deck();
	virtual ~Deck();
	vector<Card> GetDeck();
private:
	vector<Card> newDeck;
};

#endif /* DECK_H_ */
