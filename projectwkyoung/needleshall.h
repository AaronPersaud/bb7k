#ifndef __NEEDLESHALL_H__
#define __NEEDLESHALL_H__
#include <iostream>
#include <string>
#include "square.h"
#include "player.h"

class NeedlesHall: public Square {
	

public:
	NeedlesHall();
	~NeedlesHall();
	void calculate(Player*);
	void drawCup();
	std::string getOwner() {} //test
        std::string getBlock() {} //test
        int getTuition() {}
};




#endif 
