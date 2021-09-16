/*
 * GenericPlayer.h
 *
 *  Created on: Apr 20, 2021
 *      Author: nickm
 */
#include <string>
#include "Card.h"
#ifndef GENERICPLAYER_H_
#define GENERICPLAYER_H_

using namespace std;

class GenericPlayer {
public:
	//GenericPlayer();
	virtual void SetPlayerName(string input);
	virtual ~GenericPlayer();
	string GetPlayerName();
private:
	std::string name;
};

#endif /* GENERICPLAYER_H_ */
