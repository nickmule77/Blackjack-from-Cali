/*
 * Game.h
 *
 *  Created on: Apr 20, 2021
 *      Author: nickm
 */

#ifndef GAME_H_
#define GAME_H_

#include <iostream>
#include <string>
#include "GenericPlayer.h"
#include "Deck.h"
#include "Game.h"
#include "Hand.h"
#include "Player.h"
#include "Card.h"
#include "House.h"

class Game {
public:
	Game();
	void GetPlayers();
	void FirstDeal();
	void DisplayPlayersHands();
	void AskPlayersToHit();
	void HouseHit();
	void AnnounceResults();
	virtual ~Game();
private:
	vector<Player> playerList;
	Deck gameDeck;
	House gameHouse;
	bool bustedHouse = false;
	int houseValue = 0;
};

#endif /* GAME_H_ */
