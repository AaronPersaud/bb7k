#ifndef RESIDENCE
#define RESIDENCE
#include "square.h"
#include "player.h"
#include <string>

class Residence: public Square{
  int getTuition();
  int improvement;
  std::string buildingName;
  Player *owner;
  Player *owners[4];
  public:
  std::string getOwner();
//  std::string getBlock() {} //TODO
  void set(Player* player, int improves);
  int getImprovements(); 
  std::string getBuildingName();
};

#endif
