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
  Building();
  void notify(std::string buildingName,int improvement);
  void improve();
  void unimprove();
  void changeOwner(Player *newOwner);
  void changeMortgage();
  virtual int getTuition();
};

#endif
