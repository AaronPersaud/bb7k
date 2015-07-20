#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include <iostream>
#include <string>
#include "view.h"

class TextDisplay: public View {

	int numOfPlayers;
	//char* players;

	// squares in the 1st line-up
	std::string GooseNestingSeat1;
	std::string GooseNestingSeat2;

	std::string EV1;
	std::string EV1seat1;
	std::string EV1seat2;

	std::string NEEDLESHALLseat1N;
	std::string NEEDLESHALLseat2N;

	std::string EV2;
	std::string EV2seat1;
	std::string EV2seat2;

	std::string EV3;
	std::string EV3seat1;
	std::string EV3seat2;

	std::string V1seat1;
	std::string V1seat2;

	std::string PHYS;
	std::string PHYSseat1;
	std::string PHYSseat2;

	std::string B1;
	std::string B1seat1;
	std::string B1seat2;

	std::string CIFseat1;
	std::string CIFseat2;

	std::string B2;
	std::string B2seat1;
	std::string B2seat2;

	std::string GoToTimsSeat1;
	std::string GoToTimsSeat2;


    // squares in the 2nd line-up
	std::string OPT;
	std::string OPTseat1;
	std::string OPTseat2;

	std::string EIT;
	std::string EITseat1;
	std::string EITseat2;


	// squears in the 3rd line-up
	std::string BMH;
	std::string BMHseat1;
	std::string BMHseat2;

	std::string ESC;
	std::string ESCseat1;
	std::string ESCseat2;


	// squears in the 4th line-up
	std::string SLCseatW1;
	std::string SLCseatW2;

	std::string SLCseatE1;
	std::string SLCseatE2;


	// squares in the 5th line-up
	std::string LHI;
	std::string LHIseat1;
	std::string LHIseat2;

	std::string C2;
	std::string C2seat1;
	std::string C2seat2;


	// squeares in the 6th line-up
	std::string UWP;
	std::string UWPseat1;
	std::string UWPseat2;

	std::string REV;
	std::string REVseat1;
	std::string REVseat2;


	// squares in the 7th line-up
	std::string CPH;
	std::string CPHseat1;
	std::string CPHseat2;

	std::string NEEDLESHALLseat1E;
	std::string NEEDLESHALLseat2E;


	// squares in the 8th line-up
	std::string DWE;
	std::string DWEseat1;
	std::string DWEseat2;

	std::string MC;
	std::string MCseat1;
	std::string MCseat2;


	// squeares in the 9th line-up
	std::string PACseat1;
	std::string PACseat2;

	std::string CoopFeeseat1;
	std::string CoopFeeseat2;


	// squares in the 10th line up
	std::string RCH;
	std::string RCHseat1;
	std::string RCHseat2;

    std::string DC;
	std::string DCseat1;
	std::string DCseat2;


	// squeares in the last line-up
	std::string DcTimsLine;
	std::string DcTimsLineSeat1;
	std::string DcTimsLineSeat2;

	std::string HH;
	std::string HHseat1;
	std::string HHseat2;

	std::string PAS;
	std::string PASseat1;
	std::string PASseat2;

	std::string NEEDLESHALLseat1S;
	std::string NEEDLESHALLseat2S;

	std::string ECH;
	std::string ECHseat1;
	std::string ECHseat2;

	std::string MKVseat1;
	std::string MKVseat2;

	std::string TUITIONseat1;
	std::string TUITIONseat2;

	std::string ML;
	std::string MLseat1;
	std::string MLseat2;

	std::string SLCseat1S;
	std::string SLCseat2S;

	std::string AL;
	std::string ALseat1;
	std::string ALseat2;

	std::string CollectOSAPseat1;
	std::string CollectOSAPseat2;

  public:
  char *players;
  TextDisplay();
   ~TextDisplay(); //virtual
    int getNumOfPlayers();
     void setNumOfPlayers(int); //virtual
     void setPlayer(char*); //virtual
    void startGame();
    void move(char, std::string&);
    void movePlayer(int, int);
    void remove(char, std::string&, std::string&);
    void removePlayer(int, int);
    void improve(int, std::string&);
    void improvement(int, int);
     void printBoard(); //virtual
};

#endif
