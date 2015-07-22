#include "player.h"
#include "view.h"
#include "textdisplay.h"
#include "board.h"
#include <string>
#include <fstream>
#ifndef CONTROLLER
#define CONTROLLER

class Board;
class View;

class Controller{
  protected:
    Board *gameBoard;
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
    void notify(int improvement, int location);
    void createPlayer(int i,std::string s,char c);
    void play(); //TODO not finished yet
    void setPlayers();
    void setPlayerNames();
    Controller();
    ~Controller();
    void noParameter();
    void load(std::string file);
};

#endif
