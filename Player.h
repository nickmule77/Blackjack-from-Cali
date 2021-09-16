/*
 * Player.h
 *
 *  Created on: Apr 20, 2021
 *      Author: nickm
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "GenericPlayer.h"
#include <string>
#include "Card.h"
#include "Hand.h"
using namespace std;

class Player : public GenericPlayer {
public:
	Player();
	Player(string name);
	Hand GetPlayerHand();
	Hand* GetPlayerHandPointer();
	virtual ~Player();
private:
	Hand playerHand;
};

#endif /* PLAYER_H_ */
