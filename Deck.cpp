/*
 * Deck.cpp
 *
 *  Created on: Apr 20, 2021
 *      Author: nickm
 */

#include "Deck.h"
#include <iostream>
#include <algorithm>
using namespace std;

Deck::Deck() {
	// TODO Auto-generated constructor stub
	//std::vector<Card> newDeck;
	for (int i = 1; i < 10; i++)
	{
		string temp = to_string(i);
		newDeck.push_back(Card(temp, "D"));
	}
	newDeck.push_back(Card("J", "D"));
	newDeck.push_back(Card("Q", "D"));
	newDeck.push_back(Card("K", "D"));
	newDeck.push_back(Card("A", "D"));

	for (int i = 1; i < 10; i++)
	{
		string temp = to_string(i);
		newDeck.push_back(Card(temp, "H"));
	}
	newDeck.push_back(Card("J", "H"));
	newDeck.push_back(Card("Q", "H"));
	newDeck.push_back(Card("K", "H"));
	newDeck.push_back(Card("A", "H"));

	for (int i = 1; i < 10; i++)
	{
		string temp = to_string(i);
		newDeck.push_back(Card(temp, "S"));
	}
	newDeck.push_back(Card("J", "S"));
	newDeck.push_back(Card("Q", "S"));
	newDeck.push_back(Card("K", "S"));
	newDeck.push_back(Card("A", "S"));

	for (int i = 1; i < 10; i++)
	{
		string temp = to_string(i);
		newDeck.push_back(Card(temp, "C"));
	}
	newDeck.push_back(Card("J", "C"));
	newDeck.push_back(Card("Q", "C"));
	newDeck.push_back(Card("K", "C"));
	newDeck.push_back(Card("A", "C"));

}

void Deck::Shuffle()
{
	random_shuffle( newDeck.begin(), newDeck.end());
}

void Deck::RemoveTopCard()
{
	newDeck.erase(newDeck.begin());
}

void Deck::DealTopCard(Hand* playerHand)
{
	Card temp;
	temp = newDeck.at(0);
	//cout<<temp.DisplayValue();
	playerHand->AddCard(temp);
	RemoveTopCard();
	//cout<<playerHand->DisplayHand();
}

Card Deck::SeeTopCard()
{
	Card temp = newDeck.at(0);
	return temp;
}

vector<Card> Deck::GetDeck()
{
	return newDeck;
}

Deck::~Deck() {
	// TODO Auto-generated destructor stub
}

