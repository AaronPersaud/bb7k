#ifndef __BOARD_H__
#define __BOARD_H__
#include <iostream>
#include <string>
#include "square.h"
#include "player.h"

//class Player;

//class Square;

class Auction {
	int price;
	Player* Winner;
public:
	Auction();
	void auction(Player* [], int, Square*);  // 
	void auctionBankruptcy(Player* [], int, Square**);
	//void bidding(Player*, int);
	//int finalPrice();
	void winner(Player*, int, Square*);
};



#endif
