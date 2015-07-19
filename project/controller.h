#include "player.h"
#include "view.h"
#ifndef CONTROLLER
#define CONTROLLER

class Controller{
  protected:
    //Board *gameBoard;
    View *td;
    int numPlayers;
    Player *players[8];
    char *symbols;
    bool firstTime;
    Player *yourTurn;
    int turn;
  public:
    void makeArray();
    void next();
    void createPlayer(int i,std::string s,char c);
    void play(); //TODO not finished yet
    void setPlayers();
    void setPlayerNames();
    Controller();
};

#endif
