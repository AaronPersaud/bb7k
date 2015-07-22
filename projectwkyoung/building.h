#ifndef BUILDING
#define BUILDING
#include "controller.h"
#include "square.h"
#include "player.h"
#include <string>

class Building: public Square{
  protected:
  std::string buildingName;
  std::string block;
  int location;
  int cost;
  int tuition;
  int tuition0;
  int tuition1;
  int tuition2;
  int tuition3;
  int tuition4;
  int tuition5;
  int numImprovements;
  bool owned;
  Controller *theController;
  Player *owner;
  bool mortgaged;
  char *players;
  bool monopolied;
  int costOfImprovement;
  public:
  //Building();
  void notify(std::string buildingName,int improvement);
  void improve();
  void unimprove();
  void changeOwner(Player *newOwner);
  void changeMortgage();
  virtual int getTuition();
  void setEverything(std::string bN,std::string bl,int loc,int c,int t,int t0,int t1,int t2,int t3,int t4,int t5,int nI,bool isitowned,bool mor,char *pl,bool mon,       int cOI);
  void setMonopolied();
  void set(Player* player, int improves);
  std::string getOwner() {} //TODO
  std::string getBlock() {} //TODO
};

#endif
