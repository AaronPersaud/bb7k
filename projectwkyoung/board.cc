#include <iostream>
#include <string>
#include "board.h"
#include "controller.h"
#include "needleshall.h" 
#include "slc.h"
#include "residence.h"
#include "building.h"
#include "gym.h"
#include "tuition.h"

using namespace std;

Board::Board() {}

void Board::improve() {} //TODO

void Board::mortgage() {} //TODO

void Board::assets() {} //TODO

void Board::trade() {} //TODO

void Board::bankrupt() {} //TODO

void Board::unmortgage() {} //TODO

void Board::createBoard() {
    squares = new Square*[40];
    for (int i = 0; i < 40; i++) {
      if(i==5||i==15||i==25||i==35) {
        squares[i] = new Residence;
      }  
      else if(i==2||i==17||i==33) {
        squares[i] = new SLC;
      }
      else if(i==7||i==22||i==36) {
        squares[i] = new NeedlesHall;
      }
      else if(i==12||i==28) {
        squares[i] = new Gym;
      }
      else if(i==4) {
        squares[i] = new Tuition;
      }
      else if(i==1||i==3||i==6||i==8||i==9||i==11||i==13||i==14||i==16||i==18||i==19||i==21||i==23||i==24||i==26||i==27||i==29||i==31||i==32||i==34||i==37||i==39) {
        squares[i] = new Building;
      }
      else{
        squares[i] = new Square;
      }
    }
}


void Board::initSquares() {
  (squares[1])->setEverything( "AL",  "Arts1", 1, 40, 2, 2, 10, 30,  90, 160, 250,0,false,false,NULL,false, 50);
  (squares[3])->setEverything( "ML",  "Arts1", 3, 60, 4, 4, 20, 60, 180, 320, 450,0,false,false,NULL,false, 50);
  (squares[6])->setEverything("ECH",  "Arts2", 6,100, 6, 6, 30, 90, 270, 400, 550,0,false,false,NULL,false, 50);
  (squares[8])->setEverything("PAS",  "Arts2", 8,100, 6, 6, 30, 90, 270, 400, 550,0,false,false,NULL,false, 50);
  (squares[9])->setEverything("HH",   "Arts2", 9,120, 8, 8, 40,100, 300, 450, 600,0,false,false,NULL,false, 50);
  (squares[11])->setEverything("RCH",   "Eng",11,140,10,10, 50,150, 450, 625, 750,0,false,false,NULL,false,100);
  (squares[13])->setEverything("DWE",   "Eng",13,140,10,10, 50,150, 450, 625, 750,0,false,false,NULL,false,100);
  (squares[14])->setEverything("CPH",   "Eng",14,160,12,12, 60,180, 500, 700, 900,0,false,false,NULL,false,100);
  (squares[16])->setEverything("LHI","Health",16,180,14,14, 70,200, 550, 750, 950,0,false,false,NULL,false,100);
  (squares[18])->setEverything("BMH","Health",18,180,14,14, 70,200, 550, 750, 950,0,false,false,NULL,false,100);
  (squares[19])->setEverything("OPT","Health",19,200,16,16, 80,220, 600, 800,1000,0,false,false,NULL,false,100);
  (squares[21])->setEverything("EV1",   "Env",21,220,18,18, 90,250, 700, 875,1050,0,false,false,NULL,false,150);
  (squares[23])->setEverything("EV2",   "Env",23,220,18,18, 90,250, 700, 875,1050,0,false,false,NULL,false,150);
  (squares[24])->setEverything("EV3",   "Env",24,240,20,20,100,300, 750, 925,1100,0,false,false,NULL,false,150);
  (squares[26])->setEverything("PHYS", "Sci1",26,260,22,22,110,330, 800, 975,1150,0,false,false,NULL,false,150);
  (squares[27])->setEverything("B1",   "Sci1",27,260,22,22,110,330, 800, 975,1150,0,false,false,NULL,false,150);
  (squares[29])->setEverything("B2",   "Sci1",29,280,24,24,120,360, 850,1025,1200,0,false,false,NULL,false,150);
  (squares[31])->setEverything("EIT",  "Sci2",31,300,26,26,130,390, 900,1100,1275,0,false,false,NULL,false,200);
  (squares[32])->setEverything("ESC",  "Sci2",32,300,26,26,130,390, 900,1100,1275,0,false,false,NULL,false,200);
  (squares[34])->setEverything("C2",   "Sci2",34,320,28,28,150,450,1000,1200,1400,0,false,false,NULL,false,200);
  (squares[37])->setEverything("MC",   "Math",37,350,35,35,175,500,1100,1300,1500,0,false,false,NULL,false,200);
  (squares[39])->setEverything("DC",   "Math",39,400,50,50,200,600,1400,1700,2000,0,false,false,NULL,false,200);
}

void Board::init(int players, Controller* gameNotification) {
	numOfPlayers = players;
	notification = gameNotification;
	createBoard();
	initSquares();
}



bool Board::checkMonopoly(const string block) {

	if (block == "Arts1") {

		return (squares[1]->getOwner() == squares[3]->getOwner());

	} else if (block =="Arts2") {

		return (squares[6]->getOwner() == squares[8]->getOwner() &&  squares[8]->getOwner()  == squares[9]->getOwner());

	} else if (block == "Eng") {

		return (squares[11]->getOwner() == squares[13]->getOwner() && squares[13]->getOwner() == squares[14]->getOwner());

	} else if (block == "Health") {

		return (squares[16]->getOwner() == squares[18]->getOwner() &&  squares[18]->getOwner() == squares[19]->getOwner());

	} else if (block == "Env") {

		return (squares[21]->getOwner() == squares[23]->getOwner() && squares[23]->getOwner() == squares[24]->getOwner());

	} else if (block == "Sci1") {

		return (squares[26]->getOwner() == squares[27]->getOwner() && squares[27]->getOwner() == squares[29]->getOwner());

	} else if (block == "Sci2") {

		return (squares[31]->getOwner() == squares[32]->getOwner() && squares[32]->getOwner() == squares[34]->getOwner());

	} else if (block == "Math") {

		return (squares[37]->getOwner() == squares[39]->getOwner());

	} // if

	cerr << "Enter right block name!" << endl;
	return false;

} // checkMonopolied




void Board::setMonopoly(const string block) {

	if (block == "Arts1") {

		if (squares[1]->getOwner() == squares[3]->getOwner()) {

			squares[1]->setMonopolied();
			squares[3]->setMonopolied();
			cout << squares[1]->getBlock() << " is monopolied by " << squares[1]->getOwner() << "!" << endl;

		} // if

	} else if (block =="Arts2") {

		if (squares[6]->getOwner() == squares[8]->getOwner() && squares[8]->getOwner() == squares[9]->getOwner()) {

			squares[6]->setMonopolied();
			squares[8]->setMonopolied();
			squares[9]->setMonopolied();
			cout << squares[6]->getBlock() << " is monopolied by " << squares[6]->getOwner() << "!" << endl;


		} // if

	} else if (block == "Eng") {

		if (squares[11]->getOwner() == squares[13]->getOwner() && squares[13]->getOwner() == squares[14]->getOwner()) {

			squares[11]->setMonopolied();
			squares[13]->setMonopolied();
			squares[14]->setMonopolied();
			cout << squares[11]->getBlock() << " is monopolied by " << squares[11]->getOwner() << "!" << endl;


		} // if

	} else if (block == "Health") {

		if (squares[16]->getOwner() == squares[18]->getOwner() && squares[18]->getOwner() == squares[19]->getOwner()) {

			squares[16]->setMonopolied();
			squares[18]->setMonopolied();
			squares[19]->setMonopolied();
			cout << squares[16]->getBlock() << " is monopolied by " << squares[16]->getOwner() << "!" << endl;


		} // if

	} else if (block == "Env") {

		if (squares[21]->getOwner() == squares[23]->getOwner() && squares[23]->getOwner() == squares[24]->getOwner()) {

			squares[21]->setMonopolied();
			squares[23]->setMonopolied();
			squares[24]->setMonopolied();
			cout << squares[21]->getBlock() << " is monopolied by " << squares[21]->getOwner() << "!" << endl;


		} // if

	} else if (block == "Sci1") {

		if (squares[26]->getOwner() == squares[27]->getOwner() && squares[27]->getOwner() == squares[29]->getOwner()) {

			squares[26]->setMonopolied();
			squares[27]->setMonopolied();
			squares[29]->setMonopolied();
			cout << squares[26]->getBlock() << " is monopolied by " << squares[26]->getOwner() << "!" << endl;


		} // if

	} else if (block == "Sci2") {

		if (squares[31]->getOwner() == squares[32]->getOwner() && squares[32]->getOwner() == squares[34]->getOwner()) {

			squares[31]->setMonopolied();
			squares[32]->setMonopolied();
			squares[34]->setMonopolied();
			cout << squares[31]->getBlock() << " is monopolied by " << squares[31]->getOwner() << "!" << endl;


		} // if

	} else if (block == "Math") {

		if (squares[37]->getOwner() == squares[39]->getOwner()) {

			squares[37]->setMonopolied();
			squares[39]->setMonopolied();
			cout << squares[37]->getBlock() << " is monopolied by " << squares[37]->getOwner() << "!" << endl;


		} // if

	} // if

} // checkMonopolied

