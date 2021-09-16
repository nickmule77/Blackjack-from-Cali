/*
 * Card.cpp
 *
 *  Created on: Apr 20, 2021
 *      Author: nickm
 */

#include "Card.h"

Card::Card()
{
	cValue = "";
	suite = "";
	nValue = 0;
	nValue2 = 0;
}

Card::Card(string card, string insuite) {
	// TODO Auto-generated constructor stub
	cValue = card;
	suite = insuite;
	if (card == "J" or card == "Q" or card == "K")
	{
		isFace = true;
		nValue = 10;
		nValue2 = 0;
	}
	else if (card == "A")
	{
		isAce = true;
		nValue = 1;
		nValue2 = 11;
	}
	else
	{
		nValue = stoi(card);
		nValue2 = 0;
	}
}

void Card::SetSuite(string input){
	suite = input;
}

void Card::SetcValue(string input){
	cValue = input;
	if (input == "J" or input == "Q" or input == "K")
		{
			isFace = true;
			nValue = 10;
		}
		else if (input == "A")
		{
			isAce = true;
			nValue = 1;
			nValue2 = 11;
		}
		else
		{
			nValue = stoi(input);
		}
}

string Card::DisplayValue(){
	return cValue + suite;
}

int Card::GetnValue(){
	return nValue;
}

int Card::GetnValue2(){
	return nValue2;
}

Card::~Card() {
	// TODO Auto-generated destructor stub
}

