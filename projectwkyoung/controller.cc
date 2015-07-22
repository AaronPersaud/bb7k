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
  yourTurn = players[0];
  turn = 1;
  td->printBoard();
  play();
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
    //TODO
    }
    else {
      cout << "Invalid Command. Please try again." << endl;
    }   
  }
} 
