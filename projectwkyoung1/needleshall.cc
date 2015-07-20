#include <iostream>
#include <string>
#include <stdlib.h>
#include "square.h"
#include "needleshall.h"

using namespace std;

NeedlesHall::NeedlesHall() {}

NeedlesHall::~NeedlesHall() {}

void NeedlesHall::calculate(Player* player) {

	int drawRollCup = rand() % 100 + 1;

	if (drawRollCup == 7) {

		drawCup();
		return;
		
	}

	int draw = rand() % 18 + 1;

	if (draw == 1) {

		player->setMoney(200);

	} else if (draw == 2 || draw == 3) {

		player->setMoney(100);

	} else if (draw == 4 || draw == 5 ||draw == 6) {

		player->setMoney(50);

	} else if (draw == 13 || draw == 14 ||draw == 15) {

		player->setMoney(-50);

	} else if (draw == 16 || draw == 17) {

		player->setMoney(-100);

	} else if (draw == 18) {

		player->setMoney(-200);

	} else {

		player->setMoney(25);

	}

}
void NeedlesHall::drawCup() {


}

