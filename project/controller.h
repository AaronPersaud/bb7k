#ifndef CONTROLLER
#define CONTROLLER

class Controller{
  protected:
    //Board *gameBoard;
    //View *td;
    //Player *players[numPlayers]
    int numPlayers;
    bool firstTime;
  public:
    void next();
    void createPlayers(int i);
    void getPlayers(int i);
    void getPlayersName(char c);
    void play();
};

#endif
