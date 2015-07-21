#include <iostream>
#include <string>
#include "square.h"
#include "slc.h"
#include <stdlib.h>

SLC::SLC() {}

SLC::~SLC() {}

//Square::getTuition() {}

void SLC::movePlayer(Player* player) {

	int drawRollCup = rand() % 100 + 1;

	if (drawRollCup == 7) {

		drawCup(player);
		return;
		
	}

	int draw = rand() % 24 + 1;
	int temp;

	if (draw == 1) {

		temp = player->getCurrentPosition();
		player->setCurrentPosition(30);
		player->setPrevPosition(temp);

	} else if (draw == 2 || draw == 3 || draw == 4) {

		temp = player->getCurrentPosition();
		player->setCurrentPosition(temp - 3);
		player->setPrevPosition(temp);

	} else if (draw == 5 || draw == 6 ||draw == 7 || draw == 8) {

		temp = player->getCurrentPosition();
		player->setCurrentPosition(temp - 2);
		player->setPrevPosition(temp);

	} else if (draw == 9 || draw == 10 ||draw == 11|| draw == 12) {

		temp = player->getCurrentPosition();
		player->setCurrentPosition(temp - 1);
		player->setPrevPosition(temp);

	} else if (draw == 13 || draw == 14|| draw == 15) {

		temp = player->getCurrentPosition();
		player->setCurrentPosition(temp + 1);
		player->setPrevPosition(temp);

	} else if (draw == 16|| draw == 17 || draw == 18 || draw == 19) {

		temp = player->getCurrentPosition();
		player->setCurrentPosition(temp + 2);
		player->setPrevPosition(temp);

	} else if (draw == 20|| draw == 21 || draw == 22 || draw == 23) {

		temp = player->getCurrentPosition();
		player->setCurrentPosition(temp + 3);
		player->setPrevPosition(temp);

	} else {

		temp = player->getCurrentPosition();
		player->setCurrentPosition(0);
		player->setPrevPosition(temp);

	}

}


void SLC::drawCup(Player *player) {


}

