/*
 * GenericPlayer.cpp
 *
 *  Created on: Apr 20, 2021
 *      Author: nickm
 */

#include "GenericPlayer.h"
#include <string>
using namespace std;
//GenericPlayer::GenericPlayer() {
	// TODO Auto-generated constructor stub

//}

void GenericPlayer::SetPlayerName(string input)
{
	name = input;
}

string GenericPlayer::GetPlayerName()
{
	return name;
}

GenericPlayer::~GenericPlayer() {
	// TODO Auto-generated destructor stub
}

