#include <iostream>
#include <string>
#include "board.h"
#include "controller.h"

using namespace std;

Board::Board(): numOfPlayers(0), squares(0) {}

void Board::createBoard() {
	squares = new Square* [40];

	for (int i = 0; i < 40; i++) {
		squares[i] = new Square;
	}
}

void Board::initSquares() {

}


void Board::init(int players, Controller* gameNotification) {

	numOfPlayers = players; 
	notification = gameNotification;

	createBoard();
	initSquares();
}



bool Board::checkMonopoly(const string block) {

	if (block == "Arts1") {

		return (squares[1]->getOwner() == squares[2]->getOwner());

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

		if (squares[1]->getOwner() == squares[2]->getOwner()) {

			squares[1]->monopolied = true;
			squares[2]->monopolied = true;
			cout << squares[1]->getBlock() << " is monopolied by " << squares[1]->getOwner() << "!" << endl;

		} // if

	} else if (block =="Arts2") {

		if (squares[6]->getOwner() == squares[8]->getOwner() && squares[8]->getOwner() == squares[9]->getOwner()) {

			squares[6]->monopolied = true;
			squares[8]->monopolied = true;
			squares[9]->monopolied = true;
			cout << squares[6]->getBlock() << " is monopolied by " << squares[6]->getOwner() << "!" << endl;


		} // if

	} else if (block == "Eng") {

		if (squares[11]->getOwner() == squares[13]->getOwner() && squares[13]->getOwner() == squares[14]->getOwner()) {

			squares[11]->monopolied = true;
			squares[13]->monopolied = true;
			squares[14]->monopolied = true;
			cout << squares[11]->getBlock() << " is monopolied by " << squares[11]->getOwner() << "!" << endl;


		} // if

	} else if (block == "Health") {

		if (squares[16]->getOwner() == squares[18]->getOwner() && squares[18]->getOwner() == squares[19]->getOwner()) {

			squares[16]->monopolied = true;
			squares[18]->monopolied = true;
			squares[19]->monopolied = true;
			cout << squares[16]->getBlock() << " is monopolied by " << squares[16]->getOwner() << "!" << endl;


		} // if

	} else if (block == "Env") {

		if (squares[21]->getOwner() == squares[23]->getOwner() && squares[23]->getOwner() == squares[24]->getOwner()) {

			squares[21]->monopolied = true;
			squares[23]->monopolied = true;
			squares[24]->monopolied = true;
			cout << squares[21]->getBlock() << " is monopolied by " << squares[21]->getOwner() << "!" << endl;


		} // if

	} else if (block == "Sci1") {

		if (squares[26]->getOwner() == squares[27]->getOwner() && squares[27]->getOwner() == squares[29]->getOwner()) {

			squares[26]->monopolied = true;
			squares[27]->monopolied = true;
			squares[29]->monopolied = true;
			cout << squares[26]->getBlock() << " is monopolied by " << squares[26]->getOwner() << "!" << endl;


		} // if

	} else if (block == "Sci2") {

		if (squares[31]->getOwner() == squares[32]->getOwner() && squares[32]->getOwner() == squares[34]->getOwner()) {

			squares[31]->monopolied = true;
			squares[32]->monopolied = true;
			squares[34]->monopolied = true;
			cout << squares[31]->getBlock() << " is monopolied by " << squares[31]->getOwner() << "!" << endl;


		} // if

	} else if (block == "Math") {

		if (squares[37]->getOwner() == squares[39]->getOwner()) {

			squares[37]->monopolied = true;
			squares[39]->monopolied = true;
			cout << squares[37]->getBlock() << " is monopolied by " << squares[37]->getOwner() << "!" << endl;


		} // if

	} // if

} // checkMonopolied

