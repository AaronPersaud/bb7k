#ifndef __BOARD_H__
#define __BOARD_H__
#include <iostream>
#include <string>
#include "square.h"
#include "controller.h"

class Board {
	int numOfPlayers;
	Square** squares;
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
	//Square** squares;
};

#endif 
