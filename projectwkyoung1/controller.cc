#include "controller.h"
#include <iostream>
#include <string>

using namespace std;

Controller::Controller(){
  td = NULL;
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
      //cout << symbols[i] << " " << players[i]->getToken() << endl; testing purposes
}
  }
}

void Controller::setPlayers() {
  td->setNumOfPlayers(numPlayers);
}

void Controller::setPlayerNames() {
  td->setPlayer(symbols);
}
void Controller::play() {
  this->td = new TextDisplay;
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
  setPlayers();
  setPlayerNames();
  yourTurn = players[0];
  turn = 1;
  td->startGame();
  cout << yourTurn->getName() << ", let's start the game! " << yourTurn->getToken() << endl;  
  string cmd;
  while (cin >> cmd) {
    if(cmd == "roll") {
    //TODO
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
