#ifndef PLAYER
#define PLAYER
#include <string>

class Player{
  protected:
  int money;
  char token;
  bool properties[40];
  bool mortgaged[40];
  int RolluptheRimCup;
  std::string name;
  int position;
  bool DCTimsLine;
  int DCTurns;
  public:
  Player();
  void setToken(char c);
  void setName(std::string s);
  char getToken(); //for testing purposes
  std::string getName(); // for testing purposes
  int getTuition(int i);
  void setMoney(int i);
  int getMoney();
  int getTimsCup();
  bool getTimsLine();
  int getDCTurns();
  void setCurrentPosition(int i);
  void setPrevPosition(int i);
  int getCurrentPosition();
  void set(int m,int R,int p,bool D,int DC);
};

#endif
