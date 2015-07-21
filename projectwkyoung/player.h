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
  public:
  void setToken(char c);
  void setName(std::string s);
  char getToken(); //for testing purposes
  std::string getName(); // for testing purposes
  int getTuition(int i);
  void setMoney(int i);
  void setCurrentPosition(int i);
  void setPrevPosition(int i);
  int getCurrentPosition();
};

#endif
