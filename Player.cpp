/*
 * Player.cpp
 *
 *  Created on: Apr 20, 2021
 *      Author: nickm
 */

#include "Player.h"
#include <string>

using namespace std;

Player::Player() {
	// TODO Auto-generated constructor stub

}

Player::Player(string name){
	SetPlayerName(name);
	Hand playerHand;
}

Hand Player::GetPlayerHand()
{
	return playerHand;
}

Hand* Player::GetPlayerHandPointer()
{
	return &playerHand;
}
Player::~Player() {
	// TODO Auto-generated destructor stub
}

