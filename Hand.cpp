/*
 * Hand.cpp
 *
 *  Created on: Apr 20, 2021
 *      Author: nickm
 */

#include "Hand.h"

Hand::Hand()
{
}

Hand::Hand(string playerName) {
	// TODO Auto-generated constructor stub
	vector<Card> handVector;
	SetPlayerName(playerName);
	handValue = 0;
	handValue2 = 0;

}

void Hand::AddCard(Card input)
{
	string card;
	char first;
	handVector.push_back(input);
	card = input.DisplayValue();
	first = card[0];
	if (first  == 'A')
	{
		hasAce = true;
		handValue += 1;
		handValue += 11;
	}
	else
	{
		handValue += input.GetnValue();
	}
}

string Hand::DisplayHand(){
	Card temp;
	string answer;
	for (unsigned int i = 0; i < handVector.size(); i++)
	{
		temp = handVector.at(i);
		answer += temp.DisplayValue() + " ";
	}
	return answer;
}

string Hand::DisplayHandValue(){
	Card temp;
	int numAnswer;
	int numAnswer2=0;
	if (hasAce == false)
	{
		for (unsigned int i = 0; i < handVector.size(); i++)
		{
			temp = handVector.at(i);
			numAnswer += temp.GetnValue();
		}
		return to_string(numAnswer);
	}
	else
	{
		for (unsigned int i = 0; i < handVector.size(); i++)
		{
			temp = handVector.at(i);
			numAnswer += temp.GetnValue();
			if (temp.GetnValue2() == 0)
			{
				numAnswer2 += temp.GetnValue();
			}
			else
			{
				numAnswer2 += temp.GetnValue2();
			}
		}
		if (numAnswer > 21 and numAnswer2 > 21)
		{
			aceBust = true;
		}
		if (numAnswer > 16 and numAnswer < 21)
		{
			largerValue = numAnswer;
			smallerValue = numAnswer2;
		}
		if ((numAnswer2 > 16 and numAnswer2 < 21 ) and numAnswer2 > numAnswer)
		{
			largerValue = numAnswer2;
			smallerValue = numAnswer;
		}
		return to_string(numAnswer) + " or " + to_string(numAnswer2);
	}
}

bool Hand::GetAceBust(){
	return aceBust;
}

bool Hand::GetHasAce(){
	return hasAce;
}

int Hand::GetLargerValue(){
	return largerValue;
}

int Hand::GetSmallerValue(){
	return smallerValue;
}

Hand::~Hand() {
	// TODO Auto-generated destructor stub
}

