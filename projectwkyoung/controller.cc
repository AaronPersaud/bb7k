#include "controller.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

Controller::Controller(){
  td = NULL;
  gameBoard = NULL;
  yourTurn = NULL;
  for (int i = 0;i<8;i++){
    players[i] = NULL;
  }
}

Controller::~Controller() {
  delete td;
  delete gameBoard;
  yourTurn = NULL;
  for (int i = 0; i< numPlayers ;i++) {
    delete players[i];
  }
}

void Controller::setBuilding(string b, string o, int i) {
  Player *a = NULL;
  for(int j=0; j<numPlayers;j++) {
   if(players[j]->getName() == o) {
     a = players[j]; 
     break;
   }
  }
  gameBoard->set(b,a,i);
} 

void Controller::next() {
  if (turn == numPlayers) {
    turn = 1;
    yourTurn = players[0];
  }
  else {
    turn += 1;
    yourTurn = players[turn-1];
  }
}

void Controller::notify(int x,int y) {
  td->improvement(x, y);
}

void Controller::createPlayer(int i,string s,char c) {
  Player * p = new Player;
  p->setName(s);
  p->setToken(c);
  p->setCurrentPosition(0);
  p->setMoney(1500);
  players[i] = p;
}

void Controller::makeArray() { 
  symbols = new char[numPlayers + 1];
  for(int i=0;i < numPlayers + 1; i++) {
    if (i == numPlayers) {
      symbols[i] = '\0';
    }
    else{
      symbols[i] = players[i]->getToken();
    }
  }
}

void Controller::setPlayers() {
  td->setNumOfPlayers(numPlayers);
}

void Controller::setPlayerNames() {
  td->setPlayer(symbols);
}

void Controller::noParameter() {
  td = new TextDisplay;
  gameBoard = new Board;
  cin >> numPlayers;
  for(int i=0; i < 8; i++) {
    if (i < numPlayers) {
      string character;
      char t;
      cin >> character;
      cin >> t;
      createPlayer(i,character,t);
    }
    else{
      players[i] = NULL;
    }
  }
  gameBoard->init(numPlayers,this);
  makeArray();
  setPlayers();
  setPlayerNames();
  yourTurn = players[0];
  turn = 1;
  td->startGame();
  play();
}

void Controller::load(string file) {
  td = new TextDisplay;
  gameBoard = new Board;
  ifstream ifs(file.c_str());
  ifs >> numPlayers;
  string player;
  char token;
  int TimsCup;
  int money;
  int position;  
  while(true) {
      if(ifs.eof()) {
        break;
      }
      for(int i=0; i < 8; i++) {
        if (i < numPlayers) { 
          ifs >> player >> token >> TimsCup >> money >> position;
          createPlayer(i,player,token);
          if (position == 10) {
            int visit;
            ifs >> visit;
            if(visit == 1) {
              int turns;
              ifs >> turns;
              (players[i])->set(money,TimsCup,position,true,turns);
            }
            else{
              (players[i])->set(money,TimsCup,position,false,0);
            }
          }
          else{
            (players[i])->set(money,TimsCup,position,false,0);
          }

        }
        else{
          players[i] = NULL;
        }
      }
      break;
  }
  gameBoard->init(numPlayers,this); 
  makeArray();
  setPlayers();
  setPlayerNames();
  for(int i=0; i < numPlayers;i++) {
    td->movePlayer(i+1,players[i]->getCurrentPosition());
  }
  for(int i=0; i < 28;i++) {
    string building;
    string owner;
    int improvements;
    ifs >> building >> owner >> improvements;
    setBuilding(building,owner,improvements);
   // cout << building << " " <<  owner << " " << improvements << endl; //for testing
  }
  yourTurn = players[0];
  turn = 1;
  td->printBoard();
  play();
}

void Controller::save(string filename) {
  ofstream ofs(filename.c_str());
  ofs << numPlayers << endl;
  for(int i=0;i<numPlayers;i++) {
    ofs << players[i]->getName() << " " << players[i]->getToken() << " ";
    ofs << players[i]->getTimsCup() << " " << players[i]->getMoney() << " " << players[i]->getCurrentPosition();
    if(players[i]->getCurrentPosition() == 10 & players[i]->getTimsLine() == false) {
      ofs <<" 0";
    }
    if(players[i]->getCurrentPosition() == 10 & players[i]->getTimsLine() == true) {
      ofs << " 1 " << players[i]->getDCTurns();
    }
    ofs << endl;
  }
  ofs << "AL " <<  gameBoard->squares[1]->getOwner() << " " << gameBoard->squares[1]->getImprovements() << endl;
  ofs << "ML " <<  gameBoard->squares[3]->getOwner() << " " << gameBoard->squares[3]->getImprovements() << endl;
  ofs << "MKV " << gameBoard->squares[5]->getOwner() << " " << gameBoard->squares[5]->getImprovements() << endl;
  ofs << "ECH " <<  gameBoard->squares[6]->getOwner() << " " << gameBoard->squares[6]->getImprovements() << endl;
  ofs << "PAS " <<  gameBoard->squares[8]->getOwner() << " " << gameBoard->squares[8]->getImprovements() << endl;
  ofs << "HH " <<  gameBoard->squares[9]->getOwner() << " " << gameBoard->squares[9]->getImprovements() << endl;
  ofs << "RCH " << gameBoard->squares[11]->getOwner() << " " << gameBoard->squares[11]->getImprovements() << endl;
  ofs << "PAC " << gameBoard->squares[12]->getOwner() << " " << gameBoard->squares[12]->getImprovements() << endl;
  ofs << "DWE " << gameBoard->squares[13]->getOwner() << " " << gameBoard->squares[13]->getImprovements() << endl;
  ofs << "CPH " << gameBoard->squares[14]->getOwner() << " " << gameBoard->squares[14]->getImprovements() << endl;
  ofs << "UWP " << gameBoard->squares[15]->getOwner() << " " << gameBoard->squares[15]->getImprovements() << endl;
  ofs << "LHI " << gameBoard->squares[16]->getOwner() << " " << gameBoard->squares[16]->getImprovements() << endl;
  ofs << "BMH " << gameBoard->squares[18]->getOwner() << " " << gameBoard->squares[18]->getImprovements() << endl;
  ofs << "OPT " << gameBoard->squares[19]->getOwner() << " " << gameBoard->squares[19]->getImprovements() << endl;
  ofs << "EV1 " << gameBoard->squares[21]->getOwner() << " " << gameBoard->squares[21]->getImprovements() << endl;
  ofs << "EV2 " << gameBoard->squares[23]->getOwner() << " " << gameBoard->squares[23]->getImprovements() << endl;
  ofs << "EV3 " << gameBoard->squares[24]->getOwner() << " " << gameBoard->squares[24]->getImprovements() << endl;
  ofs << "V1 " << gameBoard->squares[25]->getOwner() <<  " " << gameBoard->squares[25]->getImprovements() << endl;
  ofs << "PHYS " << gameBoard->squares[26]->getOwner() << " " << gameBoard->squares[26]->getImprovements() << endl;
  ofs << "B1 " << gameBoard->squares[27]->getOwner() << " " << gameBoard->squares[27]->getImprovements() << endl;
  ofs << "CIF " << gameBoard->squares[28]->getOwner() << " " << gameBoard->squares[28]->getImprovements() << endl; 
  ofs << "B2 " << gameBoard->squares[29]->getOwner() << " " << gameBoard->squares[29]->getImprovements() << endl;
  ofs << "EIT " << gameBoard->squares[31]->getOwner() << " " << gameBoard->squares[31]->getImprovements() << endl;
  ofs << "ESC " << gameBoard->squares[32]->getOwner() << " " << gameBoard->squares[32]->getImprovements() << endl;
  ofs << "C2 " << gameBoard->squares[34]->getOwner() << " " << gameBoard->squares[34]->getImprovements() << endl;
  ofs << "REV "<< gameBoard->squares[35]->getOwner() << " " << gameBoard->squares[35]->getImprovements() << endl;
  ofs << "MC " << gameBoard->squares[37]->getOwner() << " " << gameBoard->squares[37]->getImprovements() << endl;
  ofs << "DC " << gameBoard->squares[39]->getOwner() << " " << gameBoard->squares[39]->getImprovements() << endl; 
}

void Controller::play() {
  cout << yourTurn->getName() << ", let's start the game! " << yourTurn->getToken() << endl;  
  string cmd;
  while (cin >> cmd) {
    if(cmd == "roll") {
    //TODO
    }
    else if(cmd == "next") {
      next();
      cout << yourTurn->getName() << ", it's your turn! You are player: " << turn << yourTurn->getToken() << endl;
    }
    else if(cmd == "trade") {
      gameBoard->trade();
    }
    else if(cmd == "improve") {
      gameBoard->improve();
    }
    else if(cmd == "mortgage") {
      gameBoard->mortgage();
    }
    else if(cmd == "unmortgage") {
      gameBoard->unmortgage();
    }
    else if(cmd == "bankrupt") {
      gameBoard->bankrupt();
    }
    else if(cmd == "assets") {
      gameBoard->assets();
    }
    else if(cmd == "save") {
      string filename;
      cin >> filename;
      save(filename);
      break; 
    }
    else {
      cout << "Invalid Command. Please try again." << endl;
    }   
  }
} 
