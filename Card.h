/*
 * Card.h
 *
 *  Created on: Apr 20, 2021
 *      Author: nickm
 */

#ifndef CARD_H_
#define CARD_H_
#include <string>
using namespace std;

class Card {
public:
	void SetcValue(string input);
	void SetSuite(string input);
	void Flip();
	string DisplayValue();
	int GetnValue();
	int GetnValue2();
	Card();
	Card(string card, string insuite);
	virtual ~Card();
private:
	string cValue;
	int nValue;
	int nValue2;
	string suite;
	bool isFace = false;
	bool isAce = false;
	bool faceDown = true;
};

#endif /* CARD_H_ */
