#ifndef __TUITION_H__
#define __TUITION_H__
#include <iostream>
#include <string>
#include "square.h"
#include "player.h"

class Tuition: public Square
{
public:
	Tuition();
	~Tuition();
	void payAmount(Player*);
	void payPercent(Player*);
        void askOption();
	//std::string getOwner(); //test
	//std::string getBlock(); //test
        //int getTuition();
};

#endif
