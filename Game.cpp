/*
 * Game.cpp
 *
 *  Created on: Apr 20, 2021
 *      Author: nickm
 */

#include "Game.h"

Game::Game() {
	// TODO Auto-generated constructor stub
	Deck gameDeck;
	//gameDeck.Shuffle();
	House gameHouse;
}

void Game::GetPlayers()
{
	int numPlayers;
	string nameInput;
	cout<<"How many players (1-7)? ";
	cin>>numPlayers;
	for (int i = 0; i < numPlayers; i++)
	{
		cout<<"Enter player name: ";
		cin>>nameInput;
		playerList.push_back(Player(nameInput));
	}
}

void Game::FirstDeal(){
	gameDeck.Shuffle();
	//Player temp;
	Hand* ptemp;
	for (unsigned int i = 0; i < playerList.size(); i++)
	{
		//temp = playerList.at(i);
		ptemp = playerList.at(i).GetPlayerHandPointer();
		gameDeck.DealTopCard(ptemp);
		gameDeck.DealTopCard(ptemp);
	}
	ptemp = gameHouse.GetPlayerHandPointer();
	gameDeck.DealTopCard(ptemp);
	gameDeck.DealTopCard(ptemp);
}

void Game::DisplayPlayersHands(){
	Player temp;
	Hand htemp;
	for (unsigned int i = 0; i < playerList.size(); i++)
	{
		temp = playerList.at(i);
		htemp = temp.GetPlayerHand();
		cout<<temp.GetPlayerName()<<" ";
		cout<<htemp.DisplayHand()<<"("<<htemp.DisplayHandValue()<<")"<<endl;
	}
	cout<<"House "<<gameHouse.DisplayHouseHand()<<endl;
}

void Game::AskPlayersToHit(){
	Player temp;
	char input;
	Hand* ptemp;
	Hand htemp;
	for (unsigned int i = 0; i < playerList.size(); i++)
	{
		temp = playerList.at(i);
		cout<<temp.GetPlayerName()<<" do you want to hit (Y or N)? "<<endl;
		cin>>input;
		while (input != 'N')
		{
			ptemp = playerList.at(i).GetPlayerHandPointer();
			gameDeck.DealTopCard(ptemp);
			htemp = temp.GetPlayerHand();
			cout<<temp.GetPlayerName()<<" ";
			cout<<ptemp->DisplayHand()<<"("<<ptemp->DisplayHandValue()<<")"<<endl;
			if ( stoi(ptemp->DisplayHandValue()) > 21 or ptemp->GetAceBust() == true)
			{
				cout<<temp.GetPlayerName()<<" busts."<<endl;
				break;
			}
			cout<<temp.GetPlayerName()<<" do you want to hit (Y or N)? "<<endl;
			cin>>input;
		}
		cout<<endl;
	}
}

void Game::HouseHit(){
	Hand* ptemp;
	cout<<"House: "<<gameHouse.GetPlayerHand().DisplayHand();
	cout<<" ("<<gameHouse.GetPlayerHand().DisplayHandValue()<<")"<<endl;
	if (gameHouse.GetPlayerHand().GetHasAce() == false)
	{
		while ( stoi(gameHouse.GetPlayerHand().DisplayHandValue()) <= 16)
		{
			ptemp = gameHouse.GetPlayerHandPointer();
			gameDeck.DealTopCard(ptemp);
			cout<<"House: "<<gameHouse.GetPlayerHand().DisplayHand();
			cout<<" ("<<gameHouse.GetPlayerHand().DisplayHandValue()<<")"<<endl;
			if ( stoi(ptemp->DisplayHandValue()) > 21 or ptemp->GetAceBust() == true)
			{
				cout<<"House busts."<<endl;
				bustedHouse = true;
				houseValue = 0;
				break;
			}
		}
		if (bustedHouse == false)
		{
			houseValue = stoi(gameHouse.GetPlayerHand().DisplayHandValue());
		}
	}
	else
	{
		while (gameHouse.GetPlayerHand().GetLargerValue() <= 16)
		{
			ptemp = gameHouse.GetPlayerHandPointer();
			gameDeck.DealTopCard(ptemp);
			cout<<"House: "<<gameHouse.GetPlayerHand().DisplayHand();
			cout<<" ("<<gameHouse.GetPlayerHand().DisplayHandValue()<<")"<<endl;
			if (ptemp->GetAceBust() == true)
			{
				cout<<"House busts."<<endl;
				houseValue = 0;
				break;
			}
			else if (gameHouse.GetPlayerHand().GetLargerValue() > 21)
			{
				while (gameHouse.GetPlayerHand().GetSmallerValue() <= 16)
				{
					ptemp = gameHouse.GetPlayerHandPointer();
					gameDeck.DealTopCard(ptemp);
					cout<<"House: "<<gameHouse.GetPlayerHand().DisplayHand();
					cout<<" ("<<gameHouse.GetPlayerHand().DisplayHandValue()<<")"<<endl;
					if (gameHouse.GetPlayerHand().GetSmallerValue() > 21)
					{
						cout<<"House busts."<<endl;
						houseValue = 0;
					}
				}
				houseValue = gameHouse.GetPlayerHand().GetSmallerValue();
			}
			if (gameHouse.GetPlayerHand().GetLargerValue() <= 21)
			{
				houseValue = gameHouse.GetPlayerHand().GetLargerValue();
			}
		}
	}
}

void Game::AnnounceResults(){
	for (unsigned int i = 0; i < playerList.size(); i++)
	{
		if ( playerList.at(i).GetPlayerHand().GetHasAce() == false)
		{
			if ( stoi(playerList.at(i).GetPlayerHand().DisplayHandValue()) <= 21)
			{
				if ( stoi(playerList.at(i).GetPlayerHand().DisplayHandValue()) > houseValue )
				{
					cout<<playerList.at(i).GetPlayerName()<<" wins!"<<endl;
				}
				else if  (stoi(playerList.at(i).GetPlayerHand().DisplayHandValue()) == houseValue )
				{
						cout<<playerList.at(i).GetPlayerName()<<" ties!"<<endl;
				}
				else
				{
					cout<<playerList.at(i).GetPlayerName()<<" loses!"<<endl;
				}
			}
		}
		else
		{
			if ( playerList.at(i).GetPlayerHand().GetLargerValue() <= 21)
			{
				if ( playerList.at(i).GetPlayerHand().GetLargerValue() > houseValue )
				{
					cout<<playerList.at(i).GetPlayerName()<<" wins!"<<endl;
				}
				else if  (playerList.at(i).GetPlayerHand().GetLargerValue() == houseValue )
				{
					cout<<playerList.at(i).GetPlayerName()<<" ties!"<<endl;
				}
				else
				{
					cout<<playerList.at(i).GetPlayerName()<<" loses!"<<endl;
				}
			}
			else if ( playerList.at(i).GetPlayerHand().GetSmallerValue() <= 21)
			{
				if ( playerList.at(i).GetPlayerHand().GetSmallerValue() > houseValue )
				{
					cout<<playerList.at(i).GetPlayerName()<<" wins!"<<endl;
				}
					else if  (playerList.at(i).GetPlayerHand().GetSmallerValue() == houseValue )
				{
					cout<<playerList.at(i).GetPlayerName()<<" ties!"<<endl;
				}
				else
				{
					cout<<playerList.at(i).GetPlayerName()<<" loses!"<<endl;
				}
			}
		}
	}
}

Game::~Game() {
	// TODO Auto-generated destructor stub
}

