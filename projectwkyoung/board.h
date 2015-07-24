#ifndef __BOARD_H__
#define __BOARD_H__
#include <iostream>
#include <string>
#include "square.h"
#include "controller.h"
#include "player.h"

class Board {
	int numOfPlayers;
	//Square** squares; might need to change back
	Controller* notification;

public:
	Board();
	~Board();
	void createBoard();
	void initSquares();
	void init(int, Controller*);
	bool checkMonopoly(const std::string);
	void setMonopoly(const std::string);
	//int numOfOwn(char);
	Square** squares;
	int getTuition(int i); 
	void improve();
	void mortgage();
	void unmortgage();
	void bankrupt();
	void assets();
	void trade();
	void roll();      
        void callTimsLine();
	void useRollUpTheRim();
        void payMoneyTims();
	void rollDice();
        void set(std::string b, Player* owner, int im); 
};

#endif 
