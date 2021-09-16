//============================================================================
// Name        : CS.cpp
// Author      : Nick Mule
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include "GenericPlayer.h"
#include "Deck.h"
#include "Game.h"
#include "Hand.h"
#include "Player.h"
#include "Card.h"
#include "House.h"
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	cout<<"Welcome to Blackjack!"<<endl;
	srand(time(0));
	Game newGame;
	Deck newDeck;
	newDeck.Shuffle();
	newGame.GetPlayers();
	newGame.FirstDeal();
	newGame.DisplayPlayersHands();
	newGame.AskPlayersToHit();
	newGame.HouseHit();
	newGame.AnnounceResults();

	return 0;
}
