#include <iostream>
#include <string>
#include "square.h"
#include "tuition.h"

using namespace std;

Tuition::Tuition() {}

Tuition::~Tuition() {}

void Tuition::payAmount(Player*) {

}

void Tuition::payPercent(Player*) {

}

void Tuition::askOption() {

	int option;
	bool invalidOption = true;

	cout << "Which payment option would you like to choose?" << endl;
	cout << endl;
	cout << "	1. pay $300" << endl;
	cout << endl;
	cout << "	2. 10 percent of your total worth (including your savings,";
	cout <<			  " printed prices of all buildings you own, and costs of each improvement)" << endl;
	cout << endl;
	cout << "Please enter 1 or 2 for your payment option.";

	cin >> option;

	while (invalidOption) {

		if (option == 1) {

	            //		payAmount(Player* player); Where did you get this player?
			invalidOption = false;

		} else if (option == 2) {

		//	payPercent(Player* player); Where did you get this player?
			invalidOption = false;

		} else {

			cout << "Invalid option. Please enter 1 or 2." << endl;
			cin >> option;

		} // if

	} // while
	
} // askOption
