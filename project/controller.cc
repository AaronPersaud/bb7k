#include "controller.h"
#include <iostream>
#include <string>

using namespace std;

Controller::Controller() {}

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

void Controller::createPlayer(int i,string s,char c) {
  Player * p = new Player;
  p->setName(s);
  p->setToken(c);
  players[i] = p;
}

void Controller::makeArray() { //segfault error when this is called
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
  td->setNumOfPlayers();
}

void Controller::setPlayerNames() {
  td->setPlayer(symbols);
}
void Controller::play() {
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
  makeArray();
  yourTurn = players[0];
  turn = 1;
  cout << yourTurn->getName() << ", let's start the game! " << yourTurn->getToken() << endl;  
  string cmd;
  while (cin >> cmd) {
    if(cmd == "roll") {
    //TODO
    setPlayerNames(); //giving segfault error
    }
    else if(cmd == "next") {
      next();
      cout << yourTurn->getName() << ", it's your turn! " << yourTurn->getToken() << endl;
    }
    else if(cmd == "trade") {
      yourTurn->trade();
    }
    else if(cmd == "improve") {
      yourTurn->improve();
    }
    else if(cmd == "mortgage") {
      yourTurn->mortgage();
    }
    else if(cmd == "unmortgage") {
      yourTurn->unmortgage();
    }
    else if(cmd == "bankrupt") {
      yourTurn->bankrupt();
    }
    else if(cmd == "assets") {
      yourTurn->assets();
    }
    else if(cmd == "save") {
    //TODO
    }
    else {
      cout << "Invalid Command. Please try again." << endl;
    }   
  }
} 
