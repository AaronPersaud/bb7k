#ifndef __SLC_H__
#define __SLC_H__
#include <iostream>
#include <string>
#include "square.h"
#include "player.h"

class SLC: public Square {
public:
	SLC();
	~SLC();
	void movePlayer(Player*);
	//int getNum();
	void drawCup(Player*);
};


#endif
