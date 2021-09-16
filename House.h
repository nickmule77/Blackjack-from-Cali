/*
 * House.h
 *
 *  Created on: Apr 21, 2021
 *      Author: nickm
 */

#ifndef HOUSE_H_
#define HOUSE_H_
#include "Hand.h"
#include "Player.h"
#include <string>

class House : public Player{
public:
	House();
	string DisplayHouseHand();
	virtual ~House();
};

#endif /* HOUSE_H_ */
