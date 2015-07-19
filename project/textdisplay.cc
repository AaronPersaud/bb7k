#include <iostream>
#include <string>
#include "textdisplay.h"
using namespace std;

TextDisplay::TextDisplay() {

	players = new char [9];

	    // squares in the 1st line-up
	GooseNestingSeat1 = "_______";
	GooseNestingSeat2 = "       ";

	EV1 = "       ";
	EV1seat1 = "_______";
	EV1seat2 = "       ";

	NEEDLESHALLseat1N = "_______";
	NEEDLESHALLseat2N = "       ";

	EV2 = "       ";
	EV2seat1 = "_______";
	EV2seat2 = "       ";

	EV3 = "       ";
	EV3seat1 = "_______";
	EV3seat2 = "       ";

	V1seat1 = "_______";
	V1seat2 = "       ";

	PHYS = "       ";
	PHYSseat1 = "_______";
	PHYSseat2 = "       ";

	B1 = "       ";
	B1seat1 = "_______";
	B1seat2 = "       ";

	CIFseat1 = "_______";
	CIFseat2 = "       ";

	B2 = "       ";
	B2seat1 = "_______";
	B2seat2 = "       ";

	GoToTimsSeat1 = "_______";
	GoToTimsSeat2 = "       ";


    // squares in the 2nd line-up
	OPT = "       ";
	OPTseat1 = "_______";
	OPTseat2 = "       ";

	EIT = "       ";
	EITseat1 = "_______";
	EITseat2 = "       ";


	// squears in the 3rd line-up
	BMH = "       ";
	BMHseat1 = "_______";
	BMHseat2 = "       ";

	ESC = "       ";
	ESCseat1 = "_______";
	ESCseat2 = "       ";


	// squears in the 4th line-up
	SLCseatW1 = "_______";
	SLCseatW2 = "       ";

	SLCseatE1 = "_______";
	SLCseatE2 = "       ";


	// squares in the 5th line-up
	LHI = "       ";
	LHIseat1 = "_______";
	LHIseat2 = "       ";

	C2 = "       ";
	C2seat1 = "_______";
	C2seat2 = "       ";


	// squeares in the 6th line-up
	UWP = "       ";
	UWPseat1 = "_______";
	UWPseat2 = "       ";

	REV = "       ";
	REVseat1 = "_______";
	REVseat2 = "       ";


	// squares in the 7th line-up
	CPH = "       ";
	CPHseat1 = "_______";
	CPHseat2 = "       ";

	NEEDLESHALLseat1E = "_______";
	NEEDLESHALLseat2E = "       ";


	// squares in the 8th line-up
	DWE = "       ";
	DWEseat1 = "_______";
	DWEseat2 = "       ";

	MC = "       ";
	MCseat1 = "_______";
	MCseat2 = "       ";


	// squeares in the 9th line-up
	PACseat1 = "_______";
	PACseat2 = "       ";

	CoopFeeseat1 = "_______";
	CoopFeeseat2 = "       ";


	// squares in the 10th line up
	RCH = "       ";
	RCHseat1 = "_______";
	RCHseat2 = "       ";

    DC = "       ";
	DCseat1 = "_______";
	DCseat2 = "       ";


	// squeares in the last line-up
	DcTimsLine = "       ";
	DcTimsLineSeat1 = "_______";
	DcTimsLineSeat2 = "       ";

	HH = "       ";
	HHseat1 = "_______";
	HHseat2 = "       ";

	PAS = "       ";
	PASseat1 = "_______";
	PASseat2 = "       ";

	NEEDLESHALLseat1S = "_______";
	NEEDLESHALLseat2S = "       ";

	ECH = "       ";
	ECHseat1 = "_______";
	ECHseat2 = "       ";

	MKVseat1 = "_______";
	MKVseat2 = "       ";

	TUITIONseat1 = "_______";
	TUITIONseat2 = "       ";

	ML = "       ";
	MLseat1 = "_______";
	MLseat2 = "       ";

	SLCseat1S = "_______";
	SLCseat2S = "       ";

	AL = "       ";
	ALseat1 = "_______";
	ALseat2 = "       ";

	CollectOSAPseat1 = "_______";
	CollectOSAPseat2 = "       ";
}

TextDisplay::~TextDisplay() {delete players;}

void TextDisplay::setNumOfPlayers(int num) {
	numOfPlayers = num;
}

int TextDisplay::getNumOfPlayers() {return numOfPlayers;}

void TextDisplay::setPlayer(char* player) {
	for (int i = 0; i < numOfPlayers; i++) {
		*(players + i) = *(player + i);
	}

	*(players + numOfPlayers) = '\0';
}


void TextDisplay::startGame() {

	for (int i = 1; i < numOfPlayers + 1; i++) {
		movePlayer(i,0);
	}

	printBoard();
}


void TextDisplay::move(char player, string& position) {

	for (int i = 0; i < 7; i += 2) {
		if (position[i] == '_') {
			position[i] = player;
			break;
		} else if (position[i] == ' ') {
			position[i] = player;
			break;
		} // if
	} // for
}



void TextDisplay::movePlayer(int player, int position) {

	if (position == 0) {

		if (CollectOSAPseat1[6] == '_') {move(players[player - 1], CollectOSAPseat1);}
		else {move(*(players + player - 1), CollectOSAPseat2);}

	} else if (position == 1) {

		if (ALseat1[6] == '_') {move(players[player - 1], ALseat1);}
		else {move(players[player - 1], ALseat2);}

	} else if (position == 2) {
		
		if (SLCseat1S[6] == '_') {move(players[player - 1], SLCseat1S);}
		else {move(players[player - 1], SLCseat2S);}

	} else if (position == 3) {

		if (MLseat1[6] == '_') {move(players[player - 1], MLseat1);}
		else {move(players[player - 1], MLseat2);}
		
	} else if (position == 4) {

		if (TUITIONseat1[6] == '_') {move(players[player - 1], TUITIONseat1);}
		else {move(players[player - 1], TUITIONseat1);}
		
	} else if (position == 5) {

		if (MKVseat1[6] == '_') {move(players[player - 1], MKVseat1);}
		else {move(players[player - 1], MKVseat2);}
		
	} else if (position == 6) {
		if (ECHseat1[6] == '_') {move(players[player - 1], ECHseat1);}
		else {move(players[player - 1], ECHseat2);}
		
	} else if (position == 7) {

		if (NEEDLESHALLseat1S[6] == '_') {move(players[player - 1], NEEDLESHALLseat1S);}
		else {move(players[player - 1], NEEDLESHALLseat2S);}
		
	} else if (position ==  8) {

		if (PASseat1[6] == '_') {move(players[player - 1], PASseat1);}
		else {move(players[player - 1], PASseat2);}
		
	} else if (position ==  9) {

		if (HHseat1[6] == '_') {move(players[player - 1], HHseat1);}
		else {move(players[player - 1], HHseat2);}
		
	} else if (position == 10) {

		if (DcTimsLineSeat1[6] == '_') {move(players[player - 1], DcTimsLineSeat1);}
		else {move(players[player - 1], DcTimsLineSeat2);}
		
	} else if (position == 11) {

		if (RCHseat1[6] == '_') {move(players[player - 1], RCHseat1);}
		else {move(players[player - 1], RCHseat2);}

		
	} else if (position == 12) {

		if (PACseat1[6] == '_') {move(players[player - 1], PACseat1);}
		else {move(players[player - 1], PACseat2);}
		
	} else if (position == 13) {

		if (DWEseat1[6] == '_') {move(players[player - 1], DWEseat1);}
		else {move(players[player - 1], DWEseat2);}

	} else if (position == 14) {

		if (CPHseat1[6] == '_') {move(players[player - 1], CPHseat1);}
		else {move(players[player - 1], CPHseat2);}
		
	} else if (position == 15) {

		if (UWPseat1[6] == '_') {move(players[player - 1], UWPseat1);}
		else {move(players[player - 1], UWPseat2);}
		
	} else if (position == 16) {

		if (LHIseat1[6] == '_') {move(players[player - 1], LHIseat1);}
		else {move(players[player - 1], LHIseat2);}
		
	} else if (position == 17) {

		if (SLCseatW1[6] == '_') {move(players[player - 1], SLCseatW1);}
		else {move(players[player - 1], SLCseatW2);}

	} else if (position == 18) {

		if (BMHseat1[6] == '_') {move(players[player - 1], BMHseat1);}
		else {move(players[player - 1], BMHseat2);}
		
	} else if (position == 19) {

		if (OPTseat1[6] == '_') {move(players[player - 1], OPTseat1);}
		else {move(players[player - 1], OPTseat2);}
		
	} else if (position == 20) {

		if (GooseNestingSeat1[6] == '_') {move(players[player - 1], GooseNestingSeat1);}
		else {move(players[player - 1], GooseNestingSeat2);}
		
	} else if (position == 21) {

		if (EV1seat1[6] == '_') {move(players[player - 1], EV1seat1);}
		else {move(players[player - 1], EV1seat2);}

	} else if (position == 22) {

		if (NEEDLESHALLseat1N[6] == '_') {move(players[player - 1], NEEDLESHALLseat1N);}
		else {move(players[player - 1], NEEDLESHALLseat2N);}

	} else if (position == 23) {
		if (EV2seat1[6] == '_') {move(players[player - 1], EV2seat1);}
		else {move(players[player - 1], EV2seat2);}

	} else if (position == 24) {

		if (EV3seat1[6] == '_') {move(players[player - 1], EV3seat1);}
		else {move(players[player - 1], EV3seat2);}

	} else if (position == 25) {

		if (V1seat1[6] == '_') {move(players[player - 1], V1seat1);}
		else {move(players[player - 1], V1seat2);}

	} else if (position == 26) {

		if (PHYSseat1[6] == '_') {move(players[player - 1], PHYSseat1);}
		else {move(players[player - 1], PHYSseat2);}


	} else if (position == 27) {

		if (B1seat1[6] == '_') {move(players[player - 1], B1seat1);}
		else {move(players[player - 1], B1seat2);}

	} else if (position == 28) {

		if (CIFseat1[6] == '_') {move(players[player - 1], CIFseat1);}
		else {move(players[player - 1], CIFseat2);}

	} else if (position == 29) {

		if (B2seat1[6] == '_') {move(players[player - 1], B2seat1);}
		else {move(players[player - 1], B2seat2);}

	} else if (position == 30) {

		if (GoToTimsSeat1[6] == '_') {move(players[player - 1], GoToTimsSeat1);}
		else {move(players[player - 1], GoToTimsSeat2);}

	} else if (position == 31) {

		if (EITseat1[6] == '_') {move(players[player - 1], EITseat1);}
		else {move(players[player - 1], EITseat2);}

	} else if (position == 32) {

		if (ESCseat1[6] == '_') {move(players[player - 1], ESCseat1);}
		else {move(players[player - 1], ESCseat2);}

	} else if (position == 33) {

		if (SLCseatE1[6] == '_') {move(players[player - 1], SLCseatE1);}
		else {move(players[player - 1], SLCseatE2);}

	} else if (position == 34) {

		if (C2seat1[6] == '_') {move(players[player - 1], C2seat1);}
		else {move(players[player - 1], C2seat2);}

	} else if (position == 35) {

		if (REVseat1[6] == '_') {move(players[player - 1], REVseat1);}
		else {move(players[player - 1], REVseat2);}

	} else if (position == 36) {

		if (NEEDLESHALLseat1E[6] == '_') {move(players[player - 1], NEEDLESHALLseat1E);}
		else {move(players[player - 1], NEEDLESHALLseat2E);}

	} else if (position == 37) {

		if (MCseat1[6] == '_') {move(players[player - 1], MCseat1);}
		else {move(players[player - 1], MCseat2);}

	} else if (position == 38) {

		if (CoopFeeseat1[6] == '_') {move(players[player - 1], CoopFeeseat1);}
		else {move(players[player - 1], CoopFeeseat2);}

	} else if (position == 39) {

		if (DCseat1[6] == '_') {move(players[player - 1], DCseat1);}
		else {move(players[player - 1], DCseat2);}

	} // if
}


void TextDisplay::remove(char player, string& seat1, string& seat2) {

	for (int i = 0; i < 7; i += 2) {
		if (seat1[i] == player) {
			seat1[i] = '_';
			break;
		}
	}

	for (int i = 0; i < 7; i += 2) {
		if (seat2[i] == player) {
			seat2[i] = ' ';
			break;
		}
	}

}


void TextDisplay::removePlayer(int player, int position) {
	if (position == 0) {

		remove(players[player - 1], CollectOSAPseat1, CollectOSAPseat2);

	} else if (position == 1) {

		remove(players[player - 1], ALseat1, ALseat2);

	} else if (position == 2) {
		
		remove(players[player - 1], SLCseat1S, SLCseat2S);

	} else if (position == 3) {

		remove(players[player - 1], MLseat1, MLseat2);
		
	} else if (position == 4) {

		remove(players[player - 1], TUITIONseat1, TUITIONseat2);
		
	} else if (position == 5) {

		remove(players[player - 1], MKVseat1, MKVseat2);
		
	} else if (position == 6) {

		remove(players[player - 1], ECHseat1, ECHseat2);
		
	} else if (position == 7) {

		remove(players[player - 1], NEEDLESHALLseat1S, NEEDLESHALLseat2S);
		
	} else if (position ==  8) {

		remove(players[player - 1], PASseat1, PASseat2);

	} else if (position ==  9) {

		remove(players[player - 1], HHseat1, HHseat2);
		
	} else if (position == 10) {

		remove(players[player - 1], DcTimsLineSeat1, DcTimsLineSeat2);
		
	} else if (position == 11) {

		remove(players[player - 1], RCHseat1, RCHseat2);
		
	} else if (position == 12) {

		remove(players[player - 1], PACseat1, PACseat2);
		
	} else if (position == 13) {

		remove(players[player - 1], DWEseat1, DWEseat2);

	} else if (position == 14) {

		remove(players[player - 1], CPHseat1, CPHseat2);
		
	} else if (position == 15) {

		remove(players[player - 1], UWPseat1, UWPseat2);
		
	} else if (position == 16) {

		remove(players[player - 1], LHIseat1, LHIseat2);
		
	} else if (position == 17) {

		remove(players[player - 1], SLCseatW1, SLCseatW2);

	} else if (position == 18) {

		remove(players[player - 1], BMHseat1, BMHseat2);
		
	} else if (position == 19) {

		remove(players[player - 1], OPTseat1, OPTseat2);
		
	} else if (position == 20) {

		remove(players[player - 1], GooseNestingSeat1, GooseNestingSeat2);
		
	} else if (position == 21) {

		remove(players[player - 1], EV1seat1, EV2seat1);

	} else if (position == 22) {

		remove(players[player - 1], NEEDLESHALLseat1N, NEEDLESHALLseat2N);

	} else if (position == 23) {

		remove(players[player - 1], EV2seat1, EV2seat2);

	} else if (position == 24) {

		remove(players[player - 1], EV3seat1, EV3seat2);

	} else if (position == 25) {

		remove(players[player - 1], V1seat1, V1seat2);

	} else if (position == 26) {

		remove(players[player - 1], PHYSseat1, PHYSseat2);

	} else if (position == 27) {

		remove(players[player - 1], B1seat1, B1seat2);

	} else if (position == 28) {

		remove(players[player - 1], CIFseat1, CIFseat2);

	} else if (position == 29) {

		remove(players[player - 1], B2seat1, B2seat2);

	} else if (position == 30) {

		remove(players[player - 1], GoToTimsSeat1, GoToTimsSeat2);

	} else if (position == 31) {

		remove(players[player - 1], EITseat1, EITseat2);

	} else if (position == 32) {

		remove(players[player - 1], ESCseat1, ESCseat2);

	} else if (position == 33) {

		remove(players[player - 1], SLCseatE1, SLCseatE2);

	} else if (position == 34) {

		remove(players[player - 1], C2seat1, C2seat2);

	} else if (position == 35) {

		remove(players[player - 1], REVseat1, REVseat2);

	} else if (position == 36) {

		remove(players[player - 1], NEEDLESHALLseat1E, NEEDLESHALLseat2E);

	} else if (position == 37) {

		remove(players[player - 1], MCseat1, MCseat2);

	} else if (position == 38) {

		remove(players[player - 1], CoopFeeseat1, CoopFeeseat2);

	} else if (position == 39) {

		remove(players[player - 1], DCseat1, DCseat2);

	} // if
}

void TextDisplay::improve(int num, string& square) {

	square = "       ";

	for (int i = 0; i < num; i++) {
		square[i] = 'I';
	}
}

void TextDisplay::improvement(int num, int position) {
	if (position == 1) {

		improve(num,AL);

	} else if (position == 3) {

		improve(num,ML);
		
	} else if (position == 6) {

		improve(num,ECH);
		
	} else if (position ==  8) {

		improve(num,PAS);
		
	} else if (position ==  9) {

		improve(num,HH);
		
	} else if (position == 11) {

		improve(num,RCH);
		
	} else if (position == 13) {

		improve(num,DWE);

	} else if (position == 14) {

		improve(num,CPH);
		
	} else if (position == 16) {

		improve(num,LHI);
		
	} else if (position == 18) {

		improve(num,BMH);
		
	} else if (position == 19) {

		improve(num,OPT);
		
	} else if (position == 21) {

		improve(num,EV1);

	} else if (position == 23) {

		improve(num,EV2);

	} else if (position == 24) {

		improve(num,EV3);

	} else if (position == 26) {

		improve(num,PHYS);

	} else if (position == 27) {

		improve(num,B1);

	} else if (position == 29) {

		improve(num,B2);

	} else if (position == 31) {

		improve(num,EIT);

	} else if (position == 32) {

		improve(num,ESC);

	} else if (position == 34) {

		improve(num,C2);

	}else if (position == 37) {

		improve(num,MC);

	} else if (position == 39) {

		improve(num,DC);

	} // if
}

void TextDisplay::printBoard() {
	    // line 1
    cout << "   ";

	for (int i = 0; i < 8*11+1; i++) {
		cout << "_";
	}

	cout << endl;

    // line 2
	cout << "   |Goose  |";
	cout << EV1;
	cout << "|NEEDLES|";
	cout << EV2;
	cout << "|";
	cout << EV3;
	cout << "|V1     |";
	cout << PHYS;
	cout << "|";
	cout << B1;
	cout << "|CIF    |";
	cout << B2;
	cout << "|GO TO  |" << endl;

	// line 3
	cout << "   |Nesting|";
	cout << "-------";
	cout << "|HALL   |";
	cout << "-------";
	cout << "|";
	cout << "-------";
	cout << "|       |";
	cout << "-------";
	cout << "|";
	cout << "-------";
	cout << "|       |";
	cout << "-------";
	cout << "|TIMS   |" << endl;

	// line 4
	cout << "   |";
	cout << "       ";
	cout << "|EV1    |";
	cout << "       ";
	cout << "|EV2    |";
	cout << "EV3    |";
	cout << "       ";
	cout << "|PHYS   |";
	cout << "B1     |";
	cout << "       ";
	cout << "|B2     |";
	cout << "       ";
	cout << "|" << endl;

	// line 5

	cout << "   |" << GooseNestingSeat2;
	cout << "|" << EV1seat2;
	cout << "|" << NEEDLESHALLseat2N;
	cout << "|" << EV2seat2;
	cout << "|" << EV3seat2;
	cout << "|" << V1seat2;
	cout << "|" << PHYSseat2;
	cout << "|" << B1seat2;
	cout << "|" << CIFseat2;
	cout << "|" << B1seat2;
	cout << "|" << GoToTimsSeat2;
	cout << "|" << endl;

    // line 6
	cout << "   |" << GooseNestingSeat1;
	cout << "|" << EV1seat1;
	cout << "|" << NEEDLESHALLseat1N;
	cout << "|" << EV2seat1;
	cout << "|" << EV3seat1;
	cout << "|" << V1seat1;
	cout << "|" << PHYSseat1;
	cout << "|" << B1seat1;
	cout << "|" << CIFseat1;
	cout << "|" << B1seat1;
	cout << "|" << GoToTimsSeat1;
	cout << "|" << endl;

	// line 7
	cout << "   |" << OPT << "|";

	for (int i = 0; i < 71; i++) {
		cout << " ";
	}

	cout << "|" << EIT << "|" << endl;

	// line 8
	cout << "   |-------|";

	for (int i = 0; i < 71; i++) {
		cout << " ";
	}

	cout << "|-------|" << endl;

	// line 9
	cout << "   |OPT    |";

	for (int i = 0; i < 71; i++) {
		cout << " ";
	}

	cout << "|EIT    |" << endl;

	// line 10
	cout << "   |" << OPTseat2 << "|";

	for (int i = 0; i < 71; i++) {
		cout << " ";
	}

	cout << "|" << EITseat2 << "|" << endl;

	// line 11
	cout << "   |" << OPTseat1 << "|";

	for (int i = 0; i < 71; i++) {
		cout << " ";
	}

	cout << "|" << EITseat1 << "|" << endl;

    // line 12
    cout << "   |" << BMH << "|";

    for (int i = 0; i < 71; i++) {
		cout << " ";
	}

	cout << "|" << ESC << "|" << endl;

	// line 13
	cout << "   |-------|";

	for (int i = 0; i < 71; i++) {
		cout << " ";
	}

	cout << "|-------|" << endl;

	// line 14
	cout << "   |BMH    |";

    for (int i = 0; i < 71; i++) {
		cout << " ";
	}

	cout << "|ESC    |" << endl;

	// line 15
	cout << "   |" << BMHseat2 << "|";

    for (int i = 0; i < 71; i++) {
		cout << " ";
	}

	cout << "|" << ESCseat2 << "|" << endl;

	// line 16
	cout << "   |" << BMHseat1 << "|";

    for (int i = 0; i < 71; i++) {
		cout << " ";
	}

	cout << "|" << ESCseat1 << "|" << endl;

	// line 17
    cout << "   |SLC    |";

	for (int i = 0; i < 71; i++) {
		cout << " ";
	}

	cout << "|SLC    |" << endl;

	// line 18
    cout << "   |       |";

    for (int i = 0; i < 71; i++) {
		cout << " ";
	}

	cout << "|       |" << endl;

	// line 19
    cout << "   |       |";

    for (int i = 0; i < 71; i++) {
		cout << " ";
	}

	cout << "|       |" << endl;

	// line 20
	cout << "   |" << SLCseatW2 << "|";

    for (int i = 0; i < 71; i++) {
		cout << " ";
	}

	cout << "|" << SLCseatE2 << "|" << endl;

	// line 21
	cout << "   |" << SLCseatW1 << "|";

    for (int i = 0; i < 71; i++) {
		cout << " ";
	}

	cout << "|" << SLCseatE1 << "|" << endl;

	// line 21
	cout << "   |" << LHI << "|";

    for (int i = 0; i < 71; i++) {
		cout << " ";
	}

	cout << "|" << C2 << "|" << endl;

	// line 22
	cout << "   |-------|";

	for (int i = 0; i < 71; i++) {
		cout << " ";
	}

	cout << "|-------|" << endl;

	// line 23
	cout << "   |LHI    |";

	for (int i = 0; i < 71; i++) {
		cout << " ";
	}

	cout << "|C2     |" << endl;

	// line 24
	cout << "   |" << LHIseat2 << "|";

    for (int i = 0; i < 15; i++) {
		cout << " ";
	}

	for (int i = 0; i < 41; i++) {
		cout << "_";
	}

	for (int i = 0; i < 15; i++) {
		cout << " ";
	}

	cout << "|" << C2seat2 << "|" << endl;

	// line 25
	cout << "   |" << LHIseat1 << "|";

    for (int i = 0; i < 15; i++) {
		cout << " ";
	}

	cout << "|";

	for (int i = 0; i < 39; i++) {
		cout << " ";
	}

    cout << "|";

	for (int i = 0; i < 15; i++) {
		cout << " ";
	}

	cout << "|" << C2seat1 << "|" << endl;

	// line 26
    cout << "   |UWP    |";

    for (int i = 0; i < 15; i++) {
		cout << " ";
	}

	cout << "|  ###   ###   #####  ###   ###   ###   |";

	for (int i = 0; i < 15; i++) {
		cout << " ";
	}

	cout << "|REV    |" << endl;

	// line 27
    cout << "   |       |";

    for (int i = 0; i < 15; i++) {
		cout << " ";
	}

	cout << "|  #  #  #  #     #  #   # #   # #   #  |";

	for (int i = 0; i < 15; i++) {
		cout << " ";
	}

	cout << "|       |" << endl;

	// line 28
    cout << "   |       |";

    for (int i = 0; i < 15; i++) {
		cout << " ";
	}

	cout << "|  ####  ####    #   #   # #   # #   #  |";

	for (int i = 0; i < 15; i++) {
		cout << " ";
	}

	cout << "|       |" << endl;

	// line 29
    cout << "   |" << UWPseat2 << "|";

    for (int i = 0; i < 15; i++) {
		cout << " ";
	}

	cout << "|  #   # #   #  #    #   # #   # #   #  |";

	for (int i = 0; i < 15; i++) {
		cout << " ";
	}

	cout << "|" << REVseat2 << "|" << endl;

	// line 30
    cout << "   |" << UWPseat1 << "|";

    for (int i = 0; i < 15; i++) {
		cout << " ";
	}

	cout << "|  ####  ####  #      ###   ###   ###   |";

	for (int i = 0; i < 15; i++) {
		cout << " ";
	}

	cout << "|" << REVseat1 << "|" << endl;

	// line 31
	cout << "   |" << CPH << "|";

    for (int i = 0; i < 15; i++) {
		cout << " ";
	}

	cout << "|";

	for (int i = 0; i < 39; i++) {
		cout << "_";
	}

    cout << "|";

	for (int i = 0; i < 15; i++) {
		cout << " ";
	}

	cout << "|NEEDLES|" << endl;

	// line 32
	cout << "   |-------|";

    for (int i = 0; i < 71; i++) {
		cout << " ";
	}

	cout << "|HALL   |" << endl;

	// line 33
	cout << "   |CPH    |";

    for (int i = 0; i < 71; i++) {
		cout << " ";
	}

	cout << "|       |" << endl;

	// line 34
	cout << "   |" << CPHseat2 << "|";

    for (int i = 0; i < 71; i++) {
		cout << " ";
	}

	cout << "|" << NEEDLESHALLseat2E << "|" << endl;

	// line 35
	cout << "   |" << CPHseat1 << "|";

    for (int i = 0; i < 71; i++) {
		cout << " ";
	}

	cout << "|" << NEEDLESHALLseat1E << "|" << endl;

	// line 36
	cout << "   |" << DWE << "|";

    for (int i = 0; i < 71; i++) {
		cout << " ";
	}

	cout << "|" << MC << "|" << endl;

	// line 37
	cout << "   |-------|";

    for (int i = 0; i < 71; i++) {
		cout << " ";
	}

	cout << "|-------|" << endl;

	// line 38
	cout << "   |DWE    |";

    for (int i = 0; i < 71; i++) {
		cout << " ";
	}

	cout << "|MC     |" << endl;

	// line 39
	cout << "   |" << DWEseat2 << "|";

    for (int i = 0; i < 71; i++) {
		cout << " ";
	}

	cout << "|" << MCseat2 << "|" << endl;

	// line 40
	cout << "   |" << DWEseat1 << "|";

    for (int i = 0; i < 71; i++) {
		cout << " ";
	}

	cout << "|" << MCseat1 << "|" << endl;

	// line 41
	cout << "   |PAC    |";

    for (int i = 0; i < 71; i++) {
		cout << " ";
	}

	cout << "|COOP   |" << endl;

	// line 42
	cout << "   |       |";

    for (int i = 0; i < 71; i++) {
		cout << " ";
	}

	cout << "|       |" << endl;

	// line 43
	cout << "   |       |";

    for (int i = 0; i < 71; i++) {
		cout << " ";
	}

	cout << "|       |" << endl;

	// line 44
	cout << "   |" << PACseat2 << "|";

    for (int i = 0; i < 71; i++) {
		cout << " ";
	}

	cout << "|" << CoopFeeseat2 << "|" << endl;

	// line 45
	cout << "   |" << PACseat1 << "|";

    for (int i = 0; i < 71; i++) {
		cout << " ";
	}

	cout << "|" << CoopFeeseat1 << "|" << endl;

	// line 46
	cout << "   |" << RCH << "|";

    for (int i = 0; i < 71; i++) {
		cout << " ";
	}

	cout << "|" << DC << "|" << endl;

	// line 47
	cout << "   |-------|";

    for (int i = 0; i < 71; i++) {
		cout << " ";
	}

	cout << "|-------|" << endl;

	// line 48
	cout << "   |RCH    |";

    for (int i = 0; i < 71; i++) {
		cout << " ";
	}

	cout << "|DC     |" << endl;

	// line 49
	cout << "   |" << RCHseat2 << "|";

    for (int i = 0; i < 71; i++) {
		cout << " ";
	}

	cout << "|" << DCseat2 << "|" << endl;

	// line 50
	cout << "   |" << RCHseat1 << "|";

    for (int i = 0; i < 71; i++) {
		cout << "_";
	}

	cout << "|" << DCseat1 << "|" << endl;

	// line 51
	cout << "   |DC Tims|";
	cout << HH;
	cout << "|";
	cout << PAS;
	cout << "|NEEDLES|";
	cout << ECH;
	cout << "|MKV    ";
	cout << "|TUITION|";
	cout << ML;
	cout << "|SLC    |";
	cout << AL;
	cout << "|COLLECT|" << endl;

	// line 52
	cout << "   |Line   |";
	cout << "-------";
	cout << "|-------";
	cout << "|HALL   |";
	cout << "-------|";
	cout << "       ";
	cout << "|       |";
	cout << "-------";
	cout << "|";
	cout << "       ";
	cout << "|-------";
	cout << "|OSAP   |" << endl;

	// line 53
	cout << "   |";
	cout << "       ";
	cout << "|HH     |";
	cout << "PAS    ";
	cout << "|       |";
	cout << "ECH    |";
	cout << "       ";
	cout << "|       |";
	cout << "ML     |";
	cout << "       ";
	cout << "|AL     |";
	cout << "       ";
	cout << "|" << endl;

	// line 54

	cout << "   |" << DcTimsLineSeat2;
	cout << "|" << HHseat2;
	cout << "|" << PASseat2;
	cout << "|" << NEEDLESHALLseat2S;
	cout << "|" << ECHseat2;
	cout << "|" << MKVseat2;
	cout << "|" << TUITIONseat2;
	cout << "|" << MLseat2;
	cout << "|" << SLCseat2S;
	cout << "|" << ALseat2;
	cout << "|" << CollectOSAPseat2;
	cout << "|" << endl;

    // line 55
	cout << "   |" << DcTimsLineSeat1;
	cout << "|" << HHseat1;
	cout << "|" << PASseat1;
	cout << "|" << NEEDLESHALLseat1S;
	cout << "|" << ECHseat1;
	cout << "|" << MKVseat1;
	cout << "|" << TUITIONseat1;
	cout << "|" << MLseat1;
	cout << "|" << SLCseat1S;
	cout << "|" << ALseat1;
	cout << "|" << CollectOSAPseat1;
	cout << "|" << endl;

}

/*
int main() {
	TextDisplay* t1 = new TextDisplay();
	t1->setNumOfPlayers(6);
	char* arr = new char [9];
	*(arr) = 'A';
	*(arr+1) = 'B';
	*(arr+2) = 'C';
	*(arr+3) = 'D';
	*(arr+4) = 'E';
	*(arr+5) = 'F';
	*(arr+6) = '\0';

	//t1->players = arr;


	t1->setPlayer(arr); 

	for (int i = 0; i < t1->getNumOfPlayers(); i++) {
		cout << t1->players[i] << endl;
	}
	t1->printBoard();
}

*/

